// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Mon May 30 20:14:35 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("daixian");
set_light(50);
set_brief("%^YELLOW%^"+"�Ͻ�һ"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/daixian/dx_nanjie2.c",

"east":"/a/daixian/dx_zahuopu.c",

"north":"/a/daixian/dx_guangchang.c",
 ]));
}
