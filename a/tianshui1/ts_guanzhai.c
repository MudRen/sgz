// this room is created by buzzer.c
// driver is �������
// created date is Sun May  8 21:33:01 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("tianshui");
set_light(50);
set_brief("%^YELLOW%^"+"��լ"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/tianshui/ts_beidajie.c",

"south":"/a/tianshui/ts_dongdajie.c",
 ]));
}
