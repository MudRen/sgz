// this room is created by buzzer.c
// driver is �������
// created date is Sun May 29 20:43:50 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("qiao");
set_light(50);
set_brief("%^YELLOW%^"+"Ǯׯ"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/qiao/q_dongdadao.c",
 ]));
}
