// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Fri May 27 15:25:21 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"南城门"+"%^RESET%^");
set_long("
    这里是江陵的南城门,高大城墙上写着诺大的
两个字「"+"%^MAGENTA%^"+"江陵"+"%^RESET%^"+"」。\n\n");
set_objects((["/sgdomain/modules/m_charnpc/guard.c":1]));
}
