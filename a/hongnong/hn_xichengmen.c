// this room is created by buzzer.c
// driver is �������
// created date is Wed Jun 15 20:10:36 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("hongnong");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/hongnong/hn_xidajie.c",
 ]));
}
