// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sun May 29 17:10:22 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("qiao");
set_light(50);
set_brief("%^YELLOW%^"+"��ջ"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/qiao/q_jishi.c",
 ]));
}
