// this room is created by buzzer.c
// driver is �������
// created date is Fri Jun  3 22:10:25 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("yunnan");
set_light(50);
set_brief("%^YELLOW%^"+"é��"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/yunnan/yn_tulu2.c",
 ]));
}
