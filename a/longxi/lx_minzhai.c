// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sat May  7 14:44:17 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"民宅"+"%^RESET%^");
set_long("
    这是一间十分简陋，四壁漏风的小房子，屋子里连一张象样的床都没
有，只有一面门板上面铺着些干草。这屋子的主人一定是贫困潦倒，穷的
叮当响。\n\n");
set_exits( ([
"south":"/a/longxi/lx_xiaoxiang2.c",
 ]));
}
