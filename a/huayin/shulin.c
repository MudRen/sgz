// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Thu Apr 28 23:27:20 2011
#include <mudlib.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"树林"+"%^RESET%^");
set_long("
    眼前是一片树林，也不知是谁在多少年前种的，不过现在看来野
生野长的相当茂盛。平时东面小村里的村民会到这里来砍些柴火回去
烧火作饭，不过多数时候这里都是静悄悄的，只能听到那些不知名的
小鸟在『啾啾』地唱。\n\n");
set_exits( ([
"east":"/a/huayin/xiaolu.c",
 ]));
set_objects( (["/sgdomain/job/chopwoods/woods.c" : 1]) );
}
