// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Fri May 27 19:06:53 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("jingyang");
set_light(50);
set_brief("%^YELLOW%^"+"ÒéÊÂÌü"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/jingyang/jy_junying.c",
 ]));
}
