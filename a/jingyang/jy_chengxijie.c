// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Fri May 27 18:48:05 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("jingyang");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/jingyang/jy_jiuguan.c",

"west":"/a/jingyang/jy_xichengmen.c",

"north":"/a/jingyang/jy_yamen.c",

"east":"/a/jingyang/jy_chengzhongxin.c",
 ]));
}
