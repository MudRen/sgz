// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Sat May 28 11:32:16 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("xianyang");
set_light(50);
set_brief("%^YELLOW%^"+"Î÷´ó½Ö"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/xianyang/xy_xidajie2.c",

"south":"/a/xianyang/xy_bingqipu.c",

"east":"/a/xianyang/xy_chengzhongxin.c",
 ]));
}
