// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Sat May  7 14:28:39 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"ÀÎÓü"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/longxi/lx_datang.c",
 ]));
}
