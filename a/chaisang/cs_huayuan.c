// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Wed Jun  1 11:19:48 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("chaisang");
set_light(50);
set_brief("%^YELLOW%^"+"»¨Ô°"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/chaisang/cs_guanzhai.c",
 ]));
}
