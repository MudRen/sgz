// this room is created by buzzer.c
// driver is �������
// created date is Fri May  6 15:13:25 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuzhangyuan");
set_light(50);
set_brief("%^YELLOW%^"+"С����"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/wuzhangyuan/wzy_yingzhai.c",
 ]));
}
