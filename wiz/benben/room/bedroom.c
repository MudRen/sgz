#include <mudlib.h>
#include <sanguo.h>
inherit ROOM;
void setup(){
    set_area("my_home");
    set_light(50);
    set_brief("--小东西的卧室--");
    set_long(
"		这是可怜的小东西想象中的房间

一个暖色调的大房间，光滑的原木地板，房间里的摆设不多不少，
看起来很朴素，小东西好象是个环保主义者？\n\n一幅达芬奇的名画(monalisa)\n\n");
    set_exits( ([
        "out" :  FROOMPATH+"vzhu_lin.c"
	    ]) );
    add_item("monalisa" , "一幅达芬奇的名画",
        (["look" : "\n\n这是达芬奇的名画《蒙娜丽沙》，蒙胧的色调和房间的气氛正好相
配，不过这最多是印刷品罢了，按小东西的财力，也就只能买个赝
品附庸风雅了。 :( 
\n\n",
	  "get" : "怎么着，想偷东西呀？",
        ]));
}                             
