// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sat May 28 19:58:46 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"����"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/wuling/wl_xiaolu2.c",

"east":"/a/wuling/wl_julongxuan.c",

"south":"/a/wuling/wl_beijie2.c",
 ]));
}
