// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sat May 28 12:05:26 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("xianyang");
set_light(50);
set_brief("%^YELLOW%^"+"ҽ��"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/xianyang/xy_beidajie2.c",
 ]));
}
