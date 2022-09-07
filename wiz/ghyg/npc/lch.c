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
    set_name("lch", ""+HIY+"林冲"+NOR+"");
    set_gender(1);
    set_proper_name("林冲");
    set_in_room_desc(""+RED+"房间"+NOR+"的"+HIR+"男主人---"+HIY+"林冲"+NOR+"(lch)");
 
set_long(HIY"\n他就是这间房间的男主人，曾经在三国中的风花雪月已经远去，\n"+
         "几十年过去了,岁月在他脸上留下了无情的脚步，吃豆豆大帝、\n"+
         "未日流传人都已经不在存在了。可是，至今江湖上还流传着他\n"+
         "运筹帏卧、决胜千里，谈笑破万兵的光辉事迹。他已经成了三\n"+
         "国中的一个不破的神话，将永远激励着后来的能人志士向前。\n"+                  
         "故人远走，亲人永别。这对他是最大的打击，无论再坚强的人\n"+
         "也心灰意冷，所以他选择了离去。三国对他来说已经成过往云烟，\n"+
         "他已经忘记了那里的一切，只希望在这里陪伴着飘雪,永远永远.....\n"NOR);
    set_age(22);
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

write(HIY+"\n林冲抱轻轻抱着你柔声说道：“亲爱的，你回来啦，累了吧，好好休息一会。\n"+NOR
);
else 
    if (o->query_primary_id()=="corydon" || o->query_primary_id()=="yesh")
      {write(HIR+"\n欢迎你小朋友，我特准你进来了，不过不要乱动呀。：）\n"NOR);}
     else
    {write(HIY"\n林冲笑脸盈盈走过来，和蔼地说道：欢迎到参观！\n"+HIR+
     "不过不好意思，我夫人要休息了。\n"+"快走吧！等她回来了你再来吧。\n"+NOR+"");
     o->move("/a/huayin/vhall.c");
     o->start_busy(60,HIY"林冲告诉你：“你非法进入别人的家，所以，罚你站这一分钟。”"NOR);}
}
void do_greet(object o) 
{
call_out("greet",1,o);
}
