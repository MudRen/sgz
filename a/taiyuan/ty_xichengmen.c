// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Thu May 26 20:46:00 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("taiyuan");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/taiyuan/ty_xidajie2.c",
 ]));
}
