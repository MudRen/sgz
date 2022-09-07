// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Sun May 29 17:09:24 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("qiao");
set_light(50);
set_brief("%^YELLOW%^"+"ºØ –"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/qiao/q_caishikou.c",

"east":"/a/qiao/q_jiuguan.c",

"west":"/a/qiao/q_kezhan.c",

"south":"/a/qiao/q_nandajie.c",
 ]));
}
