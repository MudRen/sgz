// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Mon May 30 20:16:05 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("daixian");
set_light(50);
set_brief("%^YELLOW%^"+"�Ͻֶ�"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/daixian/dx_yamen.c",

"west":"/a/daixian/dx_liangcang.c",

"south":"/a/daixian/dx_nanmenkou.c",

"north":"/a/daixian/dx_nanjie1.c",
 ]));
}
