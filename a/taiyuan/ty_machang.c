// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Thu May 26 20:45:16 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("taiyuan");
set_light(50);
set_brief("%^YELLOW%^"+"��"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/taiyuan/ty_xidajie2.c",
 ]));
}
