// this room is created by buzzer.c
// driver is �������
// created date is Tue May  3 21:33:09 2011
#include <mudlib.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("changan");
set_light(50);
set_brief("%^YELLOW%^"+"�ϳ���"+"%^RESET%^");
set_objects((["/sgdomain/modules/m_charnpc/guard.c":1]));
set_long("");
}
