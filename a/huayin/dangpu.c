// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Fri Apr 29 10:58:05 2011
#include <mudlib.h>
#include <ansi.h>
inherit M_DANGPU;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"当铺"+"%^RESET%^");
set_long("
    这是华阴村的当铺，和其他地方的当铺一样，一进门就可以看到
那独特的一人高的柜台，你必须掂起脚才能将东西送上去。由于连年
战乱，老百姓的日子越来越苦，所以进出当铺的人也多了起来，以至
于门槛都被踏破了。你可以看见在一旁的墙上有一张告示(gaoshi)。\n\n");
set_exits( ([
"south":"/a/huayin/daguchang.c",
 ]));
set_objects( (["/sgdomain/obj/other/gaoshi.c" : 1]) );
}
