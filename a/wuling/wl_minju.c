// this room is created by buzzer.c
// driver is 巴山夜雨
// created date is Sat May 28 19:40:58 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"民居"+"%^RESET%^");
set_long("
    里面破破烂烂的，丢满了各种杂物。\n\n");
set_exits( ([
"east":"/a/wuling/wl_nanjie1.c",
 ]));
}
