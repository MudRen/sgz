// by fire on Dec 29 1997
// kongyiji.c  ��һ��
#include <mudlib.h>
#include <sanguo.h>
inherit LIVING;
inherit CHINESE_DA;
private *name_list=({ });
int learn_zgxy(object who)  //�ι�����
{
  int p_res;
  string p_st;
  p_res=LEARNCHECK_D->check_can_learn_skills("sk_meili",30);
  switch(p_res)
  {
	case TOO_TIRED:
		this_object()->targetted_action("$N��$TЦ��������̫���ˣ���Ϣ�������ѧ�ɡ���\n",who);
		return 0;
	case TOO_EASY:
		this_object()->targetted_action("$N��$TЦ����������Ҹ�����������ʦ�ˡ���\n",who);
		return 0;
		case LESS_LITERATE:
 this_object()->targetted_action("$N��$T���������ѧ̫���������Щ��\n",this_body());
			return 0;
	case CAN_LEARN:
  		this_object()->targetted_action("$N��$T������ι�֮����\n",who);
  		p_st=SG_SKILL_D->query_get("sk_meili");
  		who->simple_action(p_st);
  		return 1;
	default :
		write("�㾭�鲻����\n");
//            write("��������"+p_res);
  }
  return 0;
}
int learn_bfxy(object who)  //��������
{
  int p_res;
  string p_st;
  p_res=LEARNCHECK_D->check_can_learn_skills("sk_zhimou",30);
  switch(p_res)
  {
	case TOO_TIRED:
		this_object()->targetted_action("$N��$TЦ��������̫���ˣ���Ϣ�������ѧ�ɡ���\n",who);
		return 0;
                case LESS_LITERATE:
 this_object()->targetted_action("$N��$T���������ѧ̫���������Щ��\n",this_body());
                        return 0;
	case TOO_EASY:
		this_object()->targetted_action("$N��$TЦ����������Ҹ�����������ʦ�ˡ���\n",who);
		return 0;
	case CAN_LEARN:
  		this_object()->targetted_action("$N��$T������ñ�֮����\n",who);
  		p_st=SG_SKILL_D->query_get("sk_zhimou");
  		who->simple_action(p_st);
  		return 1;
	default :
		write("�㾭�鲻����\n");
//		write("��֪Ϊʲô�������㣬������ʦ�ɡ�\n");
  }
  return 0;
}
void setup()
{
    set_name("kong yiji", "��һ��");
    set_proper_name("��һ��");
    set_in_room_desc("��һ��(kong yiji)");
    set_gender(1);
    set_age(40);
    add_id("kong");
    
	add_question("name","name" );
	add_question("bfxy","bfxy");
	add_question("rumors","rumors");
	add_question("zgxy","zgxy");
	add_question("money","money");
    set_sg_rongmao(-1);
   set_accept_money(1);
}
string long() {
	return "��һ������ȥ����ģ��ƺ�û̫˯�ѡ�\n";
}
void special_answer(object who, string matt)
{
	int p_money;
	string p_id;
	object ob;
	string s_tmp;
	switch(matt)
	{
		case "name" :
			this_object()->targetted_action("$N��$Tһ��������˵����"+
"�����˿�����ʮ�˴������ſ�һ��Ҳ����\n",who);
 			return;
		case "rumors" :
			this_object()->targetted_action("$N��$T˵����"+
"�������ң����������겻ѧ�㱾�£�����Ϊ��ѽ��\n",who);
			return;
			
		case "money" :
			this_object()->targetted_action(
"$N��$t˵������ѧ�߲�ͼǮ�ƣ���Ҳ�ú���ѽ��ѧ��������������\n",who);
			return;
		case "bfxy" :
			p_id=this_body()->query_userid();
			if(member_array(p_id, name_list) != -1)
			{
				if(learn_bfxy(this_body()))
					name_list-=({ p_id });
			}
			else
			{
				
				this_object()->targetted_action(
"$N��$t˵����������ѧѽ���п׷��ֵĽ�������\n",who);
			}
			return;
		case "zgxy" :
			p_id=this_body()->query_userid();
			if(member_array(p_id, name_list) != -1)
			{
				if(learn_zgxy(this_body()))
					name_list-=({ p_id });
			}
			else
			{
				
				this_object()->targetted_action(
"$N��$t˵����������ѧѽ���п׷��ֵĽ�������\n",who);
			}
			return;
	}
}
void receive_money(object who, int number,string str)
{
	string p_id;
	int p_val;
	p_val=NORMAL_D->query_money_value(number,str);
	if (p_val>=500)
	{
		p_id=this_body()->query_userid();
		name_list+=({ p_id });
		this_object()->targetted_action("$N��$tЦ���������ڻ��кö���֮�ˡ���\n",who);
	}
	else 
		this_object()->targetted_action("$N��$t��Ц�������Ǯ������ʲô��\n",who);
	return;
}
