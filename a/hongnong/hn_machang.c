// this room is created by buzzer.c
// driver is �������
// created date is Wed Jun 15 20:19:00 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("hongnong");
set_light(50);
set_brief("%^YELLOW%^"+"��"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/hongnong/hn_beidajie.c",
 ]));
}
