// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// Rust

#include <mudlib.h>
#include <setbit.h>
#include <daemons.h>

inherit CMD;


private void main() {
    string msg;
    if(!this_body()->is_visible())
    {
        out("���Ѿ������ˡ�\n");
        return;
    }
    this_body()->do_player_message("invis");
    out("�����ڿ�ʼ������\n");
    this_body()->set_visibility(0);

    FINGER_D->update_me();
    return;
}

