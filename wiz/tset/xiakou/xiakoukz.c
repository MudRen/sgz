//  xiakoukz.c
//  夏口小客栈
//  created by tset 1/16/98
//  last updated by tset 1/19/98
 
#include <mudlib.h>

inherit INDOOR_ROOM;
inherit "/sgdomain/modules/m_store.c";

void setup(){
        set_area("xiakou");
        set_light(10);
        set_brief("小客栈");
        set_long("
小客栈里马老板一副没精打采的样子。里面看不到多少客人。墙边
有几个地铺，看来就是睡觉的地方了。西边出去就是夏口城北。南
边有个马槽。
\n\n");
                        
    set_exits( ([
        "south" : __DIR__"macao",
        "west"  : __DIR__"xiakoun",
                ]) );

    set_objects( ([
         __DIR__"npc/malaoban" : 1,
                ]) );

  add_object( __DIR__"obj/maliao.c");
  add_object( __DIR__"obj/jiudai.c");
  add_object( __DIR__"obj/mianbing.c");

  add_item("dipu", "地铺",
        (["look" : "一张简单的地铺，可以在上面睡觉。",
          "sleep" : "$N倒头往地铺上一躺，就开始呼呼大睡。"]) );

}

