// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/* Created by Ranma@Koko Wa 951001 */

/* This command will add a new path to your current exec path */

#include <mudlib.h>

inherit CMD;

private void main(string * arg) 
{
    string userid = this_user()->query_userid();
    string * paths;
    string item;
    object shell_ob = this_body()->query_shell_ob();

    if ( get_privilege(this_user()) && !check_privilege(userid) )
    {
        out(//"Permission denied.\n"
            "权限不足。\n");
        return;
    }

    paths = shell_ob->query_path();
    foreach ( item in paths )
    {
        if ( item == arg[0] )
        {
            out(//"You have had the path added already\n"
                "这个目录你早就加上了。\n");
            return;
        }
    }

    paths += ({ arg[0] + "/" });
    shell_ob->set_variable("path", paths);

    out(iwrap(implode(paths,
                        (: $1 + $2[0..<2] + ", " :),
                        //"Your path is now: "
                        "当前目录：")[0..<3]) + "\n");
}
