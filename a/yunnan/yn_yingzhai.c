// this room is created by buzzer.c
// driver is �������
// created date is Fri Jun  3 21:56:45 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("yunnan");
set_light(50);
set_brief("%^YELLOW%^"+"Ӫկ"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/yunnan/yn_zhangpeng.c",

"east":"/a/yunnan/yn_shibanlu1.c",
 ]));
}
