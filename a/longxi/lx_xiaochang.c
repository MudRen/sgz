// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sat May  7 13:53:37 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"校场"+"%^RESET%^");
set_long("
    这是陇西校场，平时军士们就在这里操练，地上很平整，
居中是指挥台，有根长达数丈的旗杆，杆顶一面绣着一条红龙的西凉铁骑
营白色军旗迎风猎猎作响。平时军士们一天三练，早上出操，中午出
城练马术和野战，晚上则负责陇西城外的巡逻。\n\n");
set_exits( ([
"north":"/a/longxi/lx_junying.c",
 ]));
}
