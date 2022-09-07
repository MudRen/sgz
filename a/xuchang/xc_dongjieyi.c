// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Sun May 29 11:50:46 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("xuchang");
set_light(50);
set_brief("%^YELLOW%^"+"∂´Ω÷“ª"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/xuchang/xc_chengzhongxin.c",

"north":"/a/xuchang/xc_chengbeidajie.c",

"south":"/a/xuchang/xc_kuiloujie.c",

"east":"/a/xuchang/xc_dongjieer.c",
 ]));
}
