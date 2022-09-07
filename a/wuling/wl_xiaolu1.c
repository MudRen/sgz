// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Sat May 28 19:50:18 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"Ð¡Â·"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/wuling/wl_xiaomatou.c",

"west":"/a/wuling/wl_yishiting.c",

"south":"/a/wuling/wl_kezhan.c",

"east":"/a/wuling/wl_xiaolu2.c",
 ]));
}
