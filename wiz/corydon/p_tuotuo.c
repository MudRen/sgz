// p_tuotuo.c "美丽的小翘"
#include <mudlib.h>
#include <sanguo.h>
inherit LIVING;
inherit M_ACTIONS;
inherit M_WANDER;
inherit M_TRIGGERS;
string *emotes, *adverbs;
string find_target() {
    string u_id;
    object *who = users(); // & all_inventory(environment());
    if (!sizeof(who)) 
        return this_object()->query_id()[0];
    u_id=who[random(sizeof(who))]->query_userid();
    if(!find_body(u_id))
        return this_object()->query_id()[0];
    return u_id;
}
void do_my_thing() {
    string which = emotes[random(sizeof(emotes))];
    string *rules = keys(SOUL_D->query_emote(which));
    string rule = rules[random(sizeof(rules))];
    object *who = users();
    string comm, token;
    
    if (!environment()) return;
    comm = which;
    foreach (token in explode(rule, " ")) {
        comm += " ";
        switch (token) {
        case "OBJ":
        case "LIV":
            comm += find_target();
            break;
        default:
            comm += token;
        }
    }
    call_out( (: do_my_thing :), 60);
    do_game_command(comm);
}

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
    set_name("girl", "小恐龙");
    add_id("tuotuo");
    set_gender(2);
    set_proper_name("美丽的小恐龙");
    set_in_room_desc("美丽动人的少女：小恐龙(girl)");
    set_long("小恐龙抬头望了你一眼，叹了一口气：
“唉. . .你不是我要找的人. . .”");
    jia=new("/wiz/fire/obj/wear/skirt.c");
    jia->move(this_object());
    jia->do_wear();
     set_sg_rongmao(35);
     add_pattern("牧童深深地叹了口气。",function(){ 
	
        	respond("comfort corydon");
		respond("say 有我在，你还不高兴吗？\n");
	
	});
     add_pattern("牧童轻轻托住你的脸，给你一个深情的吻。",function(){ 
	
        	respond("blush corydon");
		respond("giggle corydon");
		respond("say 我这就跟你走\n");
	
	});
     add_pattern("牧童将你轻轻地搂在怀里。",function(){ 
	
        	respond("shame corydon");
		respond("lbao corydon");
	
	});
     add_pattern("牧童深情地望着眼前的你，不禁痴了。",function(){ 
	
		respond("llook corydon");
	
	});
     add_pattern("牧童把你紧紧地抱在怀里。",function(){ 
	
		respond("kiss corydon");
	
	});
     add_pattern("牧童在你的耳边轻轻吹口气，想把你唤醒。",function(){ 
	
		respond("lwake");
	
	});
     add_pattern("牧童抱住你的腰，轻声说：“都是我不好，今后再也不惹你生气了。”",function(){ 
	
		respond("blush");
	
	});
     add_pattern("牧童搂着你，在你的耳边悄声道：相思知何日，此夜难为情。",function(){ 
	
		respond("lean corydon");
	
	});
     add_pattern("牧童轻抚你的秀发叹到",function(){ 
	
		respond("kiss corydon");
	
	});
     add_pattern("牧童轻轻地摸著你的脸，无限深情的说：“我好喜欢你哦．．．”",function(){ 
	
		respond("giggle");
		respond("kiss fire");
	
	});
     
     add_pattern("牧童深情地看着你，不禁黯然神伤：今朝离别去，何日再相逢？",function(){ 
		respond("cry corydon");
		respond("kiss corydon");
		respond("lwait corydone");
		respond("good corydon");
		respond("cry");
	
	});
     add_pattern("牧童走了%s",function(){ 
		respond("jump corydon");
		respond("lsj corydonf");
		
	});
    emotes = SOUL_D->list_emotes();
    adverbs = SOUL_D->get_adverbs();
    call_out( (: do_my_thing :), 5);
    set_movement_time(20);
    set_wander_area("huayin_area");
    

}
