// this room is created by buzzer.c
// driver is �������
// created date is Sat Jul 23 22:05:33 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("jiangxia");
set_light(50);
set_brief("%^YELLOW%^"+"У��"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/jiangxia/jx_suishixiaolu.c",

"east":"/a/jiangxia/jx_bingying.c",

"west":"/a/jiangxia/jx_guanzhai.c",

"north":"/a/jiangxia/jx_beijie.c",
 ]));
}
