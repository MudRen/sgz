// this room is created by buzzer.c
// driver is �������
// created date is Sun Jul 17 23:16:16 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("gongan");
set_light(50);
set_brief("%^YELLOW%^"+"��·"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/gongan/ga_shaiguchang.c",

"north":"/a/gongan/ga_maowu.c",

"south":"/a/gongan/ga_xiaodian.c",

"west":"/a/gongan/ga_xiaolu.c",
 ]));
}
