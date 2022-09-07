// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** aliasmenu.c -- alias manipulation menu
**
** 950807, Deathblade: Created from Rust's alias.c module.
*/

#include <mudlib.h>
#include <classes.h>

inherit M_INPUT;

inherit CLASS_ALIAS;

private static object shell_ob; /* which shell ob we're editing aliases for */
private static string * display_menu_options;
private static class alias new_alias_in_progress;
private static string new_alias_name;
private static int num_defaults;
private static int default_index;


/*
**  From here on lies a menu interface to aliases.
**  It's probably a bit messy. =/
**  (Written in a hurry, unfortunatly.)
*/

void input_from_main_menu(string);
string main_menu_prompt();
void display_main_menu();
static void init_alias_editor();

nomask void begin_menu(object for_shell_ob)
{
    shell_ob = for_shell_ob;
    modal_push((: input_from_main_menu :), (: main_menu_prompt :));
    display_main_menu();
}

private void goto_main_menu()
{
    display_main_menu();
    modal_func((: input_from_main_menu :), (: main_menu_prompt :));
}

private void quit_alias_editor()
{
//    write("Exiting alias editor.\n");
    write("�˳� alias �༭����\n");
    modal_pop();
    destruct(this_object());
}

private void display_main_menu()
{
/*
    write("Alias Editor\n\n"
          "l - list all aliases\n"
          "s - show one alias\n"
          "a - add or adjust an alias\n"
          "r - remove an alias\n"
          "\n"
          "q - quit\n");
*/
    write("Alias �༭��\n\n"
          "   l         - �г����е� aliases\n"
          "   s         - ��ʾһ�� alias\n"
          "   a         - ���ӻ��޸�һ�� alias\n"
          "   r         - ɾ��һ�� alias\n"
          "\n"
          "   q         - �˳�\n");
}

private string main_menu_prompt()
{
    return "[lsarq] ";
}

varargs nomask void display_one_alias(string alias_name, object shell_to_use)
{
    class alias this_alias;
    string output = "";
    int i;

    if ( !shell_to_use )
        shell_to_use = shell_ob;

    this_alias = shell_to_use->query_one_alias(alias_name);
    if(!this_alias)
    {
        printf(//"You have no alias for %s.\n"
               "�㲢δ�趨 %s ������ alias��\n" , alias_name);
        return;
    }

    output += sprintf("Alias: %-15s չ��: %s\n",
                      alias_name, this_alias->template);

    if(sizeof(this_alias->defaults) > 1 || this_alias->defaults[0] != "")
    {
        output += sprintf("\tԤ��ֵ:\n"
                          "  $*: %s\n", this_alias->defaults[0]);
        if(sizeof(this_alias->defaults) > 1)
            for(i=1;i<sizeof(this_alias->defaults);i++)
                output +=sprintf("  $%d: %s\n", i, this_alias->defaults[i]);
    }

    if ( shell_to_use->is_xalias(alias_name) )
        output += //"You don't have to type a space after you type this alias.\n\n";
                  "�㲻���������� alias ֮���ټ���ո�\n\n";
    write(output);
}


private void display_all_aliases()
{
    string * names;
    string a;
    class alias val;
    string output;
    int i;

    output = sprintf("Alias:%9sչ��:%29sԤ��:\n","","");
    output += sprintf("%77'-'s\n", "");

    names = sort_array(shell_ob->query_alias_names(), 1);
    foreach ( a in names )
    {
        val = shell_ob->query_one_alias(a);

        output += sprintf("%-14s %-38s ", a, val->template);
        if(sizeof(val->defaults) == 1 && val->defaults[0] == "")
            output += "\n";
        else
        {
            output += "$*: " + val->defaults[0] + "\n";
            for(i=1;i<sizeof(val->defaults);i++)
                output += sprintf("%54s$%d: %s\n","",i,val->defaults[i]);
        }
    }

    more(output);
}


private void process_display_alias_menu_choice(string input)
{
    int index;

    if(input=="q")
    {
        quit_alias_editor();
        return;
    }
    if(!sscanf(input,"%d",index) || index < 1 || 
       index > sizeof(display_menu_options))
    {
        //write("Invalid selection.\n");
        write("�Ƿ�ѡ�\n");
        return;
    }
    display_one_alias(display_menu_options[index-1]);
    display_menu_options = 0;
    goto_main_menu();
}

private void display_alias_menu()
{
    int i;

    display_menu_options = sort_array(shell_ob->query_alias_names(), 1);
    //write("Select alias to display:\n");
    write("��ѡ����Ҫ��ʾ�� alias��\n");
    for(i=0; i<sizeof(display_menu_options); i++)
    {
        printf("%-4d%-6s  ", i+1, display_menu_options[i]);
        if(i%5==4)
            write("\n");
    }
    write("\n");
    modal_func((:process_display_alias_menu_choice:), "[#q] ");
}

private void display_alias(string s)
{
    string* matches;
    int i;

    matches = M_COMPLETE->complete(s, shell_ob->query_alias_names());

    switch(sizeof(matches))
    {
    case 0:
        //write("No such alias.\n");
        write("�޴� alias��\n");
        goto_main_menu();
        return;

    case 1:
        display_one_alias(matches[0]);
        goto_main_menu();
        return;

    default:
        //write("Possible completions are:\n");
        write("���ϵ��У�\n");
        matches = sort_array(matches,1);
        for(i = 0; i<sizeof(matches); i++)
            printf("  %-4d%s\n",i,matches[i]);
        display_menu_options = matches;   
        modal_func((:process_display_alias_menu_choice:),
                   //"Select one by number, or q to quit: "
                   "������ѡ�񣬻� q �˳���");
        return;
    }
}

private string get_arg_default_prompt()
{
    return sprintf(//"What's the default for $%d (enter for none)? ", 
                   "$%d ��Ԥ��ֵ��ʲô��(�س�������)",
                   default_index + 1);
}

private void get_xverb_status(string s)
{
    if(s == "")
        return;

    switch(s[0])
    {
    case '?':
        /*
        write(
            "Do you want to be able to omit the space between the alias and the "
            "rest of\nwhat you type?  Ie, if your alias is for ', do you want "
            "to be able to do:\n'foo\nor do you want to be forced to put a space "
            "between the ' and the foo??\n");
        */
        write(
            "��ϣ��ʡȥ alias �����²���֮��Ŀո���\n"
            "���磺'foo\n"
            "��Ҫ�� ' �� foo ֮���Զ�ʡȥ�ո���(y/n)\n");
           
        return;
    case 'y':
        shell_ob->add_xalias(new_alias_name);
        break;
    case 'n':
        break;
    default:
        //write("Invalid response.\n");
        write("�Ƿ��ش�\n");
        return;
    }
    shell_ob->add_alias_simple(new_alias_name, new_alias_in_progress);

    printf(//"Alias %s defined.\n",
           "Alias %s �����ˡ�\n", new_alias_name);
    goto_main_menu();
}
  

private void ask_for_xverb_status()
{
    modal_func((: get_xverb_status :), //"Allow space ommision? [yn?] "
                                       "����ʡȥ�ո���[yn?]" );
}

private void set_arg_default(string s)
{
    default_index++;
    new_alias_in_progress->defaults[default_index] = s;
    if(default_index == num_defaults)
    {
        ask_for_xverb_status();
    }
}

private void set_star_default(string s)
{
    new_alias_in_progress->defaults[0] = s;
    default_index = 0;
    num_defaults  = new_alias_in_progress->num_args;
    if(!num_defaults)
    {
        ask_for_xverb_status();
        return;
    }

    modal_func((: set_arg_default :), (: get_arg_default_prompt :));
}


private void new_template(string s)
{
    if(s == "")
        return;

    if(s == "?")
    {/*
        write(
            "An alias definition can change each time you use the alias:\n"
            "$1  -- Wherever you put this in your alias definition,\n"
            "       the $1 will be replaced with the first word after\n"
            "       the alias when you use the alias.\n"
            "       You can do the same with $2, $3, $4, ad infinitum.\n"
            "       If you have $1 in your alias definition, but don't\n"
            "       provide a first argument when you use an alias,\n"
            "       the default value for $1 is used.  You can set the\n"
            "       default value when you are done with the alias definition.\n\n"
            "       Example:  If you alias \"you're\" to:\n"
            "                  say Hey, $2, you're $1!\n"
            "       When you type:\n"
            "                  you're studly Rust\n"
            "       You'll say: \"Hey, Rust, you're studly!\"\n"
            "\n"           
            "$*  -- It's the same as $1, but it means 'everything else'. \n"
            "       Example:  If you alias \"you're\" to:\n"
            "                  say $2, you're $1!  Do you $*?\n"
            "       When you type:\n"
            "                 you're studly Rust excersise much\n"
            "   You'll say: \"Hey, Rust, you're studly!  Do you excersise much?\"\n"
            "\n"
            "Notice $* matches any number of words, whereas $1, $2, etc...\n"
            "only match one word.\n\n"
            "If you don't put a $* in your expansion, one will be automatically\n"
            "added to the end of the alias for you.\n");
      */
        write(
            "һ�� alias ������ÿ����չʱ������ͬ����չ�����\n"
            "$1  -- ������ alias ������ʹ����ʱ��$1 �ᱻ������� alias ���\n"
            "       ��һ������ȡ����ͬ����� $2 $3 $4 �ȡ�\n"
            "       �����û����ʹ����� alias ʱ������һ����������ô����Ԥ\n"
            "       ��ֵ�ͻᱻ���á�\n"
            "       ��������趨 alias ��Ҳ�趨 $1 �ȵ�Ԥ��ֵ��\n\n"
            "       ���磺������ you're �趨Ϊ��\n"
            "             say Hey, $2, you're $1!\n"
            "       ֮�󣬵������룺\n"
            "             your're studly Rust\n"
            "       ��ͻ�˵����Hey, Rust, you're studly!\n\n"
            "$*  -- ���� $1 ���ƣ�������ʣ������в�����\n"
            "       ���磺������ you're �趨Ϊ��\n"
            "             say $2, you're $1! Do you $*?\n"
            "       ֮�󣬵������룺\n"
            "             you're studly Rost excercise much\n"
            "       ��ͻ�˵����Hey, Rust, your're studly! Do you exercise much?\n\n"
            
            "��ע�� $* �����κ���Ŀ�Ĵʻ㣬�� $1 $2 ��ֻ�ܴ���һ���ʡ�\n"
            "�����û������� alias ��չ��ʹ�� $*�����ᱻ�Զ����������չ֮��\n");
        return;
    }

    if(strsrch(s,"$*") == -1)
        s = s + " $*";

    new_alias_in_progress->template = s;

    new_alias_in_progress->num_args =
        max(map(explode(s[strsrch(s,"$")..],"$"), 
                function(string s){
            int d;
            sscanf(s, "%d%s",d,s);
            return d;}));

    new_alias_in_progress->defaults = 
        allocate(new_alias_in_progress->num_args+1);

    modal_func((: set_star_default :), 
               //"What's the default for $* (enter for none)? "
               "������ $* ��Ԥ��ֵ��(�س���ʾû��)");
}


private void rcv_new_alias_name(string s)
{
    if(strsrch(s," ") != -1)
    {
        write(//"Aliases may not have spaces.  Try again.\n"
              "��Ϊһ�� alias �����֣��������пո����������롣\n");
        return;
    }
    if(s=="")
        return;
  
    new_alias_in_progress = new(class alias);
    new_alias_name = s;
    //write("Type in the expansion for this alias.\n");
    write("��������� alias ����չ�����\n");
    modal_func((: new_template :), //"Expansion (? for help): "
                                   "��չ��(? �ɻ�ȡ����)");
}

  
private void cmd_adjust_alias(string s)
{
    if(strsrch(s," ") != -1)
    {
        write(//"Aliases may not have spaces.  Try again.\n");
              "��Ϊһ�� alias �����֣��������пո����������롣\n");
        modal_func((: rcv_new_alias_name :), //"Name of alias: "
                                             "Alias �����֣�");
        return;
    }
    if(s=="")
    {
        modal_func((: rcv_new_alias_name :), //"Name of alias: "
                                             "Alias �����֣�");
        return;
    }
    rcv_new_alias_name(s);
}

private varargs void process_remove_alias(mixed s, int not_using_menu)
{
    if ( !shell_ob->query_one_alias(s) )
    {
        printf(//"You don't have '%s' as an alias.\n"
               "�㲢δ�趨 %s ������ alias��\n" ,s);
    }
    else
    {
        shell_ob->remove_alias(s);
        printf(//"Alias '%s' removed.\n"
               "Alias %s ��ɾ���ˡ�\n", s);
    }

    goto_main_menu();
}

private void input_from_main_menu(string arg)
{
    int cmd;

    if(arg == "")
{
  quit_alias_editor();
  return;
}
    if(strlen(arg) == 1)
    {
        cmd = arg[0];
        arg = 0;
    }
    else
    {
        if(arg[1] != ' ')
        {
            //write("Invalid command.\n");
            write("�Ƿ����\n");
            display_main_menu();
            return;
        }
        if(strlen(trim_spaces(arg)) > 1)
            arg = arg[2..];
        else
            arg = 0;
    }
    switch(cmd)
    {
    case 'q':
        quit_alias_editor();
        return;
    case 'l':
        if( !shell_ob->query_alias_count() )
        {
            //write("You currently have no aliases defined.\n");
            write("������û���κ� alias��\n");
            goto_main_menu();
            return;
        }
        display_all_aliases();
        return;
    case 's':
        if( !shell_ob->query_alias_count() )
        {
            //write("You currently have no aliases defined.\n");
            write("������û���κ� alias��\n");
            goto_main_menu();
            return;
        }
        if(!arg)
            display_alias_menu();
        else
            display_alias(arg);
        return;
    case 'a':
        if(!arg)
            modal_func((: cmd_adjust_alias :), //"Alias name? "
                                               "Alias �����֣�" );
        else
            cmd_adjust_alias(arg);
        return;
    case 'r':
        if( !shell_ob->query_alias_count() )
        {
            //write("You currently have no aliases defined.\n");
            write("������û���κ� alias��\n");
            goto_main_menu();
            return;
        }
        if(!arg)
            modal_func((: process_remove_alias :), //"Alias name? "
                                                   "Alias �����֣�");
        else
            process_remove_alias(arg);
        return;
    default:
        //write("Invalid command.\n");
        write("�Ƿ����\n");
        return;
    }
}
