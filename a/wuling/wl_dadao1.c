// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sat May 28 19:21:12 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"���"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/wuling/wl_dadao2.c",

"north":"/a/wuling/wl_yamen.c",

"west":"/a/wuling/wl_ximen.c",

"south":"/a/wuling/tmp.c",
 ]));
set_objects(([M_BOARD : ({ 1,"·�߹���һ�Żʰ� "+"%^MAGENTA%^"+"�������԰�"+"%^RESET%^", "city.wuling" }) ]) );
}
