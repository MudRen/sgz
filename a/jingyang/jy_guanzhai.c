// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Fri May 27 19:15:39 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("jingyang");
set_light(50);
set_brief("%^YELLOW%^"+"��լ"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/jingyang/jy_neizhai.c",

"west":"/a/jingyang/jy_huayuan.c",

"east":"/a/jingyang/jy_chengnanjie.c",
 ]));
}
