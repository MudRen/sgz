#include <mudlib.h>
#include <sanguo.h>
inherit MONSTER;
void setup()
{
    object wep;
    set_name("wei yan", "κ��");
    add_id("wei"); 
    set_gender(1);
    set_proper_name("κ��");
    set_in_room_desc("κ��(wei yan)");
    set_age(31);
    set_sg_rank(R_DJJ);
    set_shengwang(100000);
    init_sg_gifts(30,20,10);
    set_sg_rongmao(23);
    wep=new("/wiz/shaoyng/obj/wear/Wblade.c");
    wep->move(this_object());
    this_object()->do_wield(wep);
}

