// this room is created by buzzer.c
// driver is �������
// created date is Sat May  7 13:49:23 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/longxi/lx_qianmendajie1.c",
 ]));
}
