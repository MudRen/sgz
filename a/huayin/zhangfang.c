// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Fri Apr 29 12:49:42 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"ÕÊ·¿"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/huayin/qianting.c",
 ]));
}
