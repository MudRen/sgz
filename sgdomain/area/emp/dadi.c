//by ljty.
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup(){   
	set_light(50);
   set_brief(""+YEL+"金銮殿"+NOR+"");
   set_long("
    大殿内上下灯火辉煌，八名侍卫钉子似地站在周围。殿内各按
方位点燃着六十四根碗口粗的金龙盘绕的红烛，十二名太监垂手恭
侍在金碧交辉的御座前。你不自禁的觉得一阵腿软，大气也不敢喘
一下，悄悄地站在一旁。
\n");
   set_exits( ([
             "goout" : __DIR__+"hugo.c",  
          "west" : __DIR__+"cl1",
            "east" : __DIR__+"cl4",
      "north" :"/wiz/row/rooms/wdd.c",

	]) );	
	set_objects( ([        "/sgdomain/event/ev_king/king.c" : 1,]));
set_enter_msg("dadian","$N战战兢兢地走进了大殿，两脚一软，「噗通」一下跪在了地上。\n\n");
    set_exit_msg("goout","\n$N战战兢兢地低头向后慢慢地挪动着退出了大殿，这才送了一口气。\n\n");
}
