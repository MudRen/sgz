// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// Beek, End of July

#include <mudlib.h>
inherit CMD;

private void main(string arg) {
    if (!arg) {
        out("��Ҫȡһ��ʲô�ºţ�\n");
        return;
    }
    
    this_body()->set_nickname(arg);
    out("��ɡ�\n");
}

