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
"    ������һ����խ�������ϣ�����Ϳ쵽�������ˡ��������ر���
��һ�Ӷӹٱ���������롣�����Ĳ����Ǻ���ĵط���\n\n"
);
   set_room_state("valid_start");
    set_exits( ([
    "west" : __DIR__+"hn_xj2.c",
    "north" : __DIR__+"hn_sbf",
    "east" : __DIR__+"hn_cz",
    ]) );
    set_objects( ([
    ]) );
}
