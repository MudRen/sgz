// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sat May  7 14:35:49 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"相馆"+"%^RESET%^");
set_long("
    这里是陇西相士馆,一个老相士闭目养神的坐在木桌后,旁边墙靠个
面旗子写着大大的“相”字。路上行人自顾自己的走来去，好像没有人看
见老相士似的。\n\n");
set_exits( ([
"west":"/a/longxi/lx_beichenjie2.c",
 ]));
}
