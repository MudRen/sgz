// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** save.c -- simple player save cmd
**
** 950711, Deathblade: Created.
*/

#include <mudlib.h>
inherit CMD;

private void main(string arg)
{
    write("���ܴ��̣�ϵͳ���Զ����档 \n");
    return;
    this_body()->put_m_all_money();  // add by fire on Dec 13, 1997
    this_body()->save_me();
    out("�洢��ϡ�\n");

    return;
}
