//  С��5 road5.c
// made by benben
// cl_road5.c 
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("caolu_area");
    set_light(50);
    set_brief(""+YEL+"С��"+NOR+"");
    set_long("    ��ɽ���������ˣ������ס�ӿ��˽Ų���\n\n");
    set_exits( ([
        "west" :  __DIR__+"cl_road6.c",
        "east" :  __DIR__+"cl_road4.c",
    ]) );
set_objects( ([ "/wiz/benben/NPC/farmer.c" : 1 ]) );
}
