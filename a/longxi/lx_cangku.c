// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sat May  7 12:15:25 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"仓库"+"%^RESET%^");
set_long("
    这是陇西仓库，右边放着一堆堆兵器，有刀枪剑戟。
左边堆一排排的盔甲。东面门口守着两个陇西官兵。一个小官左手
拿着账本，右手拿着笔，在本子上纪录数字。\n\n");
set_exits( ([
"east":"/a/longxi/lx_dounanjie1.c",
 ]));
}
