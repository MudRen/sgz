// farmer.c "ũ��"
#include <mudlib.h>
#include <sanguo.h>
inherit MONSTER;
void setup()
{
    set_name("caocao", "�ܲ�");
    add_id("cao"); 
    set_gender(1);
    set_proper_name("�ܲ�");
    set_in_room_desc("�ܲ�(cao cao)");
    set_age(50);
    set_sg_rank(R_CX);
    set_shengwang(1000000);
}
