// this room is created by buzzer.c
// driver is �������
// created date is Sun May 29 20:50:06 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("qiao");
set_light(50);
set_brief("%^YELLOW%^"+"��լ"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/qiao/q_houyuan.c",

"east":"/a/qiao/q_beidajie.c",
 ]));
}
