// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <size.h>
inherit ROOM;

void setup()
{
    set_area("pirate");
    set_brief("矮洞");
    set_long(
      "你必须手脚并用才能爬过这个通道，即使这样，你的背部还是与洞顶"
      "紧贴，碎石在你的身边不断落下，这使得移动很困难。洞的北面略宽"
      "，而南方则有一股咸湿的风吹在你的脸上。");
    set_light(0);
    set_exits( ([
      "south" : "/domains/std/rooms/caves/grotto.c",
   "north" : "/domains/std/rooms/caves/inside_cave.c",
    ]) );
    set_default_exit( "这个方向没有出口。\n");

    add_item( "crawl", "low crawl" , "通道", "矮洞", 
              "你转过头去，想四下里看看，不料有更多的碎石落下，你赶忙闭上了眼。");

    add_item( "ceiling" , "洞顶", "这里根本没有你抬头向上看的空间。");

    add_item( "rock", "rocks", "gravel", "rocks and gravel", "碎石", 
              ([ "look" : "碎石从上方落下，堆积在地上，使得地面起伏不平。",
                 "get" : "它们太碎小了，恐怕没有什么用处。" 
               ]));

    set_max_capacity(VERY_LARGE+3*MEDIUM); // A person + 3 medium items
}



