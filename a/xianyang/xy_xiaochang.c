// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sat May 28 12:07:26 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("xianyang");
set_light(50);
set_brief("%^YELLOW%^"+"У��"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/xianyang/xy_junying.c",
 ]));
}
