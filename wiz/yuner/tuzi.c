// tuzi.c "耳朵长长的兔子"
#include <mudlib.h>
#include <sanguo.h>
inherit LIVING;
inherit M_WANDER;
inherit M_ACTIONS;
inherit M_TRIGGERS;
void receive_outside_msg(string str){
    receive_outside_msga(str);
}
void receive_private_msg(string str) {
    receive_outside_msga(str);
}
string *query_channel_list() {
    return ({ "plyr_gossip" });
}
void setup()
{
    object jia;
    set_name("tuzi", "耳朵长长的兔子");
    add_id("rabbit");
    set_gender(1);
    set_proper_name("眼睛红红的，耳朵长长的兔子");
    set_in_room_desc("一只眼睛红红的，耳朵长长的兔子(rabbit)");
    set_long("可爱的兔子歪着头望了你一眼，一脸的天真：“你不是大灰狼吧？. . .”");    
    set_sg_rongmao(35);
    set_movement_time(20);
    set_wander_area("xbv_area");


    jia=new("/wiz/fire/obj/wear/skirt.c");
    jia->move(this_object());
    jia->do_wear();
     add_pattern("%s深深地叹了口气。",function(){ 
       	if ($1=="小柔")
	{
        	respond("comfort rou");
		respond("say 你真的不想要一只耳朵长长的眼睛红红的兔子吗？~~");
	}
	else
	{
		respond("en");
	}
	});
     add_pattern("%s轻轻托住你的脸，给你一个深情的吻。",function(){ 
	if ($1=="小柔")
	{
		respond("hug2 rou");
                respond("kiss1 rou");	
        } 
	else
	{
		respond("angry");
		respond(":大叫道：别碰我，不然我就把你耳朵拔的跟我一样长，哼！\n");
	}
	});

	add_pattern("%s的肩头放声大哭。",function(){
        if ($1=="小柔")
        {
                respond("tender rou");
                respond("whisper rou 想云儿了？给他写封信吧？");
        }
        });
     add_pattern("%s将你轻轻地搂在怀里。",function(){ 
	if ($1=="小柔")
	{
        	respond("kiss rou");
		respond("hug rou");
	}
	else
	{
		respond("angry");
		respond("say 兔子们，虾米们，咸菜太贵！\n");
	}
	});
     add_pattern("%s惊讶地啊了一声。",function(){ 
	if ($1=="小柔")
	{
		respond("sweat rou");
	}
	else
	{
		respond("angry");
		respond(":看都不看你一眼，哼~~~~~~~\n");
	}
	});
     add_pattern("%s把你紧紧地抱在怀里。",function(){ 
	if ($1=="小柔")
	{
		respond("hug2 rou");
	}
	else
	{
		respond("hammer");
		respond("say 再碰我，我可要叫狼哥哥了~~~~~~狼来了！！！\n");
	}
	});
     add_pattern("%s在你的耳边轻轻吹口气，想把你唤醒。",function(){ 
	if ($1=="小柔")
	{
		respond("wake");
                respond("whisper rou 云儿不在耶，亲亲我好不好？");
                respond("pure rou");
	}

	else
	{
		respond("angry");
		respond("say 别碰我\n");
	}
	});
     add_pattern("%s抱住你的腰，轻声说：“都是我不好，今后再也不惹你生气了。”",function(){ 
	if ($1=="小柔")
	{
		respond("lhong");
	}
	else
	{
		respond("angry");
		respond("say 别碰我\n");
	}
	});
     add_pattern("%s搂着你，在你的耳边悄声道：相思知何日，此夜难为情。",function(){ 
	if ($1=="小柔")
	{
		respond("lkao");
	}
	else
	{
		respond("angry");
		respond("say 别碰我\n");
	}
	});
     add_pattern("%s轻轻地拍了拍你的头。",function(){ 
	if ($1=="小柔")
	{
		respond("pout rou");
	}
	else
	{
		respond("heng");
		respond("say 别碰我\n");
	}
	});
     add_pattern("%s轻轻地摸著你的脸，无限深情的说：“我好喜欢你哦．．．”",function(){ 
	if ($1=="小柔")
	{
		respond("touch rou");
		respond("hug rou");
	}
	else
	{
		respond("angry");
		respond("say 胡说些什么，别碰我\n");
	}
	});
     add_pattern("%s对你发出阵阵淫笑。",function(){ 
		respond("angry");
		respond("say 请放尊重一点\n");
	});
     add_pattern("%s对你说道：送君千里，终有一别，咱们就此别过！",function(){ 
	if ($1=="小柔")
	{	respond("cry rou");
		respond("kiss rou");
		respond("lwait rou");
		respond("good rou");
		respond("cry");
	}
	else
	{
		respond("wave");
	}
	});
     add_pattern("小柔走了%s",function(){ 
		respond("jump rou");
		respond("lsj rou");
		
	});

     add_pattern("%s眨眨眼，一对会说话的眼睛闪闪动人！",function(){
        if ($1=="小柔")
        {
                respond("en rou");
                respond("say 为什么眨眼？是不是对谁有意思了？");
        	respond("angry tuzi");
        }
        else
        {
                respond("pure");
                respond("say 你的眼睛好大哦~~~~~~~~@_@\n");
        }
        });
        
 

      add_pattern("%s看起来一脸天真．．．好可爱耶～～～",function(){
        if ($1=="小柔")
        {
                respond("pure rou");
                respond("say 我是不是一只可爱的兔宝宝呢？");
        }
	});   

      add_pattern("%s摇了摇头。",function(){
        if ($1=="小柔")
        {
                respond("pout");
                respond("inn rou");
                respond("cry tuzi");
        }
        else
        {
                respond("heng tuzi");
                respond(":恶狠狠的叫道：你敢说不？？？\n");
        }
        });
      add_pattern("%s点了点头。",function(){
        if ($1=="小柔")
        {
                respond("jump rou");
                respond("kiss1");
                respond("lean rou");
        }
        else
        {
                respond("thank");
                respond("say 谢谢大灰狼哥哥~~~~~~~~~~\n");
        }
        });
}
