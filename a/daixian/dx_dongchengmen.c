// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Mon May 30 20:07:41 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("daixian");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/daixian/dx_dongjie.c",
 ]));
}