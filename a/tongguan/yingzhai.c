// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Sun May  1 23:01:26 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("tongguan");
set_light(50);
set_brief("%^YELLOW%^"+"ÓªÕ¯"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/tongguan/dalu.c",

"north":"/a/tongguan/zhongjunzhang.c",

"west":"/a/tongguan/tmp.c",
 ]));
}
