// this room is created by buzzer.c
// driver is �������
// created date is Wed Jun 15 20:08:46 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("hongnong");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/hongnong/hn_beidajie.c",

"east":"/a/hongnong/hn_dongdajie.c",

"west":"/a/hongnong/hn_xidajie.c",

"south":"/a/hongnong/hn_nandajie2.c",
 ]));
}
