// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sun May  8 21:43:49 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("tianshui");
set_light(50);
set_brief("%^YELLOW%^"+"客栈"+"%^RESET%^");
set_long("
    这是天水城一家普通的客栈，由于靠近城中心，生意非常兴隆。外地游客
多选择这里落脚，店小二里里外外忙得团团转，接待着南腔北调的客人。\n\n");
set_exits( ([
"west":"/a/tianshui/ts_nandajie1.c",
 ]));
set_objects( (["/sgdomain/obj/other/bed.c" : 1]) );
}
