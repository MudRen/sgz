//by ljty.
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>

inherit ROOM;

void setup()
{
   set_light(50);
   set_brief(""+YEL+"皇宫"+NOR+"");
   set_long("    这里是皇宫。无数嫔妃从你面前走过，使你不禁惊叹世上竟然
还有如此美丽的人。向北是皇宫大殿。\n\n");
   set_exits( ([
	     "north" : __DIR__+"dadi.c",
	     "south" : "/sgdomain/area/cities/changan/ca_bcm.c"
	]) );
}
