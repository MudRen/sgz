// written by yuner and fire 
/* Do not remove the headers from this file! see /USAGE for more info. */
#include <mudlib.h>
#include <sanguo.h>
inherit LIVING;
inherit M_ACTIONS;
inherit M_TRIGGERS;
inherit CHINESE_DA;
private *name_list=({ });
string *query_channel_list() {
    return ({ "plyr_gossip" });
}
void learn_sj(object who)
{
  int p_res;
  string p_st;
  p_res=LEARNCHECK_D->check_can_learn_skills("jbsj",30);
  switch(p_res)
  {
	case TOO_TIRED:
		this_object()->targetted_action("$N��$TЦ��������̫���ˣ���Ϣ�������ѧ����ˮ�ưɡ���\n",who);
		return;
	case TOO_EASY:
		this_object()->targetted_action("$N��$TЦ��������������������̻���ˮ���ء���\n",who);
		return;
	case LESS_EXP:
		this_object()->targetted_action("$N��$TЦ���������鲻����ֻ������Ҳ�̲�����ѽ����\n",who);
		return;
	case CAN_LEARN:
  		this_object()->targetted_action("$N��$T����˻���ˮ��֮����\n",who);
  		p_st=SG_SKILL_D->query_get("jbsj");
  		who->simple_action(p_st);
  		return;
	default :
		write("��֪Ϊʲô�������㣬������ʦ�ɡ�\n");
  }
  return;
}
void setup()
{
    set_name("shuijing xiansheng", "ˮ������");
    set_gender(1);
    set_proper_name("ˮ������");
    set_in_room_desc("ˮ������(shuijing xiansheng)");
    add_id("shuijing");
    add_id("sx");
    add_id("xiansheng");
    set_age(70);
    set_long("     
      һ����ʮ��������ߣ��ɷ���ǣ�
����˸˸�� ���۳������ǻ۵Ĺ�â��
Ҫ����ʲô�����ģ����������������� ");
	add_question("name","name" );
	add_question("here","here");
	add_question("news","news");
	add_question("rumors","rumors");
	add_question("help","help");
	add_question("money","money");
	add_question("shouming","shouming");
	add_question("jbsj","jbsj");
	add_question("luoyang","luoyang");
    add_pattern("%s���˹�����", (: "say " + $1 + "���������ӭ���������ͣ�
�ȶ���(read)���ɣ�" :) );
    add_pattern("%s����LIMA��", (: "say " + $1 + "���������ӭ���������ͣ�
�ȶ���(read)���ɣ�" :) ); 
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
			this_object()->targetted_action("$N��$TЦ����"+
"�����ҵ������ҵ���������һɽҰ��������ʲô���մ���ѽ����\n",who);
 			return;
 		case "here" :
			this_object()->simple_action(
"$N˵��������������ʱ������֪������Щʲô��(help,money,shouming)");
			return;
		case "help" :
			this_object()->simple_action("$N΢΢һЦ��\n");
			this_object()->simple_action("$N˵������������Ұɣ����ҿ��ʶ��ˡ���\n"+
"Ҫ���˽��������磬���ȶ�������(news)��\n");
			return;
		case "news" :
			this_object()->targetted_action("$N��$TЦ����"+
"��������������С�ֵ��Ļ���־�����ɳ�һ����ҵ��\n",who);
			return;
		case "rumors" :
			this_object()->targetted_action("$N��$TС��˵����"+
"��˵����������Ϸ������������������ʦ������Ȥ�Ļ��п�ȥ�����ɡ�\n",who);
			return;
			
		case "money" :
			this_object()->targetted_action(
"$N��$t�ź���˵�������������ҵ���ȫ�������ˣ�$cҪ�ǲ������ɵ�����\n"+
"�Ŵ󻧼ҿ����ܲ����ҵ��ɸɣ���������(help digsoil)�鿴��\n",who);
                        return;
			p_money=who->query_amt_money("bank");
			p_money=p_money+who->query_all_con_money();
			if (p_money>50000)
			{
				this_object()->targetted_action(
"$N��$t˵������С�ֵܼ����ķᣬֻ�¿������������Ǯ�ɡ���\n",who);
				return;
			}
			p_id=this_body()->query_userid();
			if(member_array(p_id, name_list) != -1)
			{
				this_object()->targetted_action(
"$N��$t�ź���˵�������������ҵ���ȫ��С�ֵ��ˣ��� . . .��\n",who);
				return;
			}
			name_list+=({ p_id });
			ob=new(M_GOLD);
			ob->set_m_num(3);
			ob->move(who);
			this_object()->targetted_action(
"$N��$t˵��������������֮����Ҳ����Ե����㱡��������С�ֵ���ɰ�ҵ��\n",who);
			this_object()->targetted_action("$N��$tһЩ�ƽ�\n",who);
			return;
		case "shouming" :
			p_money=who->query_shouming();
			s_tmp=chinese_number(p_money);
			this_object()->simple_action("$N��ָ������\n");
			this_object()->targetted_action(
"$N��$tС��˵������$R���и�֮�ˣ���������"+s_tmp+"�ꡣ��\n",who);
			return;
		case "jbsj" : // ����ˮ��
			learn_sj(who);
			return ;
			
		case "luoyang" :
			this_object()->simple_action("$NЦ�����������˸��Σ���������Ի��\n
	�ȹ���ѣ�������ȼ���ҵ�ʯĥ��������֮��
	�µ��ܶ����õ����飬ϰ����������Ҫʮ����
	�ݼ��ܷ�����ؾ�������ȥ�������޳�ɷ�Ҳ����\n");
			return;
	}
}
