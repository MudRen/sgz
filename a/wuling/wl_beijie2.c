// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sat May 28 19:55:38 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"����"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/wuling/wl_beijie3.c",

"east":"/a/wuling/wl_xiaomiao.c",

"south":"/a/wuling/wl_beijie1.c",
 ]));
}
