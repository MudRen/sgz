// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Fri Apr 29 12:50:06 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"厨房"+"%^RESET%^");
set_long("
    一跨进这间屋子，你就闻到了一股油烟味儿，直冲鼻子，看样子
这里是间厨房。靠墙用泥巴糊起了一只大灶，灶头上凌乱地放着些葱
姜什么的。灶角则堆放着些柴火，是用来生火的。你看到一位厨娘正
忙前忙后，烧饭做菜。\n\n");
set_exits( ([
"north":"/a/huayin/qianting.c",
 ]));
set_objects( (["/sgdomain/job/chopwoods/chuniang.c" : 1]) );
}
