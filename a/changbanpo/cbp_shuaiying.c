// this room is created by buzzer.c
// driver is �������
// created date is Tue Jul 19 09:31:36 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("changbanpo");
set_light(50);
set_brief("%^YELLOW%^"+"˧Ӫ"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/changbanpo/cbp_yingzhai.c",
 ]));
}
