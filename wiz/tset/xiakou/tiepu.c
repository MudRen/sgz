//  tiepu.c
//  夏口铁铺
//  created by tset 1/23/98
//  last updated by tset 1/23/98

#include <mudlib.h>

inherit INDOOR_ROOM;
inherit "/sgdomain/modules/m_store.c";

void setup(){
        set_area("xiakou");
        set_light(20);
        set_brief("铁铺");
        set_long("
铁铺里工匠正满头大汗地打制兵器。四周墙角放了好些已经打造完
毕的铁器。工匠见你进来，急忙道：“小人正忙，客官请自己慢慢
看(list)吧。”
\n\n");

  set_exits( ([
        "west" : __DIR__"xiakous"
                ]) );
                
  add_object( __DIR__"obj/jia.c" );
}
 
