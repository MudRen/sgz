// this room is created by buzzer.c
// driver is �������
// created date is Fri Apr 29 10:15:53 2011
#include <mudlib.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"�ϻ���"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/huayin/citang.c",

"west":"/a/huayin/cunzhangjia.c",

"north":"/a/huayin/nongtian.c",

"south":"/a/huayin/lukou.c",
 ]));
}
