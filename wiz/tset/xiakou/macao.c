//  macao.c
//  夏口马槽
//  created by tset 1/19/98
//  last updated by tset 1/19/98

#include <mudlib.h>

inherit OUTDOOR_ROOM;

void setup(){
        set_area("xiakou");
        set_light(10);
        set_brief("马槽");
        set_long("
这里是一间马槽。墙角边有一口水井，右边有几根木桩。北边是个
小客栈。
\n\n");

    set_exits( ([
        "north" : __DIR__"xiakoukz"
                ]) );

    set_objects( ([
        __DIR__"obj/well.c" : 1 ]) );

  add_item("wood", "木桩",
        (["look" : "几根木桩，是用来拴马的。"]) );

  add_item("piao", "水瓢",
        (["look" : "一个用来舀水的水瓢。"]) );
}

