// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Mon May 30 19:11:59 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
inherit STORE;
void setup() {
set_area("nanpi");
set_light(50);
set_brief("%^YELLOW%^"+"�ٷ��¥"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/nanpi/np_lianhuachi.c",
 ]));
set_objects((["/sgdomain/obj/other/board.c" : ({ 1,"�ٷ��¥��һ���ߴ�ľ�¥���������ƣ�����������list�г���Ʒ��buy����\n\n"}) ]) );

add_object("/sgdomain/obj/foodanddrink/mantou.c");
add_object("/sgdomain/obj/foodanddrink/ypjd.c");

set_objects( (["/sgdomain/obj/other/well.c" : 1]) );
}
