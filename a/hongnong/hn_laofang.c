// this room is created by buzzer.c
// driver is �������
// created date is Wed Jun 15 20:05:26 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("hongnong");
set_light(50);
set_brief("%^YELLOW%^"+"�η�"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/hongnong/hn_yamen.c",
 ]));
}
