// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sat May 28 12:12:46 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("xianyang");
set_light(50);
set_brief("%^YELLOW%^"+"��լ"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/xianyang/xy_beidajie3.c",
 ]));
}
