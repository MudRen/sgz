// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Thu Jun  2 21:00:22 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("poyang");
set_light(50);
set_brief("%^YELLOW%^"+"����"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/poyang/py_jianyu.c",

"west":"/a/poyang/py_naoshi.c",
 ]));
}
