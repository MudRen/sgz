// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Thu Jun  2 21:01:00 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("poyang");
set_light(50);
set_brief("%^YELLOW%^"+"����"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/poyang/py_yamen.c",
 ]));
}
