// p_tuotuo.c "美丽的小翘"
#include <mudlib.h>
#include <sanguo.h>
inherit LIVING;
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
    set_name("girl", "小翘");
    add_id("tuotuo");
    set_gender(2);
    set_proper_name("美丽的小翘");
    set_in_room_desc("美丽动人的少女：小翘(girl)");
    set_long("小翘抬头望了你一眼，叹了一口气：
“唉. . .你不是我要找的人. . .”");
    jia=new("/wiz/fire/obj/wear/skirt.c");
    jia->move(this_object());
    jia->do_wear();
     set_sg_rongmao(35);
     add_pattern("国题深深地叹了口气。",function(){ 
	
        	respond("comfort group");
		respond("say 有我在，你还不高兴吗？");
	});
add_pattern("%s深深地叹了口气。",function(){
	
	
		respond("en");
	
	});
     add_pattern("国题轻轻托住你的脸，给你一个深情的吻。",function(){ 
	
        	respond("blush");
		respond("giggle");
	});
add_pattern("%s轻轻托住你的脸，给你一个深情的吻。",function()	{
		respond("angry");
		respond("say 别碰我\n");
	}
	);
     add_pattern("国题将你轻轻地搂在怀里。",function(){ 
	
        	respond("shame group");
		respond("lsj fire");
	});
add_pattern("%s将你轻轻地搂在怀里。",function()	{
		respond("angry");
		respond("say 别碰我\n");
	
	});
     add_pattern("国题深情地望着眼前的你，不禁痴了。",function(){ 
	
		respond("llook");
	});
add_pattern("%s深情地望着眼前的你，不禁痴了。",function(){	
		respond("angry");
		respond("say 讨厌\n");
	
	});
     add_pattern("国题把你紧紧地抱在怀里。",function(){ 
	
		respond("lbao");
	});
add_pattern("%s把你紧紧地抱在怀里。",function(){	
		respond("angry");
		respond("say 别碰我\n");
	
	});
     add_pattern("国题在你的耳边轻轻吹口气，想把你唤醒。",function(){ 
	
		respond("lwake");
	});
add_pattern("%s在你的耳边轻轻吹口气，想把你唤醒。",function(){	
		respond("angry");
		respond("say 别碰我\n");
	
	});

add_pattern("国题抱住你的腰，轻声说：“都是我不好，今后再也不惹你生气了。”",function(){ 
	
		respond("lhong");
	});
add_pattern("%s抱住你的腰，轻声说：“都是我不好，今后再也不惹你生气了。”",function(){	

		respond("angry");
		respond("say 别碰我\n");
	
	});

add_pattern("国题搂着你，在你的耳边悄声道：相思知何日，此夜难为情。",function(){ 
	
		respond("lkao");
	});
add_pattern("%s搂着你，在你的耳边悄声道：相思知何日，此夜难为情。",function(){	

		respond("angry");
		respond("say 别碰我\n");
	
	});

add_pattern("国题轻抚你的秀发叹到：“得妻若此，此生何憾？”",function(){ 
	
		respond("xixi");
	 });
add_pattern("%s轻抚你的秀发叹到：“得妻若此，此生何憾？”",function(){	

		respond("angry");
		respond("say 胡说些什么，别碰我\n");
	
	});

add_pattern("国题轻轻地摸著你的脸，无限深情的说：“我好喜欢你哦．．．”",function(){ 
	
		respond("giggle");
		respond("kiss group");
	 });
add_pattern("%s轻轻地摸著你的脸，无限深情的说：“我好喜欢你哦．．．”",function(){	

		respond("angry");
		respond("say 胡说些什么，别碰我\n");
	
	});
     add_pattern("%s对你发出阵阵淫笑。",function(){ 
		respond("angry");
		respond("say 请放尊重一点\n");
	});

add_pattern("国题对你说道：送君千里，终有一别，咱们就此别过！",function(){ 
		respond("cry group");
		respond("kiss fire");
		respond("lwait fire");
		respond("good fire");
		respond("cry");
	});
add_pattern("%s对你说道：送君千里，终有一别，咱们就此别过！",function(){	

		respond("wave");
	
	});
     add_pattern("烈火走了%s",function(){ 
		respond("jump fire");
		respond("lsj fire");
		
	});
}
