#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>

inherit INDOOR_ROOM;
void setup(){
    set_area("xbv_area");
    set_light(50);
set_brief(""+HIR+"--浪迹天涯的厨房--"+NOR+"");
    set_long(
"    哇，好大的厨房。看看冰箱里都有什么？看来浪迹天涯
很少做饭。方便面袋子到处都是，单身汉的日子是不好过。
\n冰箱(bingxiang)\n");
    set_exits( ([
             "out" : "/wiz/ljty/workroom.c",
   ]) );
  set_objects(([
    "/wiz/ljty/obj/foodgui.c" : 1
    ]) );
    add_item("bingxiang", "冰箱",
            (["open" : "\n里面一无所有，失望了吧。\n\n",
              "look" : "\n好大的冰箱，打开看看有没有很吃的\n\n",
           ]) );
}
