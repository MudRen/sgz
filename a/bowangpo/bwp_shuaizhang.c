// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sun Jun 12 21:43:16 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("bowangpo");
set_light(50);
set_brief("%^YELLOW%^"+"˧��"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/bowangpo/bwp_zhalan.c",
 ]));
}
