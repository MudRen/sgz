// this room is created by buzzer.c
// driver is �������
// created date is Sat May  7 14:38:07 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"С��"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/longxi/lx_minzhai.c",

"west":"/a/longxi/lx_xiaoxiang3.c",

"east":"/a/longxi/lx_xiaoxiang1.c",
 ]));
}
