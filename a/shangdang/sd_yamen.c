// this room is created by buzzer.c
// driver is �������
// created date is Wed Jun 15 16:26:04 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("shangdang");
set_light(50);
set_brief("%^YELLOW%^"+"����"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/shangdang/sd_datang.c",

"east":"/a/shangdang/sd_nandajie1.c",
 ]));
}
