// farmer.c "ũ��"
#include <mudlib.h>
#include <sanguo.h>
inherit MONSTER;
void setup()
{
    object wep;
    object horse;
    set_name("guan yu", "����");
    add_id("guan"); 
    set_gender(1);
    set_proper_name("����");
    set_in_room_desc("����(guan yu)");
    set_age(28);
    set_sg_rank(R_DJJ);
    set_shengwang(100000);
   init_sg_gifts(30 ,15,15) ;
   set_sg_rongmao(25);
    wep=new("/wiz/yue/obj/longdao.c");
    wep->move(this_object());
    this_object()->do_wield(wep);
    horse=new("/wiz/ljty/obj/chituhorse.c");
    horse->move(environment(this_object()));
    this_object()->move(horse);
}
