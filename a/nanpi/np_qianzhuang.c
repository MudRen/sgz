// this room is created by buzzer.c
// driver is 巴山夜雨
// created date is Mon May 30 19:22:53 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit M_BANK;
void setup() {
set_area("nanpi");
set_light(50);
set_brief("%^YELLOW%^"+"钱庄"+"%^RESET%^");
set_long("
    这里是南皮的钱庄，门口写着一个招牌“正德银号”，钱庄老板
正对着帐本打着算盘。在这可以兑换金银存钱取钱。门口贴着一张
钱庄的告示(sign)\n\n");
set_exits( ([
"west":"/a/nanpi/np_huashi.c",
 ]));
set_objects( (["/sgdomain/obj/other/sign.c" : 1]) );
}
