// this room is created by buzzer.c
// driver is �������
// created date is Sun May  8 21:15:23 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("tianshui");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/tianshui/ts_xidajie.c",
 ]));
}
