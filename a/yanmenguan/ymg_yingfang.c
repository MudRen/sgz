// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Wed Jun 15 22:20:50 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("yanmenguan");
set_light(50);
set_brief("%^YELLOW%^"+"Ӫ��"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/yanmenguan/ymg_yingzhai.c",
 ]));
}
