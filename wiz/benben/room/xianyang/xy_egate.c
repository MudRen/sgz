//  ������
// xy_egate.c 
#include <mudlib.h>
#include "/wiz/fire/fire.h"
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("xianyang");
    set_light(50);
    set_brief(""+YEL+"������"+NOR+"");
    set_long("�����š�ͨ��������\n\n");
    set_exits( ([
        "east" :  __DIR__+"?_?.c",
        "west" :  __DIR__+"xy_est2.c",
    ]) );
}
