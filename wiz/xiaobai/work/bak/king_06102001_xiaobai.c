// accountant ���׵�

#include <ansi.h>
#include <mudlib.h>
#define EV_KING "/sgdomain/event/ev_king.c"
#define EV_KWAR "/sgdomain/event/ev_kwar.c"
#define SHOYU "/sgdomain/obj/other/shoyu"

inherit M_OUT;
inherit LIVING;
inherit M_ANSI;

object usr;
int starttime;
int money,t_money,rep;

void input_way(string arg);
void ask_baijian(object usrk);
void award();
void ask_mizhao(object usrf);
void ask_title(object me, object who, string ans);

private mapping fj_food=([]);

void setup()
{
   set_name("han xiandi", "���׵�");
   set_in_room_desc("���׵�(han xiandi)");
    add_id("emperor");
   set_gender(1);
   set_age(24);
   add_question("baijian", "baijian");
   add_question("mizhao", "mizhao");    
   add_question("fengjue","fengjue");
   add_ask_str("baijian","$N�����أ�������$T������ߵ�����ϣ�\n");
   add_ask_str("mizhao","$N�����أ�������$T������ߵ�����ϣ�\n");
   add_ask_str("fengjue","$N�����أ�����˵������Ϊ���¾Ϲ����ᣬ�����ܵ�һ��λ������³�ȫ��\n");
   call_out("call_event", 5);
}
string long() {
	return "
�������һ���ʵۡ�
ֻ�����׵ۣ�
��%^H_YELLOW%^��������%^RESET%^(longpao)��\n";
}
void ev_king_call() {
	remove_call_out("ev_king_call");
	call_out("ev_king_call",50);
        EV_KING->recall();
}
void call_event()
{
        remove_call_out("call_event");
        EV_KWAR->recall();
	ev_king_call();
}
mixed ask_fengjue(object ply) {
	string p_id;
	string f_id;
	object o_fd;
	int rep_req,lit_req,cur_ju;
	string *foods,*drinks;

	p_id=ply->query_primary_id();
	f_id=fj_food[p_id];
	if(stringp(fj_food[p_id])) {
		o_fd=present(f_id,ply);
		if(objectp(o_fd)) return 1;
		return "$N��$Tŭ������Ҫ��"+OBJ_D->get_obj(f_id,"name")+
			"��ô��û�㵽ѽ��\n";
	}
	cur_ju=CHAR_D->get_char(p_id,"ju");
	if(cur_ju>=10)
		return "$N��$T����$R�ľ�λ�Ѿ��������ѵ�Ҫ���ҵ�λ���ɡ�\n";
	rep_req=CHENGHU_D->query_ju_rep(cur_ju);
	if(CHAR_D->get_char(p_id,"reputation")<rep_req) 
		return "$N��$T˵����$R������δ�ﵽ������Ҫ�󣬻����ٶ��Ŭ���ɡ�\n";
	lit_req=CHENGHU_D->query_ju_lit(cur_ju);
	if(lit_req>ply->query_literate())
		return "$N��$T˵����$R��ѧ��δ�ﵽ������Ҫ�󣬻����ٶ��Ŭ���ɡ�\n";
	foods=OBJ_D->check_obj("type","food");
	drinks=OBJ_D->check_obj("type","drink");
	foods+=drinks;
	f_id=foods[random(sizeof(foods))];
	if(!sizeof(OBJ_D->get_obj_maker(f_id)))
		f_id="blchun";
	fj_food[p_id]=f_id;
		return 
"$N��$T���ͷ��˵����$R�������޺������ֻҪ���������һ�����飬���ܼӹٷ����\n"+
"����˵��������˵�����������ֽ�"+OBJ_D->get_obj(f_id,"name")+"�Ķ���������ζ������Ͱ����һ����ɡ�\n";
}
void prepare_fengjue(object ply) {
	string p_id,f_id;
	object o_fd;
	int ju;
	p_id=ply->query_primary_id();
	f_id=fj_food[p_id];

	o_fd=present(f_id,ply);

	this_object()->targetted_action("$N��$T���нӹ�$O��\n",ply,o_fd);
	destruct(o_fd);
	map_delete(fj_food,p_id);
	this_object()->targetted_action(
	  "$N��ϲ��������$T���ͷ����Ȼ$R������ģ��޾ͷ���һ����λ�ɡ�\n",ply);

	ju=CHAR_D->get_char(p_id,"ju");
	if( ju<3 ){ 
		CHAR_D->set_char(p_id,"ju",ju+1);
		this_object()->targetted_action(	
"$N��$T˵�����ã��޾ͷ�$RΪ"+CHENGHU_D->query_char_jun (p_id) +"��\n",ply);
		CHANNEL_D->deliver_tell("gossip",this_object()->short(),
CHAR_D->get_char(p_id,"name")+"�������Ĺ������Ϳ๦�ߣ������޾ͷ�"+
CHAR_D->get_char(p_id,"name")+"Ϊ"+CHENGHU_D->query_char_jun (p_id)+"��");
	} else {
		this_object()->targetted_action("$N��$TЦ������֪��Ҫ�ָ������ķ���أ�\n",ply);
		write("answer ��� to han di\n");
		set_answer(ply->query_primary_id(), (:ask_title:) );
	}
	return;
}
void ask_title(object me, object who, string ans) // me is this_object()
{
	int i, ju;
	string id, title, tmp;
	
	id = who->query_primary_id();
	ju = CHAR_D->get_char(id,"ju");
	ju++;
	title = CHENGHU_D->query_ju_str(ju);
	title = colour_truncate(title, 10);
	if( ju>6 ){
		tmp = ans;
		ans = colour_truncate(ans, 10);
	};
	if( sizeof(ans)+sizeof(title) > 10 ) {
		write("��ķ��̫���ˣ���һ����һ��İɣ�\n");
		return;
	};
	for(i=0; i<sizeof(ans); i++){
		if( ans[i]<122&&ans[i]>40 ) {
			write("ֻ���ú��֣�����ʹ��Ӣ���ַ���\n");
			return;
		}
	}
	if( (sizeof(ans)%2) ){
		write("��  "+ans+"  �����������ĺ��֣�\n");
		return;
	}
	if( ju>6 ) CHAR_D->set_char(id, "ju_n", tmp );
	else CHAR_D->set_char(id, "ju_n", ans);
	this_object()->clear_answer();
	CHAR_D->set_char(id,"ju",ju);
	CHANNEL_D->deliver_tell("gossip",this_object()->short(),CHAR_D->get_char(id,"name")+"�������Ĺ������Ϳ๦�ߣ������޾ͷ�"+CHAR_D->get_char(id,"name")+"Ϊ"+CHENGHU_D->query_char_jun (id)+"��");

	return;
}
mixed special_answer(object ob, string str)
{
   object player;
   mixed ret;
   player = this_body();
   switch(str)
   {
      case "baijian":
          ask_baijian(player);
          return;
      case "mizhao":
          ask_mizhao(player);
          return;       
      case "fengjue" :
	  ret=ask_fengjue(player);
	  if(stringp(ret)) {
	     this_object()->targetted_action(ret,player);
	     return;
	  }
          prepare_fengjue(player);
 	  return;
      default:
         return ;
    }
}
void ask_mizhao(object usrf)
{
    string n_id, mess, n_city;

    usr=usrf;
    n_id=usr->query_id()[0];
    if (EV_KWAR->query_name()!=n_id)
   {
        this_object()->simple_action(
        "$N�������˲�δ�ټ����㣬������˺��£�\n");
        return;
   }
        else
{   n_city = EV_KWAR->query_city();
    n_city = AREA_D->get_area(n_city,"name");   
    this_object()->simple_action
	("$N�������˴˴��ټ����㣬����һ������\n");
    this_object()->simple_action("$N�������㹥��"+n_city+"�������Ҵ󺺹�����\n");
    this_object()->simple_action("$N����ף�������ɡ�\n");
    mess =CHAR_D->get_char(n_id,"name")+"�����׵ۣ�������ּ��";
    CHANNEL_D->deliver_tell("rumor","system",mess);
    return;
}

}
        
void ask_baijian(object usrk)
{
    string n_id;  
        
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
    string n_id,mess;
    object player;
    object sy;
    string pskills;
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
    {   rep=CHAR_D->get_char(n_id,"reputation");
        rank=CHAR_D->get_char(n_id,"localcontribution");
        money=CHAR_D->get_char(n_id,"gold");
        p_skills=usr->query_self_skills();
        pskills = p_skills[random(sizeof(p_skills))];
        level = usr->query_sk_level(pskills);
        exp = usr->query_sk_exp(pskills);       
        starttime=EV_KING->query_time();
        ntime=time();
        
        if ((ntime-starttime)<120)
        {       
        t_rep=400+random(400);
        rep=rep+t_rep;
        this_object()->simple_action("$NЦ���������ڷ���ʵ����������"
        +chinese_number(t_rep)+"������������Ŭ����и��\n",usr);
        CHAR_D->set_char(n_id,"reputation",rep);
        mess =CHAR_D->get_char(n_id,"name")+"�����׵ۣ��ڷ���ʵ��ϲ������"
        +chinese_number(t_rep)+"�㡣";
        }
else
{
        if (money>3000)
        {t_money = 100 + random(money/50);
         
        this_object()->simple_action("$N˵�����ã����˽�����ͷ�Ľ��������Ƿ�ɽ��׻ƽ�"+
		chinese_number(t_money)+"����\n");
	        usr->modal_push((: input_way:),"���������ѡ��(yes/no)��");
	        return;
        }
        else if (rep>100000)
        {
        t_rep=1000+random(3000);
        rep=rep+t_rep;
        this_object()->simple_action("$NЦ������������ȵ�𣬿�ϲѽ��ϲ����������"
                +chinese_number(t_rep)+"������������Ŭ����и��\n",usr);
        CHAR_D->set_char(n_id,"reputation",rep);
        mess =CHAR_D->get_char(n_id,"name")+"�����׵ۣ�ϲ������"
                +chinese_number(t_rep)+"�㡣";
        }
        
        else if (rank >1000 && sizeof(p_skills))
        {
        t_skills=200+random(500);
        exp= exp + t_skills;
        usr->set_sg_skill(pskills, level, exp);
        this_object()->simple_action("$NЦ�������乤�����࣬������"
        +SG_SKILL_D->query_name(pskills)+"����"+chinese_number(t_skills)+
		"�㣬���ʹ�����\n");
        mess =CHAR_D->get_char(n_id,"name")+"�����׵ۣ�ϲ��"
	+SG_SKILL_D->query_name(pskills)+"����"+chinese_number(t_skills)+"�㡣";
        }
        else{
        t_gold=10+random(20);
        CHAR_D->set_char(n_id,"gold", money+t_gold);
        this_object()->simple_action("$N̾�������仹��Ŭ����и�������������"
		+chinese_number(t_gold)+"���ƽ������ٽ�����\n");
        mess = CHAR_D->get_char(n_id,"name")+"�����׵ۣ����ͻƽ�"
		+chinese_number(t_gold)+"����";
        }
        }
        sy=new(SHOYU);
        player=usr->query_body();
        if(!objectp(player)) return;
        {
                sy->move(player);
                this_object()->targetted_action(
		"$N��$T������֪����ϻۺ�ѧ���ش�����һ�ţ���ҿɻʹ����Ĵ����ߡ�\n",player);

	}       
        CHANNEL_D->deliver_tell("rumor","system",mess);

        }       

        return;
}
void input_way(string arg)
{
        string n_id,mess;
        int rep1, repd;
	object sy,player;        
        n_id=usr->query_id()[0];
        if (arg=="yes")
	{       CHAR_D->set_char(n_id,"gold",money-t_money);
        	this_object()->simple_action("$NЦ�������Ͱ����ˡ�");
	        CHAR_D->set_char(n_id,"reputation",rep+2*t_money);
        	rep1 = 2* t_money;
	        mess=CHAR_D->get_char(n_id,"name")+"�����׵ۣ�����"
		+chinese_number(t_money)+"�ƽ𣬵õ�����"+chinese_number(rep1)+"�㡣";


	        sy=new(SHOYU);
        	player=usr->query_body();
	        if(!objectp(player)) return;
	        {
        	        sy->move(player);
	                this_object()->targetted_action(
			"$N��$T������֪����ϻۺ�ѧ���ش�����һ�ţ���ҿɻʹ����Ĵ����ߡ�\n",player);

		}       

	}       
        else{ 
        if (arg=="no")
        {       
        this_object()->simple_action("$N������Ȼ��ˣ�Ҳ�Ͱ��ˡ�");
        repd= 0.2*t_money;
        rep = rep - repd;
        CHAR_D->set_char(n_id,"reputation",rep);
        if (repd>15000) repd=15000;
        mess=usr->query_id()[1]+"�����׵ۣ���ֹʧ����ʧ����"
	+chinese_number(repd)+"�㡣";
        }
        else return;
        }
        CHANNEL_D->deliver_tell("rumor","system",mess);
        usr->modal_pop();       
}
