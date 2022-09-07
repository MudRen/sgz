// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Fri Apr 29 10:44:55 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"村长家"+"%^RESET%^");
set_long("
    这是一间简朴的木屋，室内非常宽敞，简单地摆置着一张大大的
木桌和几条板凳，两面的墙上挂着几幅画，虽不是出自名人手笔，但
也比较耐看。这里便是华阴村村长平时待的地方，村里的官员们有了
要紧的事也总是到这里来商量。\n\n");
set_exits( ([
"west":"/a/huayin/laofang.c",

"east":"/a/huayin/laohuaishu.c",
 ]));
//set_objects( (["/sgdomain/modules/m_board.c" : 1]) );
set_objects(([M_BOARD : ({ 1,"墙上有一张华阴官员专用的 "+"%^MAGENTA%^"+"华阴留言榜"+"%^RESET%^", "city.didao" }) ]) );
}
