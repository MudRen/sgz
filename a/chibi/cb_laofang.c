// this room is created by buzzer.c
// driver is �������
// created date is Mon Jul 25 23:36:19 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("chibi");
set_light(50);
set_brief("%^YELLOW%^"+"�η�"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/chibi/cb_bingying.c",
 ]));
}
