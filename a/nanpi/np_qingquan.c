// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Mon May 30 18:54:55 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("nanpi");
set_light(50);
set_brief("%^YELLOW%^"+"��Ȫ"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/nanpi/np_bingying.c",

"east":"/a/nanpi/np_shusi.c",

"south":"/a/nanpi/np_longxiangdonglu.c",
 ]));
}
