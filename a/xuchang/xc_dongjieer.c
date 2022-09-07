// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Sun May 29 11:44:26 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("xuchang");
set_light(50);
set_brief("%^YELLOW%^"+"¶«½Ö¶þ"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/xuchang/xc_dongjieyi.c",

"east":"/a/xuchang/xc_dongchengmen.c",

"south":"/a/xuchang/xc_kezhan.c",

"north":"/a/xuchang/tmp.c",
 ]));
}
