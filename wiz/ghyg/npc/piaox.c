#include <mudlib.h>
#include <ansi.h>
#include <sanguo.h>
#include <localtime.h>
inherit LIVING;
inherit M_WANDER;
inherit M_ACTIONS;
inherit M_TRIGGERS;
inherit CHINESE_DA;
inherit M_GREETER;
void receive_outside_msg(string str){
    receive_outside_msga(str);
}
void receive_private_msg(string str) {
    receive_outside_msga(str);
}
string *query_channel_list() {
    return ({ "plyr_gossip" });
}

object jia;
void setup()
{
    set_name("piao xue", ""+HIY+"飘雪"+NOR+"");
    set_gender(2);
    set_proper_name("飘雪");
    set_in_room_desc(""+RED+"房间"+NOR+"的"+HIR+"女主人---"+HIY+"飘雪"+NOR+"(piao xue)");
    set_long(HIY"\n她是这间房间的女主人，也曾经在外面的乱世争霸,\n"+
                "也曾经金戈铁马，也曾经雪月风花。现在她已经累了，\n"+
                "也不再想在江湖上挣扎了，她放弃了自己的肉身，终于\n"+
                "修成了正果，但她还有一些事情放不下，可能永远也放\n"+
                "不下了，从她眼角中你能看出岁月的沧桑，永恒的无奈。\n"+HIR
                "她现在正在休息，请别打扰她，让她好好睡一会吧。\n"NOR);
    set_age(18);
    set_sg_rongmao(30);
    jia=new("/sgdomain/obj/cloth/torso/longpao.c");
    jia->move(this_object());
    jia->do_wear();

      jia=new("/wiz/ghyg/obj/jinkui.c");
    jia->move(this_object());
    jia->do_wear();

    jia=new("/sgdomain/obj/weapon/sword/yitian.c");
    jia->move(this_object());
    jia->do_wield();
    init_greet();     
}
void greet(object o)
{
if (o->query_primary_id()=="ghyg" || o->query_primary_id()=="firecrow")
write(HIY"\n亲爱的你回来啦，要不要我给你作点吃的？要不下碗面给你？"+
         "\n飘雪高兴的跳到你怀里。\n"+NOR);
else 
    write(HIY"\n飘雪笑脸盈盈走过来，和蔼地说道：欢迎到参观！\n"+
          "不过不好意思，我要休息了，你等我的真人在的时候再来吧。\n"+HIR
          "快走吧！要不我真的要打你了。\n"+NOR+"");   
}
void do_greet(object o) 
{
call_out("greet",1,o);
}
