// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Thu Jun  2 21:22:16 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("baima");
set_light(50);
set_brief("%^YELLOW%^"+"Ӫ��"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/baima/bm_xiaochang.c",
 ]));
}
