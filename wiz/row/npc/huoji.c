// xiaoer.c ��� by row
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
	set_name("huo ji", "���");
	add_id("waiter","ji");
	set_gender(1);
	set_proper_name("���");
	set_in_room_desc("���(huo ji)");
	set_long("һ������Ŀ�ջ��ƣ�ʱ��ʱ����Ĩ�����ù�̨��\n\n");
	set_sg_rongmao(15);
	add_question("rumors","rumors" );
	add_pattern("%s���˹�����",function()
	{
		respond("say ��λ��ס����");
	});
}
void special_answer(object who, string matt)
{
	switch(matt)
	{
		case "rumors" :
			this_object()->targetted_action("$Nѹ����ɤ�ŵ��������������˶��������\n",who);
			return;
	}
}