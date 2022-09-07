#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>

inherit INDOOR_ROOM;	

void setup(){
    set_area("xbv_area");
    set_light(50);
    set_brief(""+HIR+"--浪迹天涯的卧室--"+NOR+"");
    set_long(
"    浪迹天涯的卧室有点凌乱，谁让老婆还没到位。平常就在这张
双人床上休息一下或看看电视。\n\n");
  set_objects(([
    "/wiz/ljty/obj/ljtybed.c" : 1
    ]) );
    set_exits( ([
             "down" : "/wiz/ljty/workroom.c",
   ]) );
}
