// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Fri May 27 19:30:55 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("anding");
set_light(50);
set_brief("%^YELLOW%^"+"��լ"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/anding/ad_chengdongjie.c",
 ]));
}
