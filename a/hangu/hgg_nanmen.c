// this room is created by buzzer.c
// driver is �������
// created date is Tue Jun 14 22:13:53 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("hangu");
set_light(50);
set_brief("%^YELLOW%^"+"���ȹ�����"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/hangu/hgg_xiaodao.c",

"north":"/a/hangu/hgg_yingzhai.c",
 ]));
}
