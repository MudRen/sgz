// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Sun Jul  3 10:37:30 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("yiling");
set_light(50);
set_brief("%^YELLOW%^"+"ÀÎ·¿"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/yiling/yl_zhalan.c",
 ]));
}
