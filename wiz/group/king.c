// accountant ���׵�
#include <ansi.h>
#include <mudlib.h>
#define EV_KING "/sgdomain/event/ev_king.c"
inherit M_OUT;
inherit LIVING;

object usr;
int starttime;
int money,t_money,rep;
void input_way(string arg);
void ask_baijian(object usrk);
void award();
void setup()
{
   object jia;
   jia=new(PTORSO+"longpao");
   jia->move(this_object());
   jia->do_wear();
   set_name("han di", "���׵�");
   set_in_room_desc("���׵�(han di)");
   set_long(
       "�������һ���ʵۡ�\n");
   set_gender(1);
   set_age(24);
   set_sg_rongmao(20);
   add_question("baijian", "baijian");
   add_ask_str("baijian","$N�����أ�������$T������ߵ�����ϣ�\n");
}

mixed special_answer(object ob, string str)
{
   object player;
   player = this_body();
   switch(str)
   {
      case "baijian":
          ask_baijian(player);
          return;
      default:
         return ;
    }
}
void ask_baijian(object usrk)
{
    string n_id, mess;	
	
    usr=usrk;	
    n_id=usr->query_id()[0];
    if (EV_KING->query_name()!=n_id)
   {
	this_object()->simple_action(
	"$N�������˲�δ�ټ����㣬������˺��£�\n");
	return;
   }
else
{
    EV_KING->remove_name();	 			
    this_object()->simple_action("$N����������������һ�����⡣\n");
    ROBOT->robot_test(usr,(:award:));
}
}
void award()
{   
    int isrobot, repred,rank,t_rep,t_skills,t_gold;
    int level,exp,ntime;
    string n_id, mess;
    object player;
    string pskills, *skills;
    string* p_skills;

    n_id=usr->query_id()[0];		
    isrobot=usr->query_robot();
    if(isrobot)
    {   this_object()->simple_action(
         "$N�����󵨣������û�������ƭ���ˣ�\n");
    	rep=CHAR_D->get_char(n_id,"reputation");
	repred=rep/20;
	if (repred>15000)repred=15000;
	CHAR_D->set_char(n_id,"reputation",rep - repred);
	mess=CHAR_D->get_char(n_id,"name")+"�û�������ƭ�׵ۣ���������"
+chinese_number(repred)+"�㡣";
	}
    else
    {	rep=CHAR_D->get_char(n_id,"reputation");
	rank=CHAR_D->get_char(n_id,"localcontribution");
	money=CHAR_D->get_char(n_id,"gold");
	p_skills=usr->query_self_skills();
	pskills = p_skills[random(sizeof(p_skills))];
	level = usr->query_sk_level(pskills);
	exp = usr->query_sk_exp(pskills);	
	starttime=EV_KING->query_time();
	ntime=time();
	
	if ((ntime-starttime)<60)
	{	
	t_rep=100+random(400);
        rep=rep+t_rep;
        this_object()->simple_action("$NЦ���������ڷ���ʵ����������"
+chinese_number(t_rep)+"������������Ŭ����и��\n",usr);
        CHAR_D->set_char(n_id,"reputation",rep);
        mess =CHAR_D->get_char(n_id,"name")+"�����׵ۣ��ڷ���ʵ��ϲ������"
+chinese_number(t_rep)+"�㡣";
	}
else
{
	if (money>50000)
	{t_money = 300 + random(money/100);
	 
	this_object()->simple_action("$N˵�����ã����˽�����ͷ�Ľ���
�����Ƿ�ɽ��׻ƽ�"+chinese_number(t_money)+"����\n");
	usr->modal_push((: input_way:),"���������ѡ��(yes/no)��");
return;
	}
	else if (rep>100000)
	{
	t_rep=100+random(400);
	rep=rep+t_rep;
	this_object()->simple_action("$NЦ������������ȵ�𣬿�ϲѽ��ϲ��
��������"+chinese_number(t_rep)+"������������Ŭ����и��\n",usr);
	CHAR_D->set_char(n_id,"reputation",rep);
	mess =CHAR_D->get_char(n_id,"name")+"�����׵ۣ�ϲ������"
+chinese_number(t_rep)+"�㡣";
	}
	
	else if (rank >1500 && sizeof(p_skills))
	{
	t_skills=200+random(500);
	exp= exp + t_skills;
	usr->set_sg_skill(pskills, level, exp);
	this_object()->simple_action("$NЦ�������乤�����࣬������"
+SG_SKILL_D->query_name(pskills)+"����"+chinese_number(t_skills)+"�㣬���ʹ�����\n");
	mess =CHAR_D->get_char(n_id,"name")+"�����׵ۣ�ϲ��"
+SG_SKILL_D->query_name(pskills)+"����"+chinese_number(t_skills)+"�㡣";
	}
	else{
	t_gold=10+random(40);
	CHAR_D->set_char(n_id,"gold", money+t_gold);
	this_object()->simple_action("$N̾�������仹��Ŭ����и�������������"
+chinese_number(t_gold)+"���ƽ������ٽ�����\n");
	mess = CHAR_D->get_char(n_id,"name")+"�����׵ۣ����ͻƽ�"
+chinese_number(t_gold)+"����";
	}
	}
}	
	CHANNEL_D->deliver_tell("rumor","system",mess);
	return;
	}

void input_way(string arg)
{
	string mess,n_id;
	int rep1, repd;
	
	n_id=usr->query_id()[0];
	if (arg=="yes")
{	CHAR_D->set_char(n_id,"gold",money-t_money);
	this_object()->simple_action("$NЦ�������Ͱ����ˡ�");
	CHAR_D->set_char(n_id,"reputation",rep+2*t_money);
	rep1 = 2* t_money;
	mess=CHAR_D->get_char(n_id,"name")+"�����׵ۣ�����"
+chinese_number(t_money)+"�ƽ𣬵õ�����"+chinese_number(rep1)+"�㡣";
}	
	else{ 
	if (arg=="no")
	{	
	this_object()->simple_action("$N������Ȼ��ˣ�Ҳ�Ͱ��ˡ�");
	CHAR_D->set_char(n_id,"reputation",rep-0.2*t_money);
	repd=0.2*t_money;
	if (repd>15000) repd=15000;
	mess=usr->query_id()[1]+"�����׵ۣ���ֹʧ����ʧ����"
+chinese_number(repd)+"�㡣";
	}
	else return;
	}
	CHANNEL_D->deliver_tell("rumor","system",mess);
	usr->modal_pop();	
}
