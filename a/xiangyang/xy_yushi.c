// this room is created by buzzer.c
// driver is �������
// created date is Fri Jul 29 10:51:28 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("xiangyang");
set_light(50);
set_brief("%^YELLOW%^"+"����"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/xiangyang/xy_qingshiludong.c",

"north":"/a/xiangyang/xy_guopu.c",
 ]));
}
