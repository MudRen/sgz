// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Mon May 30 20:06:21 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("daixian");
set_light(50);
set_brief("%^YELLOW%^"+"�㳡"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/daixian/dx_nanjie1.c",

"north":"/a/daixian/dx_jishi.c",

"east":"/a/daixian/dx_dongjie.c",

"west":"/a/daixian/dx_xijie.c",
 ]));
}
