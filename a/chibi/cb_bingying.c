// this room is created by buzzer.c
// driver is �������
// created date is Mon Jul 25 23:32:53 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("chibi");
set_light(50);
set_brief("%^YELLOW%^"+"��Ӫ"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/chibi/cb_shuaizhang.c",

"east":"/a/chibi/cb_liangcang.c",

"west":"/a/chibi/cb_laofang.c",

"south":"/a/chibi/cb_xiaolu.c",
 ]));
}
