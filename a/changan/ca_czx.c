// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Tue May  3 19:27:17 2011
#include <mudlib.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;

void setup() {
set_area("changan");
set_light(50);
set_brief("%^YELLOW%^"+"城中心"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/changan/ca_nandajie.c",

"west":"/a/changan/ca_xdj1.c",

"east":"/a/changan/ca_dongdajie1",

 ]));
        set_objects( ([        "sgdomain/event/ev_king/kingguard.c" : 1,]));
set_objects(([M_BOARD : ({ 1,"这里是长安的中心广场。广场尽头就是气势恢弘的皇宫大殿。\n\n一个木板做的"+"%^MAGENTA%^"+"长安留言榜"+"%^RESET%^", "city.changan" }) ]) );
}
