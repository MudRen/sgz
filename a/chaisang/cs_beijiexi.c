// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Mon May 30 21:00:33 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("chaisang");
set_light(50);
set_brief("%^YELLOW%^"+"±±Ω÷Œ˜"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/chaisang/cs_guanzhai.c",

"east":"/a/chaisang/cs_beijiezhong.c",

"north":"/a/chaisang/cs_qianzhuang.c",

"south":"/a/chaisang/cs_xiaoshiqiao.c",
 ]));
}
