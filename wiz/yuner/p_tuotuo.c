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
     add_pattern("%s�����̾�˿�����",function(){ 
	if ($1=="�һ�")
	{
        	respond("comfort fire");
		respond("say �����ڣ��㻹��������");
	}
	else
	{
		respond("en");
	}
	});
     add_pattern("%s������ס�����������һ��������ǡ�",function(){ 
	if ($1=="�һ�")
	{
        	respond("blush");
		respond("giggle");
	}
	else
	{
		respond("angry");
		respond("say ������\n");
	}
	});
     add_pattern("%s���������§�ڻ��",function(){ 
	if ($1=="�һ�")
	{
        	respond("shame fire");
		respond("lsj fire");
	}
	else
	{
		respond("angry");
		respond("say ������\n");
	}
	});
     add_pattern("%s�����������ǰ���㣬�������ˡ�",function(){ 
	if ($1=="�һ�")
	{
		respond("llook");
	}
	else
	{
		respond("angry");
		respond("say ����\n");
	}
	});
     add_pattern("%s��������ر��ڻ��",function(){ 
	if ($1=="�һ�")
	{
		respond("lbao");
	}
	else
	{
		respond("angry");
		respond("say ������\n");
	}
	});
     add_pattern("%s����Ķ������ᴵ����������㻽�ѡ�",function(){ 
	if ($1=="�һ�")
	{
		respond("lwake");
	}
	else
	{
		respond("angry");
		respond("say ������\n");
	}
	});
     add_pattern("%s��ס�����������˵���������Ҳ��ã������Ҳ�����������ˡ���",function(){ 
	if ($1=="�һ�")
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
	if ($1=="�һ�")
	{
		respond("lkao");
	}
	else
	{
		respond("angry");
		respond("say ������\n");
	}
	});
     add_pattern("%s�ḧ����㷢̾�������������ˣ������κ�����",function(){ 
	if ($1=="�һ�")
	{
		respond("lwife");
	}
	else
	{
		respond("angry");
		respond("say ��˵Щʲô��������\n");
	}
	});
     add_pattern("%s�������������������������˵�����Һ�ϲ����Ŷ��������",function(){ 
	if ($1=="�һ�")
	{
		respond("giggle");
		respond("kiss fire");
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
	if ($1=="�һ�")
	{	respond("cry fire");
		respond("kiss fire");
		respond("lwait fire");
		respond("good fire");
		respond("cry");
	}
	else
	{
		respond("wave");
	}
	});
     add_pattern("�һ�����%s",function(){ 
		respond("jump fire");
		respond("lsj fire");
		
	});
}
