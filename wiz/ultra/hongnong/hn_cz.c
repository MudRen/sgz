/* hn_cc.c
** Coded by ����@LIMA
** Code generated with RoomMaker v0.9.1 coded by Onyx@RedDragon
** Do not remove this header.
*/

#include <ansi.h>

inherit OUTDOOR_ROOM;

void setup(){
   set_area("hn_area");
    set_light(50);
    set_brief(YEL+"����"+NOR);
    set_long(
"    ������Ǻ�ũ�ĳ����ġ���Ȼ��ũ�Ǻ�С����������Ҳ�Ǻܴ�
·�����������������Ƕ��֣�ԶԶ��һЩ���ӡ����������֣��Ǳ���
һ�ҿ�ջ��ȥ����Ϣ��Ϣ�ɡ�\n
");
   set_room_state("valid_start");
    set_exits( ([
    "west" : __DIR__+"hn_xj1.c",
    "east" : __DIR__+"hn_dj1",
"southwest" :  __DIR__+"hn_yizhan.c",
    ]) );
    set_objects( ([
    ]) );
}
