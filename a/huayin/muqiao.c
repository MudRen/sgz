// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Fri Apr 29 12:58:52 2011
#include <mudlib.h>
#include <ansi.h>
#include <sanguo.h>
inherit INDOOR_ROOM;
inherit M_BLOCKEXITS;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"木桥"+"%^RESET%^");
set_long("
    这是一座窄窄的木桥，看上去似乎刚造不久，要不然走上去还真
有点心惊胆战呢。从桥上往下看，是一条清清的小河，水静静地流淌
着，清澈无比，你还可以看到有许多鱼儿在水底嬉戏。\n\n");
set_objects((["/sgdomain/modules/m_charnpc/guard.c":1]));
}
