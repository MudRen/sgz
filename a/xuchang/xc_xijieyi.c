// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sun May 29 12:20:48 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("xuchang");
set_light(50);
set_brief("%^YELLOW%^"+"����һ"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/xuchang/xc_balingqiao.c",

"west":"/a/xuchang/xc_xichengmen.c",

"south":"/a/xuchang/xc_yaopu.c",

"east":"/a/xuchang/xc_xijieer.c",
 ]));
}
