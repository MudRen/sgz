#include <mudlib.h>
#include <ansi.h>
#define BW_MASTER __DIR__"master.c"

inherit OUTDOOR_ROOM;

void setup(){
        set_light(50);
        set_brief(""+YEL+"武将争霸大会"+NOR+"");
	set_long("    这儿就是武将争霸的报名处，场地的中间站着一位神采奕奕的老
者(master)，如果你有意于天下的英雄一试高下，可以向他要求报名
(ask master about join)。");
	set("no_fight", 1);
	set_objects(([
		BW_MASTER:1,
]));
}

