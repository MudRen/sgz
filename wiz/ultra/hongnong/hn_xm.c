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
"    ���������ţ�����ǰ�����⵽���˵Ĺ�������Ե���Щ�ưܡ�
�������Ϸ�����ǿǿ�����ϳ������š��������֣���ǽ�����ż���ͨ
����ʾ(gaoshi)��\n\n"
);
   set_room_state("valid_start");
    set_exits( ([
    "east" : __DIR__+"hn_xj2",
    ]) );
    set_objects( (["/sgdomain/area/town/hongnong/npc/bing.c" : 2]) );
}
