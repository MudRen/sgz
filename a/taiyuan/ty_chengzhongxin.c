// this room is created by buzzer.c
// driver is �������
// created date is Thu May 26 20:02:18 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("taiyuan");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/taiyuan/ty_beidajie1.c",

"south":"/a/taiyuan/ty_nandajie1.c",

"west":"/a/taiyuan/ty_xidajie1.c",

"east":"/a/taiyuan/ty_dongdajie1.c",
 ]));
}
