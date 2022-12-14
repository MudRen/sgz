// 街亭小道 modified by row
// jt_xd1.c

#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;

void setup(){
	set_area("jieting");
	set_light(50);
	set_brief(""+YEL+"小道"+NOR+"");
	set_long("
    一条弯曲的小道，延伸至此。向西南方向望去，隐约可以看到一
条大路，那是通往天水的必经之路，而过了天水，便可以入川了。而
西面靠北则有一座小山，山下驻扎着一座营寨，旌旗飘扬，那里便是
军事要地『街亭』。\n\n");
	set_exits( ([
	"east" :  __DIR__+"jt_yz.c",
"southwest" : __DIR__+"jt_yizhan.c",
	"north" : __DIR__+"jt_sl.c",
	]) );
}
