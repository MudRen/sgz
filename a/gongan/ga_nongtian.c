// this room is created by buzzer.c
// driver is �������
// created date is Sun Jul 17 23:24:18 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("gongan");
set_light(50);
set_brief("%^YELLOW%^"+"ũ��"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/gongan/ga_cunbianxiaolu.c",
 ]));
}
