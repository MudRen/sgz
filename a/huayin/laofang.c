// this room is created by buzzer.c
// driver is �������
// created date is Fri Apr 29 10:46:25 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"�η�"+"%^RESET%^");
set_long("");
/*set_exits( ([
"east":"/a/huayin/cunzhangjia.c",
 ]));*/
set_objects( (["/sgdomain/prison/yuzu.c" : 1 ]) );
}
