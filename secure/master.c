// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** master.c -- the MudOS Master object
*/

#include <config.h>
#include <daemons.h>
#include <mudlib.h>
#include <security.h>
#include <log.h>
#include <driver/parser_error.h>

private mapping errors = ([]);

void create()
{
    debug_message(ctime() + " loaded " __FILE__);
}

string domain_file(string file)
{
    return "BACKBONE";
}

string author_file (string file)
{
    return "NONAME";
}

object compile_object(string path)
{
    string pname;
    object ob;

    /* LPscript support */
    if (path[<4..] == ".scr")
        return LPSCRIPT_D->compile(path);

    pname = path;

    /* go back through the path, checking each dir; if the name is
       "/foo/bar/baz.c" then "/foo/bar.c" and "/foo.c" are checked. */
    while (1) {
        int idx = strsrch(pname, "/", -1);

        if (idx == -1)
            return 0;

        pname = pname[0..idx-1];

        if (file_size(pname + ".c") >= 0) {
            if (ob = pname->virtual_create(path[idx+1..]))
                return ob;
        }
    }
}

private void crash()
{
    tell(users(), //"Game Driver shouts: Ack! I think the game is crashing!\n"
                  "霎时地动山摇，天翻地覆，整个世界毁于一旦！\n");
    users()->quit();
}

nomask string get_player_fname()
{
    string err;
    object ob;

    if ( err = catch(ob = load_object(USER_OB)) || !ob )
    {
        if ( !ob )
            err = "File '" + USER_OB + "' does not exist!";
        write("Main login ob not loadable!\n" + err + "\n");
        if ( err = catch(ob = load_object(USER_OB_BAK)) )
            write("Spare login obj not loadable!\n" + err + "\n");
        else if ( !ob )
            write("Spare login ob (" + USER_OB_BAK + ") does not exist!\n");
        else
            return USER_OB_BAK;
    }
    else
        return USER_OB;

    return 0;
}

#ifdef  DEBUG_CONNECTIONS
void debug_connections(object ob)
{
    debug_message(sprintf("Debugger tells you: There's a new connection from %s.\n", query_ip_name(ob)));
}
#endif

object connect()
{
    object ob;
    string ret;

    ret = catch(ob = new(get_player_fname()));

#ifdef DEBUG_CONNECTIONS
    call_out((: debug_connections($(ob)):), 2);
#endif

    write("\n");
    if ( ret )
    {
        write(ret + "\n");
        return 0;
    }
    return ob;
}

int different(string fn, string pr) {
    sscanf(fn, "%s#%*d", fn);
    fn += ".c";
    return (fn != pr) && (fn != ("/" + pr));
}

string trace_line(object obj, string prog, string file, int line) {
    string ret;
    string objfn = obj ? file_name(obj) : "<none>";

    ret = objfn;
    if (different(objfn, prog)) ret += sprintf(" (%s)", prog);
    if (file != prog) ret += sprintf(" at %s:%d\n", file, line);
    else ret += sprintf(" at line %d\n", line);
    return ret;
}

varargs string standard_trace(mapping mp, int flag) {
    string ret;
    mapping *trace;
    int i,n;

    ret = ctime( time());
    ret += "\n";
    ret += mp["error"] + "Object: " + trace_line(mp["object"], mp["program"],
      mp["file"], mp["line"]);
    ret += "\n";
    trace = mp["trace"];

    n = sizeof(trace);

    for (i=0; i<n; i++) {
        if (flag) ret += sprintf("#%d: ", i);

        ret += sprintf("'%s' at %s", trace[i]["function"],
          trace_line(trace[i]["object"], trace[i]["program"],
            trace[i]["file"], trace[i]["line"]));
    }
    return ret;
}

/* ***WARNING***:
 * We do NOT runtime errors in here, so program defensively.  I've already
 * had to fix a few cases where people assumed this_user() couldn't be zero,
 * etc.  BE CAREFUL.
 *
 * -Beek
 */
// The mudlib runtime error handler.
void error_handler(mapping error, int caught)
{
    string trace = standard_trace(error, caught);

    // catch(error(x))
    if (caught)
    {
        efun::write_file("log/catch_error", trace);
        return;
    }

    trace += "[" + ctime() + "]";
    trace += sprintf("\n%O\n", error);
    // whatever we return goes to the debug.log
    efun::write_file("log/error_handler", trace);
}

mapping query_error(string name)
{
    /* This MUST be secure */
    if (!check_privilege(1)) return 0;
    return errors[name];
}

string ws = " \t\n";

/* don't use the string module, it's dangerous to do that here :) */
string trim_spaces(string str)
{
    int i=0,j=strlen(str)-1;
    while (i<=j && member_array(str[i], " \t\n") != -1) i++;
    while (i<=j && member_array(str[j], " \t\n") != -1) j--;
    return str[i..j];
}

mixed name_of_file_owner(string object_name)
{
    string wiz_name;
    string start, trailer;

    if ( sscanf(object_name, WIZ_DIR"/%s", wiz_name) == 1 )
    {
        if ( sscanf(wiz_name, "%s/%s", start, trailer) == 2 )
            wiz_name = start;
        return wiz_name;
    }
    else if (object_name[0..3] != "ftp/" && object_name[0..4] != "open/")
    {
        /* no creator, but legal. */
        return 1;
    }
}

// Handle tabs and non-printables; unfortunately UNIX tabs are indent
// sensitive; this means that strlen(str) depends where we are on the line ...
private int funky_strlen(string str, int start) {
    int l, n, pos = start;
    l = n = strlen(str);
    for (int i = 0; i < n; i++) {
        if (str[i] == '\t') {
            int z = 8 - (pos % 8);
            l += z;
            pos += z;
        }
        if (str[i] < 32 || str[i] > 126) {
            l--;
            continue;
        }
        pos++;
    }
    return l;
}

#define WIDTH 75
#define INDENT "## "

private void report_context(string src, int line, string context) {
    string txt;
    int len, clen;
    int pos = strlen(INDENT);
    int tmp;

    if (!context || context == "") return;
    if (context[<1] == '\n') context = context[0..<2];

    src = read_file((src[0] == '/' ? src : "/" + src), line, 1);
    if (src == "") return;
    if (src[<1] != '\n')
        src += "\n";
    // HACK WARNING:
    // If there are nonprintables, we might not slash off enough, hence
    // the while.  If there are tabs, we might slice off too much.
    txt = src;
    while ((len = funky_strlen(txt, pos)) > WIDTH)
        txt = txt[0..<len-(WIDTH - 5)] + "...\n";
    // END HACK.  RESUME NORMAL DRIVING
    write(INDENT + txt);
    if (context == "the end of line")
        context = "\n";

    context = replace_string(context, "%", "%%");
    if (sscanf(src, "%s" + context + "%s", txt, src) != 2)
        return;
    len = funky_strlen(txt, pos);
    pos += len;

    if (pos <= WIDTH) {
        printf(INDENT "%-*' 's", len, "");
        clen = funky_strlen(context, pos);
        pos += clen;
        printf("^%-*' 's", clen - 1, "");
        while ((tmp = strsrch(src, context)) != -1) {
            txt = src[0..tmp-1];
            src = src[tmp + strlen(context)..];

            len = funky_strlen(txt, pos);
            pos += len;
            clen = funky_strlen(context, pos);
            pos += clen;
            if (pos > WIDTH) {
                if (pos - len - clen + 1 <= WIDTH)
                    write("^");
                break;
            }
            printf("%-*' 's^%-*' 's", len, "", clen - 1, "");
        }
    }
    write("\n");
}

void log_error(string file, string message)
{
    if (strsrch(message, "Warning") == -1)
    {
        // 记录错误日志
        efun::write_file("log/log_error", message);
    }
    else
    {
        // 记录警告日志
        efun::write_file("log/log", message);
    }
}

private int save_ed_setup(object who, int code) {
    who->set_ed_setup(code);
    return 1;
}

private int retrieve_ed_setup(object who) {
    return who->query_ed_setup();
}

int valid_shadow(object ob)
{
    return (int)ob->query_allow_shadow(previous_object());
}

/*
 * Default language functions used by parse_command()
 */
string *parse_command_id_list()
{
    return ({ "one", "thing" });
}

string *parse_command_plural_id_list()
{
    return ({});
}

string *parse_command_adjectiv_id_list()
{
    return ({});
}

string *parse_command_prepos_list()
{
    return ({ "in","from","on","under","behind","beside","of","for","to",
      "with", "at", "off", "out", "down", "up", "around", "over",
      "into", "about", });
}

string parse_command_all_word()
{
    return "all";
}

void refresh_parse_info() {
     parse_refresh();
}

object *parse_command_users()
{
    return users()->query_body();
}

string parser_error_message(int kind, object ob, mixed arg, int flag) {
    string ret;
    if (ob)
        ret = ob->short() + ": ";
    else
        ret = "";

    switch (kind) {
    case ERR_IS_NOT:
            return ret + "这里没有" + arg + "。\n";
        break;
    case ERR_NOT_LIVING:
        if (flag)
            return ret + "没有" + arg + "是活着的。\n";
        else
            return ret + arg + "不象是有生命的东西。\n";
        break;
    case ERR_NOT_ACCESSIBLE:
        if (flag)
            return ret + "你拿不到它们。\n";
        else
            return ret + "你拿不到它。\n";
        break;
    case ERR_AMBIG:
        {
            array descs = unique_array(arg, (: $1->short() :));
            string str;

            if (sizeof(descs) == 1)
                return ret + "你指的是哪一个" + descs[0][0]->short() + " ？\n";
            str = ret + "你指的是";
            for (int i = 0; i < sizeof(descs); i++) {
                str += descs[i][0]-> short();
                if (i < sizeof(descs) - 2)
                    str += "，";
                else if (i == sizeof(descs) - 2)
                    str += "或";
            }
            return str + "中的哪一个？";
        }
        break;
    case ERR_ORDINAL:
        if (arg > 1)
            return ret + "这里只有" + chinese_number(arg) + "个。\n";
        else
            return ret + "这里只有一个。\n";
        break;
    case ERR_ALLOCATED:
        return ret + arg;
    case ERR_THERE_IS_NO:
        return ret + "这里没有" + arg + "。\n";
    case ERR_BAD_MULTIPLE:
        return ret + "对于这个动词，你不能使用多于一个物体。\n";
    }
}

string get_save_file_name(string file, object who)
{
    file = "/" + file + "%";
    rm( file );
    return file;
}

string make_path_absolute(string path)
{
    return evaluate_path(path);
}

int valid_override(string file, string efun_name)
{
    if(file[0] != '/') return 0;

    switch (efun_name) {
    case "pluralize":
        // M_GRAMMAR overrides this
        return 1;
    case "input_to":
    case "get_char":
        return file == "/secure/user/inputsys";
    }
    /*
    ** The simul efun ob can use efun:: all it wants.  Other objects are
    ** completely restricted.
    */
    return file == "/secure/simul_efun/overrides";
}

int valid_socket(object ob, string what, mixed * info)
{
    string fname;

    sscanf(file_name(ob), "%s#%*s", fname);
    return fname == SOCKET;
}


void remove()
{
    destruct();
}

private nomask void preload( string file )
{
    object o;

        //write("Preloading: "+file+"...  ");
        catch(o = load_object(file));
        //if ( objectp(o) )
        //   write("success\n");
        //else
        //   write("FAILED\n");
}

string* epilog( int eflag )
{
    return filter_array(explode(read_file(PRELOAD_FILE), "\n") - ({ "" }),
      (: $1[0] != '#' :));
}

string object_name( object ob )
{
    if ( !ob )
        return "<destructed>";

    if ( interactive(ob) )
        return ob->query_userid() + "'s link";

    if ( ob->is_living() )
        if(ob = ob->query_link()) return ob->query_userid()+"'s body";
        else
            return 0;
}



#if 0
mixed valid_write(string path, string eff_user, string call_fun, object caller)
{
    return 1;
}

mixed valid_read(string path, string eff_user, string call_fun, object caller)
{
    return 1;
}
#else
#pragma strict_types

mixed valid_write(mixed path, object caller, string call_fun)
{
    if (caller == this_object())
        return 1;
    path = canonical_path(path);

    if (SECURE_D->check_privilege(SECURE_D->query_protection(path,1),1))
        return path;

    write_file(ACCESS_LOG,
      (this_user() ? this_user()->query_userid() : file_name(caller)) +
      ": attempted to write " + path + "\n");

    printf("Permission denied: %s.\n",path);
    return 0;
}

mixed valid_read(string path, object caller, string call_fun)
{
    if (caller == this_object())
        return 1;
    if (file_name(caller)==SECURE_D && call_fun == "restore_object")
        return 1;

    path = canonical_path(path);
    if (SECURE_D->check_privilege(SECURE_D->query_protection(path,0),0))
        return path;

    write_file(ACCESS_LOG,
      (this_user() ? this_user()->query_userid() : file_name(caller)) +
      ": attempted to read " + path + "\n");

    printf("Permission denied: %s.\n",path);
    return 0;
}

#endif

int valid_bind(object binder, object old_owner, object new_owner)
{
    return check_privilege(get_protection(base_name(new_owner), "wf"));
}

int valid_save_binary()
{
    return 1;
}
