// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sat May  7 12:16:59 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"点心铺"+"%^RESET%^");
set_long("
    这里是陇西远近闻名的点心铺,门口排这长龙,一个店小二拿着一个牌子
“点心已售空，暂停营业”挂在门柱上。\n\n");
set_exits( ([
"east":"/a/longxi/lx_dounanjie2.c",
 ]));
}
