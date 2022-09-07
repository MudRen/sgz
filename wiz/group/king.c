// accountant 汉献帝
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
   set_name("han di", "汉献帝");
   set_in_room_desc("汉献帝(han di)");
   set_long(
       "汉朝最后一个皇帝。\n");
   set_gender(1);
   set_age(24);
   set_sg_rongmao(20);
   add_question("baijian", "baijian");
   add_ask_str("baijian","$N单足跪地，朗声向$T道：臣叩见皇上！\n");
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
	"$N道：寡人并未召见于你，卿家来此何事？\n");
	return;
   }
else
{
    EV_KING->remove_name();	 			
    this_object()->simple_action("$N道：寡人先来问你一个问题。\n");
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
         "$N道：大胆！竟敢用机器人蒙骗寡人！\n");
    	rep=CHAR_D->get_char(n_id,"reputation");
	repred=rep/20;
	if (repred>15000)repred=15000;
	CHAR_D->set_char(n_id,"reputation",rep - repred);
	mess=CHAR_D->get_char(n_id,"name")+"用机器人蒙骗献帝，声望降低"
+chinese_number(repred)+"点。";
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
        this_object()->simple_action("$N笑道：爱卿勤奋朴实，朕再赠你"
+chinese_number(t_rep)+"点声望，望你努力不懈。\n",usr);
        CHAR_D->set_char(n_id,"reputation",rep);
        mess =CHAR_D->get_char(n_id,"name")+"晋见献帝，勤奋朴实，喜得声望"
+chinese_number(t_rep)+"点。";
	}
else
{
	if (money>50000)
	{t_money = 300 + random(money/100);
	 
	this_object()->simple_action("$N说到：好！寡人近来手头颇紧，
爱卿是否可进献黄金"+chinese_number(t_money)+"两？\n");
	usr->modal_push((: input_way:),"请输入你的选择(yes/no)：");
return;
	}
	else if (rep>100000)
	{
	t_rep=100+random(400);
	rep=rep+t_rep;
	this_object()->simple_action("$N笑道：爱卿声名鹊起，可喜呀可喜。
朕再赠你"+chinese_number(t_rep)+"点声望，望你努力不懈。\n",usr);
	CHAR_D->set_char(n_id,"reputation",rep);
	mess =CHAR_D->get_char(n_id,"name")+"晋见献帝，喜得声望"
+chinese_number(t_rep)+"点。";
	}
	
	else if (rank >1500 && sizeof(p_skills))
	{
	t_skills=200+random(500);
	exp= exp + t_skills;
	usr->set_sg_skill(pskills, level, exp);
	this_object()->simple_action("$N笑道：爱卿工作辛苦，朕赏你"
+SG_SKILL_D->query_name(pskills)+"技能"+chinese_number(t_skills)+"点，以资鼓励。\n");
	mess =CHAR_D->get_char(n_id,"name")+"晋见献帝，喜得"
+SG_SKILL_D->query_name(pskills)+"技能"+chinese_number(t_skills)+"点。";
	}
	else{
	t_gold=10+random(40);
	CHAR_D->set_char(n_id,"gold", money+t_gold);
	this_object()->simple_action("$N叹道：爱卿还需努力不懈。这次朕且赏你"
+chinese_number(t_gold)+"两黄金，望你再接再厉\n");
	mess = CHAR_D->get_char(n_id,"name")+"晋见献帝，受赏黄金"
+chinese_number(t_gold)+"两。";
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
	this_object()->simple_action("$N笑道：有劳爱卿了。");
	CHAR_D->set_char(n_id,"reputation",rep+2*t_money);
	rep1 = 2* t_money;
	mess=CHAR_D->get_char(n_id,"name")+"晋见献帝，献上"
+chinese_number(t_money)+"黄金，得到声望"+chinese_number(rep1)+"点。";
}	
	else{ 
	if (arg=="no")
	{	
	this_object()->simple_action("$N道：既然如此，也就罢了。");
	CHAR_D->set_char(n_id,"reputation",rep-0.2*t_money);
	repd=0.2*t_money;
	if (repd>15000) repd=15000;
	mess=usr->query_id()[1]+"晋见献帝，举止失礼，损失声望"
+chinese_number(repd)+"点。";
	}
	else return;
	}
	CHANNEL_D->deliver_tell("rumor","system",mess);
	usr->modal_pop();	
}
