// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sat May 28 12:06:20 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("xianyang");
set_light(50);
set_brief("%^YELLOW%^"+"��Ӫ"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/xianyang/xy_xiaochang.c",

"west":"/a/xianyang/xy_beidajie2.c",
 ]));
}
