// 狄道悬崖山腰
// dd_xy.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;

void setup(){
    set_area("didao");
    set_light(50);
    set_brief(""+YEL+"山腰"+NOR+"");
    set_long(
@LONG 
  半面崖壁上血红大字

                   狄道

	       必死万人于此
	        	
LONG
);
    set_exits( ([
	"west"      :  __DIR__+"dd_xy.c",
    ]) );
}


