// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sat May 28 19:54:40 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"����"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/wuling/wl_beijie2.c",

"south":"/a/wuling/wl_nanjie2.c",

"west":"/a/wuling/wl_cunzhongxin.c",
 ]));
}
