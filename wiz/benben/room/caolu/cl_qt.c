//  Ç°Ìü
// cl_qt.c by by benben
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("caolu_area");
    set_light(50);
    set_brief(""+YEL+"Ç°Ìü"+NOR+"");
    set_long("Çë¼ÓÃèÊö¡£\n\n");
    set_exits( ([
        "north" :  __DIR__+"cl_zht.c",
        "south" :  __DIR__+"cl_mdoor.c",
    ]) );
}
