// this room is created by buzzer.c
// driver is �������
// created date is Sun May 29 19:37:12 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("qiao");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/qiao/q_xidadao.c",
 ]));
}
