// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Thu Jun  2 20:51:06 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("poyang");
set_light(50);
set_brief("%^YELLOW%^"+"buzzer"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/poyang/tmp.c",
 ]));
}
