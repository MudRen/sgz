// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sun Jun 12 20:36:48 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("bailangshan");
set_light(50);
set_brief("%^YELLOW%^"+"¹��"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/bailangshan/bls_xiaolu.c",
 ]));
}
