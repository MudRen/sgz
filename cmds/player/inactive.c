// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// Jan 10, 94 by Rust
// No longer works
// Megaboz@ZorkMUD added help

#include <mudlib.h>
#include <daemons.h>
#include <playerflags.h>


inherit CMD;
inherit M_INPUT;


private nomask void become_active(int start_time, string str)
{
    int num;
    int hours, minutes;

    num = time() - start_time;
    printf("��%s�����ֻص�����Ϸ��\n", CHINESE_D->chinese_period(num));
    this_body()->other_action("$N���»ص���Ϸ��\n");
    this_body()->clear_flag(F_INACTIVE);
}


nomask private void main(string arg)
{
    out("��ѡ����ʱ�뿪��Ϸ������Ҫ����ʱ����һ��<return>�����ˡ�\n");
    this_body()->other_action("$N���������״̬��\n");
    this_body()->set_flag(F_INACTIVE);
    modal_simple((: become_active, time() :));
}

