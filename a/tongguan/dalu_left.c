// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Sun May  1 23:04:08 2011
#include <mudlib.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("tongguan");
set_light(50);
set_brief("%^YELLOW%^"+"´óÂ·"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/tongguan/shanlu.c",

"east":"/a/tongguan/guankou.c",
 ]));
}
