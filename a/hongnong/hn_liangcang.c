// this room is created by buzzer.c
// driver is �������
// created date is Wed Jun 15 20:19:36 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("hongnong");
set_light(50);
set_brief("%^YELLOW%^"+"����"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/hongnong/hn_beidajie.c",
"south":"/a/hongnong/hn_juhuisuo.c",
 ]));
}
