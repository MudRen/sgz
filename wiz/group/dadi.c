//by ljty.
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>

inherit INDOOR_ROOM;

void setup()
{
   set_area("changan");
   set_light(50);
   set_brief(""+YEL+"金銮殿"+NOR+"");
   set_long("    这就是皇帝的金銮殿，的确金壁辉煌，让人目不暇接，周围的
人都目不斜视，你不自禁的觉得一阵腿软，使你大气也不敢出一声，
悄悄的站在一旁。\n\n");

   set_exits( ([
	     "south" : __DIR__+"hugo.c",
	]) );
	set_objects( ([
        "/sgdomain/event/ev_king/king.c" : 1,
]));	
}
