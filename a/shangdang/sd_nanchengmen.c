// this room is created by buzzer.c
// driver is �������
// created date is Wed Jun 15 16:03:42 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("shangdang");
set_light(50);
set_brief("%^YELLOW%^"+"�ϳ���"+"%^RESET%^");
set_long("");
set_objects((["/sgdomain/modules/m_charnpc/guard.c":1]));
}
