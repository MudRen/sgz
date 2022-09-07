// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Sat May 28 19:32:20 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"ÀÈ Ø¬∑"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/wuling/wl_suishilu2.c",

"west":"/a/wuling/wl_guanzhai.c",

"north":"/a/wuling/wl_xiaoxiang.c",
 ]));
}
