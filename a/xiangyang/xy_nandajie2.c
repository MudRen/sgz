// this room is created by buzzer.c
// driver is �������
// created date is Thu Jul 28 19:02:11 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("xiangyang");
set_light(50);
set_brief("%^YELLOW%^"+"�ϴ��"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/xiangyang/xy_yamen.c",

"east":"/a/xiangyang/xy_junying.c",

"south":"/a/xiangyang/xy_guanzhai.c",

"north":"/a/xiangyang/xy_nandajie1.c",
 ]));
}
