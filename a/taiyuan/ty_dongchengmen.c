// this room is created by buzzer.c
// driver is �������
// created date is Thu May 26 19:47:52 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("taiyuan");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/taiyuan/ty_dongdajie2.c",
 ]));
}
