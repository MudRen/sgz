//  ��վ by benben
// lx_yzh.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit ROOM;
void setup(){
    set_area("longxi");
    set_light(50);
    set_brief(""+YEL+"--��վ--"+NOR+"");
    set_long("    ������\n");
    set_exits( ([
        "west" :  __DIR__+"lx_dnst1.c",
    ]) );
 set_objects( ([
      "wiz/flee/misc/mafu.c" : 1,
]) );
}
