// tuzi.c "���䳤��������"
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
    set_name("tuzi", "���䳤��������");
    add_id("rabbit");
    set_gender(1);
    set_proper_name("�۾����ģ����䳤��������");
    set_in_room_desc("һֻ�۾����ģ����䳤��������(rabbit)");
    set_long("�ɰ�����������ͷ������һ�ۣ�һ�������棺���㲻�Ǵ���ǰɣ�. . .��");    
    set_sg_rongmao(35);
    set_movement_time(20);
    set_wander_area("xbv_area");


    jia=new("/wiz/fire/obj/wear/skirt.c");
    jia->move(this_object());
    jia->do_wear();
     add_pattern("%s�����̾�˿�����",function(){ 
       	if ($1=="С��")
	{
        	respond("comfort rou");
		respond("say ����Ĳ���Ҫһֻ���䳤�����۾�����������~~");
	}
	else
	{
		respond("en");
	}
	});
     add_pattern("%s������ס�����������һ��������ǡ�",function(){ 
	if ($1=="С��")
	{
		respond("hug2 rou");
                respond("kiss1 rou");	
        } 
	else
	{
		respond("angry");
		respond(":��е��������ң���Ȼ�ҾͰ������εĸ���һ�������ߣ�\n");
	}
	});

	add_pattern("%s�ļ�ͷ������ޡ�",function(){
        if ($1=="С��")
        {
                respond("tender rou");
                respond("whisper rou ���ƶ��ˣ�����д���Űɣ�");
        }
        });
     add_pattern("%s���������§�ڻ��",function(){ 
	if ($1=="С��")
	{
        	respond("kiss rou");
		respond("hug rou");
	}
	else
	{
		respond("angry");
		respond("say �����ǣ�Ϻ���ǣ��̲�̫��\n");
	}
	});
     add_pattern("%s���ȵذ���һ����",function(){ 
	if ($1=="С��")
	{
		respond("sweat rou");
	}
	else
	{
		respond("angry");
		respond(":����������һ�ۣ���~~~~~~~\n");
	}
	});
     add_pattern("%s��������ر��ڻ��",function(){ 
	if ($1=="С��")
	{
		respond("hug2 rou");
	}
	else
	{
		respond("hammer");
		respond("say �����ң��ҿ�Ҫ���Ǹ����~~~~~~�����ˣ�����\n");
	}
	});
     add_pattern("%s����Ķ������ᴵ����������㻽�ѡ�",function(){ 
	if ($1=="С��")
	{
		respond("wake");
                respond("whisper rou �ƶ�����Ү�������Һò��ã�");
                respond("pure rou");
	}

	else
	{
		respond("angry");
		respond("say ������\n");
	}
	});
     add_pattern("%s��ס�����������˵���������Ҳ��ã������Ҳ�����������ˡ���",function(){ 
	if ($1=="С��")
	{
		respond("lhong");
	}
	else
	{
		respond("angry");
		respond("say ������\n");
	}
	});
     add_pattern("%s§���㣬����Ķ�������������˼֪���գ���ҹ��Ϊ�顣",function(){ 
	if ($1=="С��")
	{
		respond("lkao");
	}
	else
	{
		respond("angry");
		respond("say ������\n");
	}
	});
     add_pattern("%s��������������ͷ��",function(){ 
	if ($1=="С��")
	{
		respond("pout rou");
	}
	else
	{
		respond("heng");
		respond("say ������\n");
	}
	});
     add_pattern("%s�������������������������˵�����Һ�ϲ����Ŷ��������",function(){ 
	if ($1=="С��")
	{
		respond("touch rou");
		respond("hug rou");
	}
	else
	{
		respond("angry");
		respond("say ��˵Щʲô��������\n");
	}
	});
     add_pattern("%s���㷢��������Ц��",function(){ 
		respond("angry");
		respond("say �������һ��\n");
	});
     add_pattern("%s����˵�����;�ǧ�����һ�����Ǿʹ˱����",function(){ 
	if ($1=="С��")
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
     add_pattern("С������%s",function(){ 
		respond("jump rou");
		respond("lsj rou");
		
	});

     add_pattern("%sգգ�ۣ�һ�Ի�˵�����۾��������ˣ�",function(){
        if ($1=="С��")
        {
                respond("en rou");
                respond("say Ϊʲôգ�ۣ��ǲ��Ƕ�˭����˼�ˣ�");
        	respond("angry tuzi");
        }
        else
        {
                respond("pure");
                respond("say ����۾��ô�Ŷ~~~~~~~~@_@\n");
        }
        });
        
 

      add_pattern("%s������һ�����森�����ÿɰ�Ү������",function(){
        if ($1=="С��")
        {
                respond("pure rou");
                respond("say ���ǲ���һֻ�ɰ����ñ����أ�");
        }
	});   

      add_pattern("%sҡ��ҡͷ��",function(){
        if ($1=="С��")
        {
                respond("pout");
                respond("inn rou");
                respond("cry tuzi");
        }
        else
        {
                respond("heng tuzi");
                respond(":��ݺݵĽе������˵��������\n");
        }
        });
      add_pattern("%s���˵�ͷ��",function(){
        if ($1=="С��")
        {
                respond("jump rou");
                respond("kiss1");
                respond("lean rou");
        }
        else
        {
                respond("thank");
                respond("say лл����Ǹ��~~~~~~~~~~\n");
        }
        });
}
