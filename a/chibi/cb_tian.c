// this room is created by buzzer.c
// driver is �������
// created date is Mon Jul 25 23:37:31 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("chibi");
set_light(50);
set_brief("%^YELLOW%^"+"�̰�"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/chibi/cb_liangcang.c",
 ]));
}
