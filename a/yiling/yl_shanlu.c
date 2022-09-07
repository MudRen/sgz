// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Sun Jul  3 10:32:48 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("yiling");
set_light(50);
set_brief("%^YELLOW%^"+"É½Â·"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/yiling/yl_shulin.c",

"south":"/a/yiling/yl_caodi.c",
 ]));
}
