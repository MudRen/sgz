// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Fri Apr 29 10:51:55 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"磨坊"+"%^RESET%^");
set_long("
    这是一间相当陈旧的磨坊，磨坊中间有一只沉重的石磨，看样子
拉磨的驴再也找不回来了，只有靠自己来推磨了，你不由想起了那句
有钱能使。。。的俗话。\n\n");
set_exits( ([
"east":"/a/huayin/lukou.c",
 ]));
set_objects( (["/sgdomain/job/choppork/zth.c" : 1]) );
}
