// this room is created by buzzer.c
// driver is �������
// created date is Sun May  8 21:13:31 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("tianshui");
set_light(50);
set_brief("%^YELLOW%^"+"�����"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/tianshui/ts_junying.c",

"south":"/a/tianshui/ts_zahuopu.c",

"west":"/a/tianshui/ts_xichengmen.c",

"east":"/a/tianshui/ts_chengzhongxin.c",
 ]));
}
