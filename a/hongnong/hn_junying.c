// this room is created by buzzer.c
// driver is �������
// created date is Wed Jun 15 20:18:30 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("hongnong");
set_light(50);
set_brief("%^YELLOW%^"+"��Ӫ"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/hongnong/hn_beidajie.c",
"south":"/a/hongnong/hn_xidajie.c",
 ]));
}
