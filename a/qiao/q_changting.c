// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Sun May 29 17:14:40 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("qiao");
set_light(50);
set_brief("%^YELLOW%^"+"≥§Õ§"+"%^RESET%^");
set_long("");
set_exits( ([
"northwest":"/a/qiao/q_xiaochang.c",

"east":"/a/qiao/q_dongdadao.c",

"southwest":"/a/qiao/q_caishikou.c",
 ]));
}
