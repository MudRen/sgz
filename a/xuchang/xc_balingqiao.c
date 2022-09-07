// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Sun May 29 12:58:50 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("xuchang");
set_light(50);
set_brief("%^YELLOW%^"+"Â±¡Í«≈"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/xuchang/xc_xiaoxihu.c",

"south":"/a/xuchang/xc_xijieyi.c",
 ]));
}
