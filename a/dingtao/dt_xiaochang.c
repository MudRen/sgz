// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Thu Jun  2 19:46:56 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("dingtao");
set_light(50);
set_brief("%^YELLOW%^"+"У��"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/dingtao/dt_dongxiaodao.c",

"south":"/a/dingtao/dt_nanxiaodao.c",

"north":"/a/dingtao/dt_junying.c",

"west":"/a/dingtao/dt_xixiaodao.c",
 ]));
}
