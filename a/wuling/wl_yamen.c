// this room is created by buzzer.c
// driver is 巴山夜雨
// created date is Sat May 28 19:25:26 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"衙门"+"%^RESET%^");
set_long("
    这里是武陵衙门,门右边放这一个大鼓,如果有人有冤情的时候
可以击鼓鸣冤。\n\n");
set_exits( ([
"north":"/a/wuling/wl_laoyu.c",

"south":"/a/wuling/wl_dadao1.c",
 ]));
}
