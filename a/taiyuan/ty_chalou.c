// this room is created by buzzer.c
// driver is �������
// created date is Thu May 26 19:56:32 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
inherit STORE;

void setup() {
set_area("taiyuan");
set_light(50);
set_brief("%^YELLOW%^"+"��¥"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/taiyuan/ty_dongdajie1.c",
 ]));
set_objects((["/sgdomain/obj/other/board.c" : ({ 1,"̫ԭ�Ĳ�¥���ſڹ���һ����¥�����ơ�list�г���Ʒ��buy����\n\n"}) ]) );
add_object("/sgdomain/obj/foodanddrink/mantou.c");
add_object("/sgdomain/obj/foodanddrink/ypjd.c");

set_objects( (["/sgdomain/obj/other/well.c" : 1]) );
}
