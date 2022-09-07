// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Fri May 27 19:03:07 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("jingyang");
set_light(50);
set_brief("%^YELLOW%^"+"³Ç¶«½Ö"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/jingyang/jy_tuwu.c",

"north":"/a/jingyang/jy_junying.c",

"west":"/a/jingyang/jy_chengzhongxin.c",
 ]));
}
