// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Mon May  9 09:19:58 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"兵营"+"%^RESET%^");
set_long("
    这是江陵军营,里面有三二个小兵赌博聊天,东门是
瑞平路,西面是帅帐.有很多人围在贴有榜文的地方高谈阔论。\n\n");
set_exits( ([
"west":"/a/jiangling/jl_shuaizhang.c",

"east":"/a/jiangling/jl_ruipinglu2.c",
 ]));
set_objects(([M_BOARD : ({ 1,"一个精致的"+"%^MAGENTA%^"+"江陵留言榜"+"%^RESET%^", "city.jiangling" }) ]) );
}
