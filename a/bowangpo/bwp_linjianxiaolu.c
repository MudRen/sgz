// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sun Jun 12 21:40:32 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("bowangpo");
set_light(50);
set_brief("%^YELLOW%^"+"�ּ�С·"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/bowangpo/bwp_yangchangxiaodao.c",
 ]));
}
