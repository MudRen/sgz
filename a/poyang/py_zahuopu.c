// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Thu Jun  2 21:06:18 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("poyang");
set_light(50);
set_brief("%^YELLOW%^"+"�ӻ���"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/poyang/py_bingying.c",
 ]));
}
