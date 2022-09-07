//  西大街三
// ly_xdj3.c described by ljty 1.8.1998
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("ly_area");
    set_light(50);
    set_brief(""+YEL+"西大街"+NOR+"");
    set_long("    这里是西大街的尽头，向西便可到洛阳城的西大门了。远处传来
官兵的吆喝声，不言而知官兵正在那里盘问来来往往的行人。北边是一
间牛棚，不时有几声牛叫传来。南边是条小巷子，来来往往的人不少。
\n\n");
    set_exits( ([
        "west" :  __DIR__+"ly_xicm.c",
        "east" :  __DIR__+"ly_xdj2.c",
        "north" :  __DIR__+"ly_niup.c",
        "south" :  __DIR__+"ly_chengxx.c",
    ]) );
}
