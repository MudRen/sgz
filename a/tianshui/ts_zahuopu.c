// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sun May  8 21:16:19 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("tianshui");
set_light(50);
set_brief("%^YELLOW%^"+"杂货铺"+"%^RESET%^");
set_long("
    这里是天水杂货铺,每天人来人往，也挺热闹。这里无论是油盐酱醋，
还是大米白面，各种日常用品也是样样齐全。中间一张柜台，店主人正坐在
柜台后面算帐。据说私底下他也卖一些贵重的东西。\n\n");
set_exits( ([
"north":"/a/tianshui/ts_xidajie.c",
 ]));
}
