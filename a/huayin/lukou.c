// this room is created by buzzer.c
// driver is �������
// created date is Fri Apr 29 10:12:03 2011
#include <mudlib.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"·��"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/huayin/daguchang.c",

"west":"/a/huayin/mofang.c",

"north":"/a/huayin/laohuaishu.c",

"south":"/a/huayin/cunzhongxin.c",
 ]));
}
