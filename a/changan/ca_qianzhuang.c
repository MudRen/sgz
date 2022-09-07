// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Tue May  3 19:52:01 2011
#include <mudlib.h>
#include <ansi.h>
inherit M_BANK;

void setup() {
set_area("changan");
set_light(50);
set_brief("%^YELLOW%^"+"钱庄"+"%^RESET%^");
set_long("
    这里是长安城的钱庄，门口写着一个招牌“宝丰隆”，钱庄老板
正对着帐本打着算盘。在这可以兑换金银存钱取钱。门口贴着一张
钱庄的告示(sign)\n\n");
set_exits( ([
"west":"/a/changan/ca_yongchangjie3.c",
 ]));
set_objects( (["/sgdomain/obj/other/sign.c" : 1]) );
}
