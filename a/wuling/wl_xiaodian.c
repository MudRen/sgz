// this room is created by buzzer.c
// driver is 巴山夜雨
// created date is Sat May 28 20:03:10 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit M_BANK;

void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"小店"+"%^RESET%^");
set_long("
    这里是三国志里全国连锁“"+"%^MAGENTA%^"+"汇通号"+"%^RESET%^"+"”钱庄武陵分店，由于
是独家垄断，生意很火热，高高的柜台后面堆满了一箱箱的白银，
几个伙计忙着把银箱抬到后院。几个机灵的伙计在前面招待客人，
墙上贴着一张告示“转账和取钱收取手续费百分之十”。\n\n");

set_exits( ([
"west":"/a/wuling/wl_xiaolu2.c",
 ]));
set_objects( (["/sgdomain/obj/other/sign.c" : 1]) );
}
