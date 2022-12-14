// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <driver/origin.h>
#include <security.h>

inherit M_ACCESS;
inherit M_INPUT;
inherit M_HISTORY;
inherit M_ALIAS;
inherit M_SHELLFUNCS;
inherit M_SAVE;
inherit M_SCROLLBACK;

private static object owner;

varargs void execute_command();
string query_shellname();
string query_save_path(string userid);

static function arg_to_words_func = (: explode($1," ") :);

//### goofy fucking hack cuz the shell doesn't save for shit. only M_SAVE,
//### even though in the alias code it professes to "not require it to be
//### bound to M_SAVE" ... this is bunk...
private string save_info;

void setup_for_save()
{
    /*
    ** This object has no variables to save, but many of the moduless do,
    ** so we must dispatch to them.
    */
    alias::setup_for_save();
    shellfuncs::setup_for_save();
}

void save_me()
{
    if ( !owner )   /* probably the blueprint */
    return;

    setup_for_save();
    save_info = save_to_string();
    unguarded(1, (: save_object, query_save_path(owner->query_userid()) :));
}
static void restore_me(string userid)
{
    unguarded(1, (: restore_object, query_save_path(userid) :));
    if ( save_info )
    {
    load_from_string(save_info, 0);
    save_info = 0;
    }
}

void remove()
{
    if ( origin() != ORIGIN_LOCAL && owner && previous_object() != owner )
    //error("illegal attempt to remove shell object\n");
    error("企图非法删除命令行物件\n");
    save_me();
    destruct();
}

static void shell_input(mixed input)
{
    mixed argv;
    string original_input;

    if(input == "") return;
    if(input == -1)
    {
    remove();
    return;
    }

    /*
    ** ### WORK IN PROGRESS HERE
    **
    ** Defined from the BASH shell
    **
    ** Evaluation order:
    ** - history expansion
    ** - store in history
    ** - alias expansion
    ** - shell-defined expansion
    **   - TENTATIVELY: wish does: left-to-right: brace, tilde, parameter,
    **     variable, command, arithmetic, then word splitting, then
    **     pathname expansion
    ** - execution
    **
    ** If the command uses parsed arguments (argv syntax), then the only
    ** expansion that can change the number of arguments are: brace
    ** expansion, word splitting, and pathname expansion.  An exception
    ** is the expansion of $@.
    */

    // is this history manipulation?
    if(input[0] == HISTORY_CHAR)
    {
    input = history_command(input);
    if(!input) return;
    }

    add_history_item(input);

    argv = explode(input, " ");

    // alias expansion... a leading \ ignores alias expansion
    if(sizeof(argv) && (strlen(argv[0]) > 1) && (argv[0][0] == '\\'))
    {
    argv[0] = argv[0][1..];
    }
    else
    {
    mixed tmp = expand_alias(argv);

    argv = stringp(tmp) ? explode(tmp," ") : tmp;

    }

    if (!argv || !sizeof(argv)) return;
    
    original_input = implode(argv," ");

    if (!sizeof(argv))
    return;

    execute_command(argv, original_input);
}

private void cmd_exit()
{
    if(modal_stack_size() == 1)
    {
//### I think we could just issue the quit command rather than force it
    this_user()->force_me("quit");
    return;
    }
    printf(//"Exiting %s\n",
           "退出 %s\n",
            query_shellname());
    modal_pop();
    remove();
}

protected void create()
{
    if ( !clonep() )
    return;

    owner = previous_object();
    if ( owner != this_user() )
    {
    destruct();
    //error("illegal shell object creation\n");
    error( sprintf("命令行文件建立失败 previous_obj=%O this_usr=%O\n",
    	owner,this_user()));
    }

    if ( owner )
    restore_me(owner->query_userid());

    alias::create();
    history::create();
}

/*
** This function is used internally to prepare a shell for operation.
** Subclasses will typically override to set up bindings and variables
** with shell_bind_if_undefined() or set_if_undefined(), respectively.
*/
static void prepare_shell()
{
    shell_bind_if_undefined("alias",    (: cmd_alias :));
    shell_bind_if_undefined("unalias",  (: cmd_remove_alias($1,1) :));
    shell_bind_if_undefined("history",  (: cmd_history :));
    shell_bind_if_undefined("scrollback", (: cmd_scrollback :));
//    shell_bind_if_undefined("exit",   (: cmd_exit :));
}

static mixed what_prompt()
{
    return "> ";
}

void start_shell()
{
    if ( owner != this_user() || previous_object() != owner )
    //error("illegal attempt to take over shell\n");
    error("企图非法超越命令行\n");
    modal_push((: shell_input :), what_prompt());

    prepare_shell();
}


nomask object query_owner()
{
    return owner;
}
