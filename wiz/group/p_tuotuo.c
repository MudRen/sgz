// p_tuotuo.c "������С��"
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
    set_name("girl", "С��");
    add_id("tuotuo");
    set_gender(2);
    set_proper_name("������С��");
    set_in_room_desc("�������˵���Ů��С��(girl)");
    set_long("С��̧ͷ������һ�ۣ�̾��һ������
����. . .�㲻����Ҫ�ҵ���. . .��");
    jia=new("/wiz/fire/obj/wear/skirt.c");
    jia->move(this_object());
    jia->do_wear();
     set_sg_rongmao(35);
     add_pattern("���������̾�˿�����",function(){ 
	
        	respond("comfort group");
		respond("say �����ڣ��㻹��������");
	});
add_pattern("%s�����̾�˿�����",function(){
	
	
		respond("en");
	
	});
     add_pattern("����������ס�����������һ��������ǡ�",function(){ 
	
        	respond("blush");
		respond("giggle");
	});
add_pattern("%s������ס�����������һ��������ǡ�",function()	{
		respond("angry");
		respond("say ������\n");
	}
	);
     add_pattern("���⽫�������§�ڻ��",function(){ 
	
        	respond("shame group");
		respond("lsj fire");
	});
add_pattern("%s���������§�ڻ��",function()	{
		respond("angry");
		respond("say ������\n");
	
	});
     add_pattern("���������������ǰ���㣬�������ˡ�",function(){ 
	
		respond("llook");
	});
add_pattern("%s�����������ǰ���㣬�������ˡ�",function(){	
		respond("angry");
		respond("say ����\n");
	
	});
     add_pattern("�����������ر��ڻ��",function(){ 
	
		respond("lbao");
	});
add_pattern("%s��������ر��ڻ��",function(){	
		respond("angry");
		respond("say ������\n");
	
	});
     add_pattern("��������Ķ������ᴵ����������㻽�ѡ�",function(){ 
	
		respond("lwake");
	});
add_pattern("%s����Ķ������ᴵ����������㻽�ѡ�",function(){	
		respond("angry");
		respond("say ������\n");
	
	});

add_pattern("���Ⱨס�����������˵���������Ҳ��ã������Ҳ�����������ˡ���",function(){ 
	
		respond("lhong");
	});
add_pattern("%s��ס�����������˵���������Ҳ��ã������Ҳ�����������ˡ���",function(){	

		respond("angry");
		respond("say ������\n");
	
	});

add_pattern("����§���㣬����Ķ�������������˼֪���գ���ҹ��Ϊ�顣",function(){ 
	
		respond("lkao");
	});
add_pattern("%s§���㣬����Ķ�������������˼֪���գ���ҹ��Ϊ�顣",function(){	

		respond("angry");
		respond("say ������\n");
	
	});

add_pattern("�����ḧ����㷢̾�������������ˣ������κ�����",function(){ 
	
		respond("xixi");
	 });
add_pattern("%s�ḧ����㷢̾�������������ˣ������κ�����",function(){	

		respond("angry");
		respond("say ��˵Щʲô��������\n");
	
	});

add_pattern("�����������������������������˵�����Һ�ϲ����Ŷ��������",function(){ 
	
		respond("giggle");
		respond("kiss group");
	 });
add_pattern("%s�������������������������˵�����Һ�ϲ����Ŷ��������",function(){	

		respond("angry");
		respond("say ��˵Щʲô��������\n");
	
	});
     add_pattern("%s���㷢��������Ц��",function(){ 
		respond("angry");
		respond("say �������һ��\n");
	});

add_pattern("�������˵�����;�ǧ�����һ�����Ǿʹ˱����",function(){ 
		respond("cry group");
		respond("kiss fire");
		respond("lwait fire");
		respond("good fire");
		respond("cry");
	});
add_pattern("%s����˵�����;�ǧ�����һ�����Ǿʹ˱����",function(){	

		respond("wave");
	
	});
     add_pattern("�һ�����%s",function(){ 
		respond("jump fire");
		respond("lsj fire");
		
	});
}
