//  温德殿
// ly_czx.c 
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit INDOOR_ROOM;

void setup(){
	set_light(50);
      set_brief("%^B_WHITE%^%^H_YELLOW%^温德殿%^RESET%^");
	set_long("
    这个殿相比金銮殿丝毫不逊色，是汉献帝用来诏见显贵客人的地
方。巨大的环龙柱拔地而起，厚重的幔帘从穹顶洒将下来，增添了肃
穆的气氛。殿内四季点着熏香，淡淡的香味令人陶醉，还真有点向往
宫廷的生活。一年一度，汉献帝都要在此聚四方诸侯，商讨重大的事
务，不过，对于一个别人只当作傀儡的皇帝来说，他说的话又有谁会
真正在意呢？\n\n");
	set_exits( ([
	"south" :"/sgdomain/area/emp/dadi.c",
	]) );
}
