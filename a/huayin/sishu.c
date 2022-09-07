// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Fri Apr 29 12:12:54 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"村私塾"+"%^RESET%^");
set_long("
    一间不大不小的草房，看起来破旧不堪。屋内摆着几张矮小的木
桌和板凳，几个小孩童趴在上面。有的在『呓呓呀呀』地念书，有的
则三三两两在一起互相打闹。一边的椅子上坐着个瘦瘦的老头，看打
扮象个书生的样子，似乎对一切都漠不关心，只是盯着手中拿的一本
发黄的破书。\n\n");
set_exits( ([
"east":"/a/huayin/xiaoxiang.c",
 ]));
set_objects( (["/sgdomain/npc/kongyiji.c" : 1]) );
}
