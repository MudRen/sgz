// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Thu Jun  2 21:15:44 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("baima");
set_light(50);
set_brief("%^YELLOW%^"+"��·"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/baima/bm_xiaochang.c",

"west":"/a/baima/bm_zhalan.c",

"south":"/a/baima/bm_laofang.c",

"north":"/a/baima/tmp.c",
 ]));
}
