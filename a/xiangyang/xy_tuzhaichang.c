// this room is created by buzzer.c
// driver is �������
// created date is Fri Jul 29 10:35:48 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("xiangyang");
set_light(50);
set_brief("%^YELLOW%^"+"���׳�"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/xiangyang/xy_huangtulu.c",

"south":"/a/xiangyang/xy_roupu.c",

"east":"/a/xiangyang/xy_xiangzhudian.c",
 ]));
}
