// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Fri Apr 29 12:50:30 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"后堂"+"%^RESET%^");
set_long("
    这个厅便是后堂了，不算很大，但布置得非常齐整而又精致，也
许是因为张小姐的闺房就在楼上的缘故。靠着墙依着一张水柳木的方
桌，上面摆着一套茶具，桌子边上是两张高背木椅。椅子旁安着只小
巧的木几，上面是一只细瓷花瓶。你可以看到一边有楼梯通向二楼。\n\n");
set_exits( ([
"north":"/a/huayin/guifang.c",

"west":"/a/huayin/qianting.c",
 ]));
set_objects( (["/sgdomain/npc/zyuanwai.c" : 1]) );
}
