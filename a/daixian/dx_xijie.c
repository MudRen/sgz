// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Mon May 30 20:04:25 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("daixian");
set_light(50);
set_brief("%^YELLOW%^"+"����"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/daixian/dx_guangchang.c",

"north":"/a/daixian/dx_minfang.c",

"west":"/a/daixian/dx_xichengmen.c",

"south":"/a/daixian/tmp.c",
 ]));
}
