// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Mon May 30 21:06:13 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("chaisang");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/chaisang/cs_xiaochang.c",
 ]));
}
