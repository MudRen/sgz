// accountant 汉献帝

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
   set_name("han xiandi", "汉献帝");
   set_in_room_desc("汉献帝(han xiandi)");
    add_id("emperor");
   set_gender(1);
   set_age(24);
   add_question("baijian", "baijian");
   add_question("mizhao", "mizhao");    
   add_question("fengjue","fengjue");
   add_ask_str("baijian","$N单足跪地，朗声向$T道：臣叩见皇上！\n");
   add_ask_str("mizhao","$N单足跪地，朗声向$T道：臣叩见皇上！\n");
   add_ask_str("fengjue","$N单足跪地，沉声说道：臣为陛下鞠躬尽瘁，今望能得一爵位，请陛下成全。\n");
   call_out("call_event", 5);
}
string long() {
	return "
汉朝最后一个皇帝。
只见汉献帝：
身穿%^H_YELLOW%^锦衣龙袍%^RESET%^(longpao)。\n";
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
		return "$N对$T怒道：朕要的"+OBJ_D->get_obj(f_id,"name")+
			"怎么还没搞到呀。\n";
	}
	cur_ju=CHAR_D->get_char(p_id,"ju");
	if(cur_ju>=10)
		return "$N对$T道：$R的爵位已经到顶，难道要窜我的位不成。\n";
	rep_req=CHENGHU_D->query_ju_rep(cur_ju);
	if(CHAR_D->get_char(p_id,"reputation")<rep_req) 
		return "$N对$T说道：$R声望尚未达到进爵的要求，还是再多多努力吧。\n";
	lit_req=CHENGHU_D->query_ju_lit(cur_ju);
	if(lit_req>ply->query_literate())
		return "$N对$T说道：$R文学尚未达到进爵的要求，还是再多多努力吧。\n";
	foods=OBJ_D->check_obj("type","food");
	drinks=OBJ_D->check_obj("type","drink");
	foods+=drinks;
	f_id=foods[random(sizeof(foods))];
	if(!sizeof(OBJ_D->get_obj_maker(f_id)))
		f_id="blchun";
	fj_food[p_id]=f_id;
		return 
"$N对$T点点头，说道：$R的忠心朕很清楚，只要爱卿帮我做一件事情，定能加官封爵。\n"+
"帝又说道：朕听说当今世上有种叫"+OBJ_D->get_obj(f_id,"name")+"的东西很是美味，爱卿就帮我找回来吧。\n";
}
void prepare_fengjue(object ply) {
	string p_id,f_id;
	object o_fd;
	int ju;
	p_id=ply->query_primary_id();
	f_id=fj_food[p_id];

	o_fd=present(f_id,ply);

	this_object()->targetted_action("$N从$T手中接过$O。\n",ply,o_fd);
	destruct(o_fd);
	map_delete(fj_food,p_id);
	this_object()->targetted_action(
	  "$N大喜过望，对$T点点头：既然$R如此忠心，朕就封你一个爵位吧。\n",ply);

	ju=CHAR_D->get_char(p_id,"ju");
	if( ju<3 ){ 
		CHAR_D->set_char(p_id,"ju",ju+1);
		this_object()->targetted_action(	
"$N对$T说道：好，朕就封$R为"+CHENGHU_D->query_char_jun (p_id) +"。\n",ply);
		CHANNEL_D->deliver_tell("gossip",this_object()->short(),
CHAR_D->get_char(p_id,"name")+"对朕忠心耿耿，劳苦功高，现在朕就封"+
CHAR_D->get_char(p_id,"name")+"为"+CHENGHU_D->query_char_jun (p_id)+"。");
	} else {
		this_object()->targetted_action("$N对$T笑道：不知你要讨个怎样的封号呢？\n",ply);
		write("answer 封号 to han di\n");
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
		write("你的封号太长了，想一个短一点的吧！\n");
		return;
	};
	for(i=0; i<sizeof(ans); i++){
		if( ans[i]<122&&ans[i]>40 ) {
			write("只能用汉字，不可使用英文字符！\n");
			return;
		}
	}
	if( (sizeof(ans)%2) ){
		write("“  "+ans+"  ”不是完整的汉字！\n");
		return;
	}
	if( ju>6 ) CHAR_D->set_char(id, "ju_n", tmp );
	else CHAR_D->set_char(id, "ju_n", ans);
	this_object()->clear_answer();
	CHAR_D->set_char(id,"ju",ju);
	CHANNEL_D->deliver_tell("gossip",this_object()->short(),CHAR_D->get_char(id,"name")+"对朕忠心耿耿，劳苦功高，现在朕就封"+CHAR_D->get_char(id,"name")+"为"+CHENGHU_D->query_char_jun (id)+"。");

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
        "$N道：寡人并未召见于你，卿家来此何事？\n");
        return;
   }
        else
{   n_city = EV_KWAR->query_city();
    n_city = AREA_D->get_area(n_city,"name");   
    this_object()->simple_action
	("$N道：寡人此次召见于你，是有一事相求。\n");
    this_object()->simple_action("$N道：望你攻下"+n_city+"，以显我大汉国威。\n");
    this_object()->simple_action("$N道：祝你马到功成。\n");
    mess =CHAR_D->get_char(n_id,"name")+"晋见献帝，接收秘旨。";
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
    string n_id,mess;
    object player;
    object sy;
    string pskills;
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
        this_object()->simple_action("$N笑道：爱卿勤奋朴实，朕再赠你"
        +chinese_number(t_rep)+"点声望，望你努力不懈。\n",usr);
        CHAR_D->set_char(n_id,"reputation",rep);
        mess =CHAR_D->get_char(n_id,"name")+"晋见献帝，勤奋朴实，喜得声望"
        +chinese_number(t_rep)+"点。";
        }
else
{
        if (money>3000)
        {t_money = 100 + random(money/50);
         
        this_object()->simple_action("$N说到：好！寡人近来手头颇紧，爱卿是否可进献黄金"+
		chinese_number(t_money)+"两？\n");
	        usr->modal_push((: input_way:),"请输入你的选择(yes/no)：");
	        return;
        }
        else if (rep>100000)
        {
        t_rep=1000+random(3000);
        rep=rep+t_rep;
        this_object()->simple_action("$N笑道：爱卿声名鹊起，可喜呀可喜。朕再赠你"
                +chinese_number(t_rep)+"点声望，望你努力不懈。\n",usr);
        CHAR_D->set_char(n_id,"reputation",rep);
        mess =CHAR_D->get_char(n_id,"name")+"晋见献帝，喜得声望"
                +chinese_number(t_rep)+"点。";
        }
        
        else if (rank >1000 && sizeof(p_skills))
        {
        t_skills=200+random(500);
        exp= exp + t_skills;
        usr->set_sg_skill(pskills, level, exp);
        this_object()->simple_action("$N笑道：爱卿工作辛苦，朕赏你"
        +SG_SKILL_D->query_name(pskills)+"技能"+chinese_number(t_skills)+
		"点，以资鼓励。\n");
        mess =CHAR_D->get_char(n_id,"name")+"晋见献帝，喜得"
	+SG_SKILL_D->query_name(pskills)+"技能"+chinese_number(t_skills)+"点。";
        }
        else{
        t_gold=10+random(20);
        CHAR_D->set_char(n_id,"gold", money+t_gold);
        this_object()->simple_action("$N叹道：爱卿还需努力不懈。这次朕且赏你"
		+chinese_number(t_gold)+"两黄金，望你再接再厉\n");
        mess = CHAR_D->get_char(n_id,"name")+"晋见献帝，受赏黄金"
		+chinese_number(t_gold)+"两。";
        }
        }
        sy=new(SHOYU);
        player=usr->query_body();
        if(!objectp(player)) return;
        {
                sy->move(player);
                this_object()->targetted_action(
		"$N对$T道：朕知爱卿聪慧好学，特赐手谕一张，卿家可皇宫内四处走走。\n",player);

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
        	this_object()->simple_action("$N笑道：有劳爱卿了。");
	        CHAR_D->set_char(n_id,"reputation",rep+2*t_money);
        	rep1 = 2* t_money;
	        mess=CHAR_D->get_char(n_id,"name")+"晋见献帝，献上"
		+chinese_number(t_money)+"黄金，得到声望"+chinese_number(rep1)+"点。";


	        sy=new(SHOYU);
        	player=usr->query_body();
	        if(!objectp(player)) return;
	        {
        	        sy->move(player);
	                this_object()->targetted_action(
			"$N对$T道：朕知爱卿聪慧好学，特赐手谕一张，卿家可皇宫内四处走走。\n",player);

		}       

	}       
        else{ 
        if (arg=="no")
        {       
        this_object()->simple_action("$N道：既然如此，也就罢了。");
        repd= 0.2*t_money;
        rep = rep - repd;
        CHAR_D->set_char(n_id,"reputation",rep);
        if (repd>15000) repd=15000;
        mess=usr->query_id()[1]+"晋见献帝，举止失礼，损失声望"
	+chinese_number(repd)+"点。";
        }
        else return;
        }
        CHANNEL_D->deliver_tell("rumor","system",mess);
        usr->modal_pop();       
}
