// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Fri May 27 19:16:33 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("jingyang");
set_light(50);
set_brief("%^YELLOW%^"+"ª®‘∞"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/jingyang/jy_guanzhai.c",
 ]));
}
