//  �Ƶ� jiud.c
// made by benben
// cl_jiud.c 
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
    set_area("caolu_area");
    set_light(50);
    set_brief(""+YEL+"���Ƶ�"+NOR+"");
    set_long("    �Ƶ������˶����������İ��泤�룬����ӱ��ʯ��Ԫ����������
���ò�����������Ϲ��������˶��ǿ��������ѣ������Ƿÿ�;�У�����ЪϢ�ɡ�\n\n");
    set_exits( ([
        "south" :  __DIR__+"cl_road4.c",
    ]) );
// set_objects( ([ "/wiz/benben/NPC/shi.c" : 1 ]) );^M
// set_objects( ([ "/wiz/benben/NPC/meng.c" : 1 ]) );^M
}
