// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sat May 28 11:31:00 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("xianyang");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/xianyang/xy_beidajie1.c",

"south":"/a/xianyang/xy_nandajie.c",

"west":"/a/xianyang/xy_xidajie.c",

"east":"/a/xianyang/xy_dongdajie1.c",
 ]));
}
