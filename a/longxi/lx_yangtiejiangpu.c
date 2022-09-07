// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sat May  7 14:44:59 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
inherit STORE;

void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"杨铁匠铺"+"%^RESET%^");
set_long("
    杨铁匠正在吭哧吭哧打一把烧红了的剑呢，伙计在一旁拉着风箱，
右边的墙上挂着各式各样的刀剑，其中不乏质量上乘的货品。用list
指令看兵器的价格，buy指令购买。\n\n");
set_exits( ([
"south":"/a/longxi/lx_xiaoxiang1.c",
 ]));
add_object("/sgdomain/obj/weapon/blade/dandao.c");
add_object("/sgdomain/obj/weapon/blade/gangdao.c");
add_object("/sgdomain/obj/weapon/ji/changji.c");
add_object("/sgdomain/obj/weapon/sword/changjian.c");
add_object("/sgdomain/obj/weapon/sword/gangjian.c");
}
