// this room is created by buzzer.c
// driver is �������
// created date is Thu Jul 28 19:13:31 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("xiangyang");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/xiangyang/xy_tianchijie1.c",

"south":"/a/xiangyang/xy_nandajie1.c",

"east":"/a/xiangyang/xy_qingshiludong.c",

"west":"/a/xiangyang/xy_qingshiluxi.c",
 ]));
}
