// this room is created by buzzer.c
// driver is �������
// created date is Fri Apr 29 10:59:21 2011
#include <mudlib.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"����"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/huayin/muwu.c",

"west":"/a/huayin/daguchang.c",
 ]));
set_objects( (["/sgdomain/job/chopwoods/woods.c" : 1]) );

}
