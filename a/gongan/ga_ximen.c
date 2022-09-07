// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Sun Jul 17 23:14:40 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("gongan");
set_light(50);
set_brief("%^YELLOW%^"+"Î÷ÃÅ"+"%^RESET%^");
set_long("");
set_objects((["/sgdomain/modules/m_charnpc/guard.c":1]));
}
