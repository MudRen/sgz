//by ljty.
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>

inherit ROOM;

void setup()
{
   set_area("changan");
   set_light(50);
   set_brief(""+YEL+"后宫"+NOR+"");
   set_long("    这里是后宫。无数嫔妃从你面前走过，使你不禁惊叹世上竟然
还有如此美丽的人。向北是皇宫大殿，东面是内宫御花园。\n\n");
   set_room_state("valid_start");
   set_exits( ([
             "east"  : __DIR__+"ca_yhy.c",
	     "south" : __DIR__+"ca_dd.c",
	     "west" : __DIR__+"ca_qg.c",	
	]) );
}
