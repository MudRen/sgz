// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Wed Jun 15 22:17:40 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("yanmenguan");
set_light(50);
set_brief("%^YELLOW%^"+"��ɽ��"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/yanmenguan/ymg_xiaomuwu.c",

"south":"/a/yanmenguan/ymg_qianshanlu.c",
 ]));
}
