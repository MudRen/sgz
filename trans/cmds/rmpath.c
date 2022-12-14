// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/* Created by Ranma@Koko Wa 951001 */

/* This command will remove a path from your current exec path */

#include <mudlib.h>

inherit CMD;

private void main(string * arg) 
{
    string path = arg[0] ;
    string * paths;
    object shell_ob = this_body()->query_shell_ob();

    paths = shell_ob->query_path();

    if ( member_array(path, paths) == -1 )
    {
        //out("The path does not exist in your current path\n");
        out("这条路径并没有出现在你当前的路径中。\n");
        return;
    }

    paths -= ({ path });
    shell_ob->set_variable("path", paths);

    out(iwrap(implode(paths,
                        (: $1 + $2[0..<2] + ", " :),
                        //"Your path is now: "
                        "当前路径：")[0..<3]) + "\n");
}
