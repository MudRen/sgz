// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Thu May 26 21:57:52 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"监狱"+"%^RESET%^");
set_long("
    这里是监狱,地上躺这个几个衣裳褴褛的囚犯,
旁边一个木桶里是馊了的米饭。\n\n");
set_exits( ([
"west":"/a/jiangling/jl_datang.c",
 ]));
}
