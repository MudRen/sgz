// this room is created by buzzer.c
// driver is �������
// created date is Fri Jul 29 10:30:14 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("xiangyang");
set_light(50);
set_brief("%^YELLOW%^"+"��ؽ�"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/xiangyang/xy_tianchijie3.c",

"east":"/a/xiangyang/xy_minzhai.c",

"west":"/a/xiangyang/xy_tudimiao.c",

"south":"/a/xiangyang/xy_tianchijie1.c",
 ]));
}
