// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sun May  8 21:41:43 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("tianshui");
set_light(50);
set_brief("%^YELLOW%^"+"衙门"+"%^RESET%^");
set_long("
    这里是陇西衙门，两扇朱木大门紧紧关闭着。“肃静”“回避”的
牌子分放两头石狮子的旁边。前面有一个大鼓，几名衙役站在门前。\n\n");
set_exits( ([
"west":"/a/tianshui/ts_datang.c",

"east":"/a/tianshui/ts_nandajie.c",
 ]));
}
