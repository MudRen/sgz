// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sat May  7 14:28:39 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"牢狱"+"%^RESET%^");
set_long("
    这里是一间黑黝黝的牢狱，空气中充斥着一股腐臭，高高的铁窗
透进一丝阳光，几只大老鼠若无其事地在你身边穿来穿去。\n\n");
set_exits( ([
"east":"/a/longxi/lx_datang.c",
 ]));
}
