//  ��վ by benben
// xy_yzh.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("xianyang");
    set_light(50);
    set_brief(""+YEL+"��վ"+NOR+"");
    set_long("    ������\n");
    set_exits( ([
        "north" :  __DIR__+"xy_est2.c",
    ]) );
 set_objects( ([
      "wiz/flee/misc/mafu.c" : 1,
]) );
}
