// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Fri May  6 22:03:07 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuguan");
set_light(50);
set_brief("%^YELLOW%^"+"关前大路"+"%^RESET%^");
set_long("");
set_objects((["/sgdomain/modules/m_charnpc/guard.c":1]));
}
