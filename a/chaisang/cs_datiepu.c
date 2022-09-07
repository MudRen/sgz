// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Mon May 30 20:52:13 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("chaisang");
set_light(50);
set_brief("%^YELLOW%^"+"´òÌúÆÌ"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/chaisang/cs_nanjiedong.c",
 ]));
}
