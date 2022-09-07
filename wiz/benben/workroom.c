#include <mudlib.h>
#include <sanguo.h>
inherit ROOM;
void setup(){
    set_area("xbv_area");
    set_light(50);
    set_brief("--小东西的家--");
    set_long(
"小东西是租了人家的房子住的，自己买不起房，只好租一个。�
房间不大？看起来很简单，还好不算简陋。一张床，一个梳妆�
台，一个写字桌，还有一个茶几。屋子里有些凌乱？看来小东
西不太会收拾。\n\n窗户(window)\n\n");
    set_exits( ([
  "kitchen" : __DIR__+"room/kitchen.c",
        "bedroom" :  __DIR__+"room/bedroom.c",
        "out" :  FROOMPATH+"vzhu_lin.c"
    ]) );
    add_item("window" , "一扇向南的窗户",
        (["look" : "\n\n南面本来是大海？可是这么多高楼
把什么都遮住了。 :( \n\n"
        ]));
}                             
