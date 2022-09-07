// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Thu Apr 28 23:22:56 2011
#include <mudlib.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"Ð¡Â·"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/huayin/xiaodian.c",

"north":"/a/huayin/tiejiangpu.c",

"west":"/a/huayin/shulin.c",

"east":"/a/huayin/cunzhongxin.c",
 ]));
}
