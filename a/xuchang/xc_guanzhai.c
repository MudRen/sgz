// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sun May 29 12:11:22 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("xuchang");
set_light(50);
set_brief("%^YELLOW%^"+"��լ"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/xuchang/xc_nanjie1.c",
 ]));
}
