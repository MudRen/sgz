// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sun Jun 12 21:39:20 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("bowangpo");
set_light(50);
set_brief("%^YELLOW%^"+"��С��"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/bowangpo/bwp_linjianxiaolu.c",

"north":"/a/bowangpo/bwp_shanlu.c",

 ]));
set_objects((["/sgdomain/modules/m_charnpc/guard.c":1]));
}
