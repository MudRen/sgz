// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Mon May 30 19:11:09 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("nanpi");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/nanpi/np_longxiangxilu.c",

"west":"/a/nanpi/np_linfengjiulou.c",

"north":"/a/nanpi/np_xiaochang.c",
 ]));
}
