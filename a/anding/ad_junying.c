// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Fri May 27 19:32:01 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("anding");
set_light(50);
set_brief("%^YELLOW%^"+"¾üÓª"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/anding/ad_xiaochang.c",

"south":"/a/anding/ad_chengdongjie.c",
 ]));
}
