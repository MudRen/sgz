// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Thu Apr 28 23:17:04 2011
#include <mudlib.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"小村中心"+"%^RESET%^");
set_long("
    这是小村的中心，往北一直走有一片农田，而向南可以发现一条
小河。西面是一条小路，而东边则是一位智者的居所，平时村民们有
什么紧要的事都会找他商议。\n\n");
set_exits( ([
"south":"/a/huayin/xiaoxiang.c",

"north":"/a/huayin/lukou.c",

"west":"/a/huayin/xiaolu.c",

"east":"/a/huayin/vhall.c",
 ]));
}
