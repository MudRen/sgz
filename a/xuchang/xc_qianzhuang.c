// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sun May 29 11:54:50 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("xuchang");
set_light(50);
set_brief("%^YELLOW%^"+"Ǯׯ"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/xuchang/xc_kuiloujie.c",
 ]));
}
