// this room is created by buzzer.c
// driver is 巴山夜雨
// created date is Sat May 28 19:48:06 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"校场"+"%^RESET%^");
set_long("
    这里是武陵校场,一排排官兵正在校场上操练,喊杀震天。\n\n");
set_exits( ([
"north":"/a/wuling/wl_kezhan.c",

"south":"/a/wuling/wl_cunzhongxin.c",
 ]));
}
