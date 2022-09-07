// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Fri May 27 19:24:15 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("anding");
set_light(50);
set_brief("%^YELLOW%^"+"³ÇÎ÷½Ö"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/anding/ad_xichengmen.c",

"north":"/a/anding/ad_yamen.c",

"south":"/a/anding/ad_jiuguan.c",

"east":"/a/anding/ad_chengzhongxin.c",
 ]));
}
