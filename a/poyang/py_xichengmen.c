// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Thu Jun  2 20:58:36 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("poyang");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("");
set_objects((["/sgdomain/modules/m_charnpc/guard.c":1]));
set_exits( ([
"enter":"/a/poyang/py_xijie.c",
 ]));
}
