// ��ͤ������
// jt_ysht.c
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup(){
    set_area("jieting");
    set_light(50);
    set_brief(""+YEL+"������"+NOR+"");
    set_long("   
\n\n");
    set_exits( ([
        "southeast" :  __DIR__+"jt_jying.c",
    ]) );
}


