// this room is created by buzzer.c
// driver is 巴山夜雨
// created date is Sat May 28 19:49:06 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"客栈"+"%^RESET%^");
set_long("
    这是一家价钱低廉的客栈，因为地方偏僻，房客很少。\n\n");
set_exits( ([
"north":"/a/wuling/wl_xiaolu1.c",

"south":"/a/wuling/wl_xiaochang.c",
 ]));
set_objects( (["/sgdomain/obj/other/bed.c" : 1]) );

}
