// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Thu Jun  2 19:43:14 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("dingtao");
set_light(50);
set_brief("%^YELLOW%^"+"��С��"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/dingtao/dt_xiaochang.c",

"north":"/a/dingtao/dt_kezhan.c",

"west":"/a/dingtao/dt_xidaokou.c",

"south":"/a/dingtao/tmp.c",
 ]));
}
