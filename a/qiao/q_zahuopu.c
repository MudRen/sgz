// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sun May 29 17:08:30 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("qiao");
set_light(50);
set_brief("%^YELLOW%^"+"�ӻ���"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/qiao/q_nandajie.c",
 ]));
}
