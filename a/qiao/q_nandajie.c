// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sun May 29 17:05:46 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("qiao");
set_light(50);
set_brief("%^YELLOW%^"+"�ϴ��"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/qiao/q_jishi.c",

"west":"/a/qiao/q_zahuopu.c",

"south":"/a/qiao/q_nanchengmen.c",

"east":"/a/qiao/tmp.c",
 ]));
}
