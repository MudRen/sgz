#include <mudlib.h>
#include <ansi.h>
#include <sanguo.h>

inherit ROOM;

void setup()
{
    set_area("lcm_room");
    set_light(50);
    set_brief(""+HIB+"��ά"+NOR+"�ļ�");
    set_long(
"\n��ά�Ǹ��򵥵��ˡ�����Ҳû��ʲôװ�ã�
ֻһ�����������ӡ�\n
���Ϸ��������飬һ����"+HIY+"���������塱"+
NOR+"����һ����"+HIY+"��ˮ䰴���"+NOR+"��");
    set_exits( (["out" : FROOMPATH+"vzhu_lin.c", 
                 "up" : "/wiz/liz/workroom.c",
                 "down" : "/wiz/lcm/bagua33.c",
                 ]) );              
}
