// this room is created by buzzer.c
// driver is 巴山夜雨
// created date is Sat May 28 19:27:46 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"大道"+"%^RESET%^");
set_long("
    这里是大道,东面通向村中心,南面有条小巷,北面
是武陵的议事厅,几位官员正向那里走去。\n\n");
set_exits( ([
"east":"/a/wuling/wl_cunzhongxin.c",

"south":"/a/wuling/wl_xiaoxiang.c",

"west":"/a/wuling/wl_dadao1.c",

"north":"/a/wuling/wl_yishiting.c",
 ]));
}
