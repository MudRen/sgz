// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Fri Apr 29 12:57:54 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"客店"+"%^RESET%^");
set_long("
    这里是华阴村的客店，是为过路的旅人提供休息的地方，店里收
拾的还算干净，没有其他什么摆设，只是安放着人们休息所最需要的
东西——床。你可以放心地在这里睡上一觉，然后继续赶路。\n\n");
set_exits( ([
"east":"/a/huayin/nancunkou.c",
 ]));
set_objects( (["/sgdomain/obj/other/bed.c" : 1]) );
}
