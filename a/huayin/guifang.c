// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Fri Apr 29 12:50:58 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"闺房"+"%^RESET%^");
set_long("
    一股香气，不可避免地钻入了你的鼻子，令你有些晕晕乎乎的感
觉。没错，这里便是主人的女儿——张小姐的闺房。四处的摆设都是
那么的精致，床上挂的是绣了花的帐子，一旁是一个雕着镂空图案的
梳妆台，从上面搁着的铜镜你似乎能看到自己的身影。待在这间房间
里，你不由得轻手轻脚起来。\n\n");
set_exits( ([
"south":"/a/huayin/houtang.c",
 ]));
}
