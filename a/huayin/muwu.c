// this room is created by buzzer.c
// driver is �������
// created date is Fri Apr 29 11:00:01 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"ľ��"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/huayin/zhulin.c",
 ]));
}
