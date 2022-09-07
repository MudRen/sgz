// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Thu Jun  2 19:45:34 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("dingtao");
set_light(50);
set_brief("%^YELLOW%^"+"øÕ’ª"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/dingtao/dt_xixiaodao.c",
 ]));
}
