// this room is created by buzzer.c
// driver is 巴山夜雨
// created date is Sun Jun 12 21:40:32 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("bowangpo");
set_light(50);
set_brief("%^YELLOW%^"+"林间小路"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/bowangpo/bwp_yangchangxiaodao.c",
 ]));
}
