// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Tue Jul 19 09:32:06 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("changbanpo");
set_light(50);
set_brief("%^YELLOW%^"+"林间小道"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/changbanpo/cbp_dalu.c",

"west":"/a/changbanpo/cbp_laofang.c",

"north":"/a/changbanpo/cbp_shuling.c",
 ]));
}
