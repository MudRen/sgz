// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Thu Jun  2 20:59:16 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("poyang");
set_light(50);
set_brief("%^YELLOW%^"+"��ջ"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/poyang/py_xijie.c",
 ]));
set_objects( (["/sgdomain/obj/other/bed.c" : 1]) );
}
