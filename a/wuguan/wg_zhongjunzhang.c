// this room is created by buzzer.c
// driver is �������
// created date is Fri May  6 22:00:05 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("wuguan");
set_light(50);
set_brief("%^YELLOW%^"+"�о���"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/wuguan/wg_yingzhai.c",
 ]));
}
