// 洞房,marry_fang.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit ROOM;
void setup(){
    set_light(1);
    set_brief(""+HIR+"洞房"+NOR+"");
    set_long("
    这里就是洞房了。艳艳的花烛静静的燃着，不时爆出一个个灯
花。铺着红桌布的圆桌上摆着一壶酒，两个小酒杯。挂着红帏帐的
大床上是整整齐齐的被褥。整个房间弥漫着一种醉人的春意。
\n\n");
    set_exits( ([
        "out" : __DIR__+"marry_tang.c",
    ]) );
   set_objects( ([
   "/wiz/ice/obj/furniture/hmbed.c":1,
]) );

}
