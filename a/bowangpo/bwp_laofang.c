// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sun Jun 12 21:41:42 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("bowangpo");
set_light(50);
set_brief("%^YELLOW%^"+"�η�"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/bowangpo/bwp_yingzhai.c",
 ]));
}
