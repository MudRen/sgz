// this room is created by buzzer.c
// driver is ∞Õ…Ω“π”Í
// created date is Thu May 26 20:46:24 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("taiyuan");
set_light(50);
set_brief("%^YELLOW%^"+"ƒœ¥ÛΩ÷"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/taiyuan/ty_zahuopu.c",

"west":"/a/taiyuan/ty_qianzhuang.c",

"south":"/a/taiyuan/ty_nandajie2.c",

"north":"/a/taiyuan/ty_chengzhongxin.c",
 ]));
}
