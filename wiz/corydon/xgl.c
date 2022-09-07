// p_tuotuo.c "������С��"
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
    set_name("girl", "С����");
    add_id("tuotuo");
    set_gender(2);
    set_proper_name("������С����");
    set_in_room_desc("�������˵���Ů��С����(girl)");
    set_long("С����̧ͷ������һ�ۣ�̾��һ������
����. . .�㲻����Ҫ�ҵ���. . .��");
    jia=new("/wiz/fire/obj/wear/skirt.c");
    jia->move(this_object());
    jia->do_wear();
     set_sg_rongmao(35);
     add_pattern("��ͯ�����̾�˿�����",function(){ 
	
        	respond("comfort corydon");
		respond("say �����ڣ��㻹��������\n");
	
	});
     add_pattern("��ͯ������ס�����������һ��������ǡ�",function(){ 
	
        	respond("blush corydon");
		respond("giggle corydon");
		respond("say ����͸�����\n");
	
	});
     add_pattern("��ͯ���������§�ڻ��",function(){ 
	
        	respond("shame corydon");
		respond("lbao corydon");
	
	});
     add_pattern("��ͯ�����������ǰ���㣬�������ˡ�",function(){ 
	
		respond("llook corydon");
	
	});
     add_pattern("��ͯ��������ر��ڻ��",function(){ 
	
		respond("kiss corydon");
	
	});
     add_pattern("��ͯ����Ķ������ᴵ����������㻽�ѡ�",function(){ 
	
		respond("lwake");
	
	});
     add_pattern("��ͯ��ס�����������˵���������Ҳ��ã������Ҳ�����������ˡ���",function(){ 
	
		respond("blush");
	
	});
     add_pattern("��ͯ§���㣬����Ķ�������������˼֪���գ���ҹ��Ϊ�顣",function(){ 
	
		respond("lean corydon");
	
	});
     add_pattern("��ͯ�ḧ����㷢̾��",function(){ 
	
		respond("kiss corydon");
	
	});
     add_pattern("��ͯ�������������������������˵�����Һ�ϲ����Ŷ��������",function(){ 
	
		respond("giggle");
		respond("kiss fire");
	
	});
     
     add_pattern("��ͯ����ؿ����㣬������Ȼ���ˣ������ȥ����������ꣿ",function(){ 
		respond("cry corydon");
		respond("kiss corydon");
		respond("lwait corydone");
		respond("good corydon");
		respond("cry");
	
	});
     add_pattern("��ͯ����%s",function(){ 
		respond("jump corydon");
		respond("lsj corydonf");
		
	});
    emotes = SOUL_D->list_emotes();
    adverbs = SOUL_D->get_adverbs();
    call_out( (: do_my_thing :), 5);
    set_movement_time(20);
    set_wander_area("huayin_area");
    

}
