// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Sat May  7 12:16:59 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"µãÐÄÆÌ"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/longxi/lx_dounanjie2.c",
 ]));
}
