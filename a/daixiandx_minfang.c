// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Mon May 30 19:55:45 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("daixian");
set_light(50);
set_brief("%^YELLOW%^"+"��"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/daixiandx_xijie.c",
 ]));
}
