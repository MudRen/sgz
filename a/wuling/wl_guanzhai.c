// this room is created by buzzer.c
// driver is 巴山夜雨
// created date is Sat May 28 19:33:34 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"官宅"+"%^RESET%^");
set_long("
    这是武陵的官宅，内部摆设极尽豪华，当中一张黑色檀木
条案，上面陈放着精美的花瓶和一些珍贵的瓷器，四壁挂满名
家的字画。\n\n");
set_exits( ([
"east":"/a/wuling/wl_suishilu1.c",
 ]));
}
