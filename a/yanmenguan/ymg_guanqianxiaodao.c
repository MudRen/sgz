// this room is created by buzzer.c
// driver is 巴山夜雨
// created date is Wed Jun 15 22:25:34 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("yanmenguan");
set_light(50);
set_brief("%^YELLOW%^"+"关前小道"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/yanmenguan/ymg_dongguankou.c",
 ]));
}
