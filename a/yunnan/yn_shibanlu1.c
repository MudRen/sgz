// this room is created by buzzer.c
// driver is �������
// created date is Fri Jun  3 21:54:17 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("yunnan");
set_light(50);
set_brief("%^YELLOW%^"+"ʯ��·1"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/yunnan/yn_yingzhai.c",

"south":"/a/yunnan/yn_zhulou.c",

"north":"/a/yunnan/yn_shibanlu2.c",

"east":"/a/yunnan/tmp.c",
 ]));
}
