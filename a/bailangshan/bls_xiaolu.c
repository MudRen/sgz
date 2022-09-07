// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Sun Jun 12 20:20:26 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("bailangshan");
set_light(50);
set_brief("%^YELLOW%^"+"Ð¡Â·"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/bailangshan/bls_yingfang.c",

"north":"/a/bailangshan/bls_xiaodian.c",

"west":"/a/bailangshan/bls_luzhai.c",

"east":"/a/bailangshan/bls_yingzhai.c",
 ]));
}
