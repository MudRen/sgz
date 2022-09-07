// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Sat May 28 11:46:58 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("xianyang");
set_light(50);
set_brief("%^YELLOW%^"+"ÄÏ³ÇÏï"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/xianyang/xy_xiaomiao.c",

"north":"/a/xianyang/xy_qianzhuang.c",

"west":"/a/xianyang/xy_nanchengxiang.c",
 ]));
}
