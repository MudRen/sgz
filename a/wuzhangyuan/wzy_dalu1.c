// this room is created by buzzer.c
// driver is �������
// created date is Fri May  6 15:07:25 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuzhangyuan");
set_light(50);
set_brief("%^YELLOW%^"+"��·"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/wuzhangyuan/wzy_zhalanrukou.c",

"west":"/a/wuzhangyuan/wzy_dalu2.c",

"south":"/a/wuzhangyuan/tmp.c",
 ]));
}
