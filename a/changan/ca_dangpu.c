// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Tue May  3 19:50:03 2011
#include <mudlib.h>
#include <ansi.h>
inherit M_DANGPU;

void setup() {
set_area("changan");
set_light(50);
set_brief("%^YELLOW%^"+"当铺"+"%^RESET%^");
set_long("
    这里是长安城的当铺，门口的招牌上写着一个很大的当字。
一进门就可以看到很独特有一人高的柜台。里面坐着一位慈祥
的戴着眼镜的老先生。你可以在店里一边的墙上看见一张醒目
的告示(gaoshi)\n\n");
set_exits( ([
"east":"/a/changan/ca_ycj2.c",
 ]));
set_objects( (["/sgdomain/obj/other/gaoshi.c" : 1]) );
}
