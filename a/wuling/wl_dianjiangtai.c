// this room is created by buzzer.c
// driver is 巴山夜雨
// created date is Sat May 28 19:46:46 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"点将台"+"%^RESET%^");
set_long("
    这里是武陵的点将台,相传姜太公在这里点过将。\n\n");
set_exits( ([
"north":"/a/wuling/wl_cunzhongxin.c",
 ]));
}
