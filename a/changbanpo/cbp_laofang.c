// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Tue Jul 19 09:32:28 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("changbanpo");
set_light(50);
set_brief("%^YELLOW%^"+"ÀÎ·¿"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/changbanpo/cbp_linjianxiaodao.c",
 ]));
}
