// 街亭帅帐
// jt_dzh.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup(){
    set_area("jieting");
    set_light(50);
    set_brief(""+YEL+"帅帐"+NOR+"");
    set_long("   这里是街亭守军最高将领的办公之处，军帐的入口处有两个士兵
持枪守卫，桌案上堆积着要处理的书函。帐外嘶嘶马鸣，时有军士进
帐报告最新战情。\n\n");
    set_exits( ([
        "southwest" :  __DIR__+"jt_jying.c",
    ]) );
}




