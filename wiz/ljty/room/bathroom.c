#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>

inherit INDOOR_ROOM;
void setup(){
    set_area("xbv_area");
    set_light(50);
    set_brief(""+HIR+"--浪迹天涯的卫生间--"+NOR+"");
    set_long(
"    浪迹天涯的卫生间挺整洁的。这小子太懒，不洗澡自然也就弄
不脏。浴盆倒不小，看来他还是挺懂享受的。
\n");
    set_exits( ([
             "out" : "/wiz/ljty/workroom.c",
   ]) );
}
