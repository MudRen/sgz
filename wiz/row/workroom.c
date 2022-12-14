//  城中心
// ly_czx.c 
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;

void setup(){
	set_area("luoyang");
	set_light(50);
        set_brief(""+YEL+"洛神国"+NOR+"");
	set_long("
    这里便是洛阳城的中心，四条大街交汇于此。一座巍峨高大的钟
楼耸立于前，很是有些气势。每到清晨，响亮的钟声便会伴着淡淡雾
气传向洛阳的大街小巷。路口车水马龙，来往人潮不断。虽说当年董
卓火烧洛阳城，但经过百姓的努力重建，昔日的繁华似乎又回来了。\n\n");

	set_room_state("valid_start");
	set_exits( ([
	"east" :  __DIR__+"ly_ddj1.c",
	"west" :  __DIR__+"ly_xdj1.c",
	"south" : __DIR__+"ly_ndj1.c",
	"north" : __DIR__+"ly_bdj1.c"
	]) );
    set_objects(([ "/wiz/row/guard/guard1" : ({ "stock-mage" }) ]));
//        set_objects(([M_BOARD : ({ 1,"洛阳留言板", "luoyang" }) ]) );
}
