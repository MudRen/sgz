// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Sun May 29 17:13:54 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("qiao");
set_light(50);
set_brief("%^YELLOW%^"+"ÄÚÌÃ"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/qiao/q_xianyamen.c",
 ]));
}
