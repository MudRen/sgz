// this room is created by buzzer.c
// driver is �������
// created date is Sun Jul 17 23:13:28 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("gongan");
set_light(50);
set_brief("%^YELLOW%^"+"С·"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/gongan/ga_tulu.c",

"north":"/a/gongan/ga_junying.c",

"west":"/a/gongan/ga_ximen.c",

"south":"/a/gongan/tmp.c",
 ]));
}
