// this room is created by buzzer.c
// driver is �������
// created date is Thu Jul 28 19:14:15 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("xiangyang");
set_light(50);
set_brief("%^YELLOW%^"+"��ؽ�"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/xiangyang/xy_tianchijie2.c",

"east":"/a/xiangyang/xy_dangpu.c",

"west":"/a/xiangyang/xy_qianzhuang.c",

"south":"/a/xiangyang/xy_chengzhongxin.c",
 ]));
}
