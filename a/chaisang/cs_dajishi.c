// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Mon May 30 20:50:47 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("chaisang");
set_light(50);
set_brief("%^YELLOW%^"+"����"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/chaisang/cs_nanjiexi.c",

"east":"/a/chaisang/cs_nanjiedong.c",

"south":"/a/chaisang/cs_nandajie.c",
 ]));
}
