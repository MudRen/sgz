// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Fri May 27 19:10:01 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("jingyang");
set_light(50);
set_brief("%^YELLOW%^"+"���Ͻ�"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/jingyang/jy_guanzhai.c",

"east":"/a/jingyang/jy_roupu.c",

"south":"/a/jingyang/jy_kezhan.c",

"north":"/a/jingyang/jy_chengzhongxin.c",
 ]));
}
