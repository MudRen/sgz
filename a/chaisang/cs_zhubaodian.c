// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Mon May 30 21:03:11 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("chaisang");
set_light(50);
set_brief("%^YELLOW%^"+"�鱦��"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/chaisang/cs_beijiezhong.c",
 ]));
}
