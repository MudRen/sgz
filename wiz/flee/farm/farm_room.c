#include <ansi.h>
#define FARMER __DIR__"farmer.c"
#define SOIL   __DIR__"soil.c"

inherit OUTDOOR_ROOM;

void setup(){
        set_light(50);
	set_area("changan");
        set_brief("一片"+HIG+"绿油油"+NOR+"的农田");
        set_long(@LONG
    一片绿油油的农田，放眼望去是看不到边际的庄稼。农夫
们正辛勤的劳作着，期望今年有个好收成。
LONG);
	set_objects(([
		FARMER:1,
		SOIL  :1,
]));
        set("no_fight", 1);
}
