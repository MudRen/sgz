// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// Rust/Belboz

#include <mudlib.h>

inherit CMD;

private void main()
{
    object ob = this_body()->query_shell_ob();

    outf("��ǰĿ¼:  %s\n��ǰ�ļ�: %s\n",
           ob->get_variable("pwd") || "NONE",
           ob->get_variable("cwf") || "NONE");
}

              
