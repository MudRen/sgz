// this room is created by buzzer.c
// driver is �������
// created date is Tue Jun 14 22:13:13 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("hangu");
set_light(50);
set_brief("%^YELLOW%^"+"�о���"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/hangu/hgg_yingzhai.c",
 ]));
}
