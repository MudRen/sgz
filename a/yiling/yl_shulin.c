// this room is created by buzzer.c
// driver is �������
// created date is Sun Jul  3 10:33:08 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("yiling");
set_light(50);
set_brief("%^YELLOW%^"+"����"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/yiling/yl_shanlu.c",
 ]));
}
