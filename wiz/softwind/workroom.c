/* workroom.c
** Coded by �ͷ�@����־
** Code generated with RoomMaker v0.9.1 coded by Onyx@RedDragon
** Do not remove this header.
*/

#include <ansi.h>
#include <mudlib.h>
#include </wiz/fire/fire.h>

inherit ROOM;

void setup(){
    set_light(1);
    set_brief(HIC+"�ͷ�"+NOR+"�Ĺ�����");
    set_long(
"    ������"+HIC+"�ͷ�"+NOR+"�Ĺ����䡣���������ҵġ������ǹ���̫æ��ûʱ
����ʰ��

"
);
    set_exits( ([
HIG+"out"+NOR :  "tg_gk.c"
    ]) );
    set_objects( ([
    ]) );
}
