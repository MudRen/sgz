// this room is created by buzzer.c
// driver is �������
// created date is Sun Jul 17 23:23:48 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("gongan");
set_light(50);
set_brief("%^YELLOW%^"+"���С·"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/gongan/ga_nongtian.c",

"west":"/a/gongan/ga_shaiguchang.c",
 ]));
}
