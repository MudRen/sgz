#include <mudlib.h>
#include <sanguo.h>
inherit MONSTER;
void setup()
{
    object wep;
    object horse;
    set_name("jiang wei", "��ά");
    add_id("jiang"); 
    set_gender(1);
    set_proper_name("����Լ");
    set_in_room_desc("��ά(jiang wei)");
    set_age(28);
    set_sg_rank(R_DJJ);
    set_shengwang(100000);
    init_sg_gifts(25,24,11) ;
    set_sg_rongmao(30);
    wep=new("/wiz/shaoyng/obj/wear/qiang.c");
    wep->move(this_object());
    this_object()->do_wield(wep);
    horse=new("/sgdomain/obj/horse/jueyinghorse.c");
    horse->move(environment(this_object()));
    this_object()->move(horse);
}

