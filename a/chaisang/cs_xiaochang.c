// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Mon May 30 21:05:39 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("chaisang");
set_light(50);
set_brief("%^YELLOW%^"+"У��"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/chaisang/cs_beichengmen.c",

"east":"/a/chaisang/cs_junying.c",
 ]));
}
