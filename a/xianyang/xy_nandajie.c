// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sat May 28 11:38:52 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("xianyang");
set_light(50);
set_brief("%^YELLOW%^"+"�ϴ��"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/xianyang/xy_nanchengxiang.c",

"west":"/a/xianyang/xy_machang.c",

"east":"/a/xianyang/xy_jiuguan.c",

"north":"/a/xianyang/xy_chengzhongxin.c",
 ]));
}
