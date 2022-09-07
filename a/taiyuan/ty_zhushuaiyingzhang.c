// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Thu May 26 20:49:44 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("taiyuan");
set_light(50);
set_brief("%^YELLOW%^"+"Ö÷Ë§ÓªÕÊ"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/taiyuan/ty_bingying.c",
 ]));
}
