// this room is created by buzzer.c
// driver is �������
// created date is Fri May  6 21:53:39 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuguan");
set_light(50);
set_brief("%^YELLOW%^"+"����·"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/wuguan/wg_yingzhai.c",

"northwest":"/a/wuguan/wg_daokou.c",

"south":"/a/wuguan/wg_laofang.c",

"west":"/a/wuguan/tmp.c",
 ]));
}
