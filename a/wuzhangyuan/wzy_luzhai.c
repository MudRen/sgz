// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Fri May  6 15:16:53 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuzhangyuan");
set_light(50);
set_brief("%^YELLOW%^"+"Â¹íÎ"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/wuzhangyuan/wzy_xiaolu.c",

"east":"/a/wuzhangyuan/wzy_yingzhai.c",
 ]));
}
