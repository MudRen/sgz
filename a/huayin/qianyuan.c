// this room is created by buzzer.c
// driver is �������
// created date is Fri Apr 29 12:17:00 2011
#include <mudlib.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"ǰԺ"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/huayin/qianting.c",

"west":"/a/huayin/xiaoxiang.c",
 ]));
}
