// 街亭校军场 
// jt_xjc.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("jieting");
    set_light(50);
    set_brief(""+YEL+"街亭校军场"+NOR+"");
    set_long(" 街亭虽小，却干系甚重，是蜀魏相通的咽喉要道，历为兵家必争之
处。在一大片空地上，几队士兵正在操练。这里是街亭的校军场。
平时练兵，检阅和集合都在这里。东边是驻兵屯粮的地方。南边就
是密密麻麻的驻军帐篷。\n\n");
    set_exits( ([
        "north" :  __DIR__+"jt_jying.c",
        "east" :  __DIR__+"jt_lcao.c",
    ]) );
}


