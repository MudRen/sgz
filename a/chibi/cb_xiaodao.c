// this room is created by buzzer.c
// driver is �������
// created date is Mon Jul 25 23:30:19 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("chibi");
set_light(50);
set_brief("%^YELLOW%^"+"С��"+"%^RESET%^");
set_long("");
set_objects((["/sgdomain/modules/m_charnpc/guard.c":1]));
set_exits( ([
"south":"/a/chibi/tmp.c",
 ]));
}
