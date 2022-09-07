// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Sun May 29 11:55:44 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("xuchang");
set_light(50);
set_brief("%^YELLOW%^"+"¥∫«Ô¬•"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/xuchang/xc_wenchangge.c",

"west":"/a/xuchang/xc_zhubaodian.c",

"north":"/a/xuchang/xc_kuiloujie.c",
 ]));
}
