// this room is created by buzzer.c
// driver is 巴山夜雨
// created date is Sat May 28 19:24:28 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"西门"+"%^RESET%^");
set_long("
    这里是武陵的西门,有两个官兵正守在门口,盘查过往商客。\n\n");
set_exits( ([
"east":"/a/wuling/wl_dadao1.c",
 ]));
}
