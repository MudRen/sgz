// this room is created by buzzer.c
// driver is �������
// created date is Sun Jul 17 23:21:56 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("gongan");
set_light(50);
set_brief("%^YELLOW%^"+"ɹ�ȳ�"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/gongan/ga_cunbianxiaolu.c",

"south":"/a/gongan/ga_tudimiao.c",

"north":"/a/gongan/ga_yishiting.c",

"west":"/a/gongan/ga_tulu.c",
 ]));
}
