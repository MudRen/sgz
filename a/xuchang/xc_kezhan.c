// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sun May 29 11:47:42 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("xuchang");
set_light(50);
set_brief("%^YELLOW%^"+"��ջ"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/xuchang/xc_dongjieer.c",
 ]));
}
