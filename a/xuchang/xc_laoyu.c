// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sun May 29 12:08:24 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("xuchang");
set_light(50);
set_brief("%^YELLOW%^"+"����"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/xuchang/xc_gongtang.c",
 ]));
}
