// farmer.c "农夫"
#include <mudlib.h>
#include <sanguo.h>
inherit MONSTER;
void setup()
{
    object wep;
    object xi,jia,zhu;
    set_name("Lv bu", "吕布");
    set_gender(1);
    set_sg_max_hp(1000);
    set_cur_max_hp(1000);
    set_cur_hp(1000);
    set_proper_name("吕布");
    set_in_room_desc("吕布(Lv bu)");
    set_long("此乃天下第一勇士人称『温候』的吕布吕奉先！！\n");
    set_age(28);
    set_sg_rank(R_DJJ);
    set_shengwang(100000);
   init_sg_gifts(30 ,20,10) ;
   set_sg_rongmao(25);
    wep=new("/wiz/fire/obj/wear/ji.c");
    wep->move(this_object());
    this_object()->do_wield(wep);
    xi=new("/wiz/fire/obj/wear/xue.c");
    xi->move(this_object());
    xi->do_wear();
    jia=new("/wiz/fire/obj/wear/jia.c");
    jia->move(this_object());
    jia->do_wear();
    zhu=new("/wiz/fire/obj/wear/zhu.c");
    zhu->move(this_object());
    zhu->do_wear();
   set_sg_max_hp(800);
}
