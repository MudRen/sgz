// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Fri Jul 29 11:08:08 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("xiangyang");
set_light(50);
set_brief("%^YELLOW%^"+"ÇàÖñÐ¡¾¶"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/xiangyang/xy_caolu.c",

"north":"/a/xiangyang/xy_qingshiluxi.c",
 ]));
}
