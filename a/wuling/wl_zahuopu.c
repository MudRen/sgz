// this room is created by buzzer.c
// driver is 巴山夜雨
// created date is Sat May 28 19:38:30 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"杂货铺"+"%^RESET%^");
set_long("
    这是一家杂货铺，大箱小箱堆满了一地，都是一些日常
用品。胡掌柜懒洋洋地躺在一只躺椅上，招呼着过往行人。
据说私底下他也卖一些贵重的东西。\n\n");
set_exits( ([
"west":"/a/wuling/wl_suishilu3.c",
 ]));
}
