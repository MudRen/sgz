// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Fri May 27 19:12:15 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("jingyang");
set_light(50);
set_brief("%^YELLOW%^"+"��ջ"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/jingyang/jy_chengnanjie.c",
 ]));
}
