// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Wed Jun 15 22:25:34 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("yanmenguan");
set_light(50);
set_brief("%^YELLOW%^"+"��ǰС��"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/yanmenguan/ymg_dongguankou.c",
 ]));
}
