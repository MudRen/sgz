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
    set_brief(YEL+"�ٳ�"+NOR);
    set_long(
"  һ.��.һ��.һ........,��������.������ǲٳ�,һȺȺ��ʿ��
���ڲ���.����������,���������,��ɽ���ϻ�,�������¿�"
);
   set_room_state("valid_start");
    set_exits( ([
    "north" : __DIR__+"hn_dj2",
    ]) );
    set_objects( ([
    ]) );
}
