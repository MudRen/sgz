// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Mon May 30 20:49:23 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("chaisang");
set_light(50);
set_brief("%^YELLOW%^"+"�ϴ��"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/chaisang/cs_dajishi.c",

"south":"/a/chaisang/cs_nanchengmen.c",

"east":"/a/chaisang/tmp.c",
 ]));
}
