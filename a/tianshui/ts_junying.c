// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sun May  8 21:16:59 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("tianshui");
set_light(50);
set_brief("%^YELLOW%^"+"军营"+"%^RESET%^");
set_long("
    这里是天水的驻军大营。这里几乎都是官兵，一队官兵正在那里操
练，傍边有一个军官摸样的在那里指手画脚，好象是官军的头子。\n\n");
set_exits( ([
"north":"/a/tianshui/ts_yishiting.c",

"south":"/a/tianshui/ts_xidajie.c",

"east":"/a/tianshui/ts_beidajie.c",
 ]));
}
