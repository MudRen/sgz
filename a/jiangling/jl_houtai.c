// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Mon May  9 10:08:12 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"后台"+"%^RESET%^");
set_long("
    这里是戏棚的后台,有几个戏子正在化装,准备登台演出,
墙上挂这各种各样的戏服。从北边可以上台。\n\n");
set_exits( ([
"north":"/a/jiangling/jl_xipeng.c",
 ]));
}
