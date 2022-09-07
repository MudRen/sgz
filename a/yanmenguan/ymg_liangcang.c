// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Wed Jun 15 22:23:14 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("yanmenguan");
set_light(50);
set_brief("%^YELLOW%^"+"¡∏≤÷"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/yanmenguan/ymg_laofang.c",

"north":"/a/yanmenguan/ymg_houshanlu.c",
 ]));
}
