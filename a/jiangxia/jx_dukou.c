// this room is created by buzzer.c
// driver is �������
// created date is Sat Jul 23 22:04:11 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("jiangxia");
set_light(50);
set_brief("%^YELLOW%^"+"�ɿ�"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/jiangxia/jx_beijie.c",
 ]));
}
