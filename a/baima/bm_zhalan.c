// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Thu Jun  2 21:17:42 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("baima");
set_light(50);
set_brief("%^YELLOW%^"+"դ��"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/baima/bm_shulin.c",

"east":"/a/baima/bm_tulu.c",
 ]));
}
