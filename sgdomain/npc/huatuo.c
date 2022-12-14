#include <mudlib.h>
#include <ansi.h>
#define HUA_TOOL __DIR__"hua_tool.c"

// this is used to make the char active
inherit "/sgdomain/modules/m_charnpc/xianren/xianren_act";
inherit LIVING;
inherit M_CHAR;
inherit M_SMARTMOVE; // so it can move

int check_job(object who);
int check_cancel(object who);
int do_award(object who);

void do_learn(string sk, int lvl, string ans);
void answer_skills(object ob);
void check_skills(string *sks, string ans);

void setup()
{
	object cloth;
        cloth = new("/sgdomain/obj/cloth/torso/hechang.c");
        cloth->move(this_object());
        cloth->do_wear();

	set_name("hua tuo", "华陀");
	add_id("huatuo");
	set_gender(1);
	set_age(60);
	set_proper_name(HIY+"流浪的仙人"+NOR+"华陀(hua tuo)");
        set_in_room_desc(HIY+"流浪的仙人"+NOR+"华陀(hua tuo)");
	add_question("job", "job");
        add_ask_str("job", "$N向$T躬身问道：先生，可有吩咐？\n");
	add_question("cancel", "cancel");
	add_ask_str("cancel","$N满脸赤红的对$T道：先生任务实在是太难。。。。\n");
	add_question("skills", "skills");
	add_ask_str("skills","$N向$T躬身问道：不知先生有合本领？\n");
   	clear_say(); // clear the default say
      	add_say("谁要是能邦我找些草药就好了。\n"); // add say, can add more
      	clear_chat(); // clear default chat
        add_chat("曹操，奸臣也，逆天行事，安得长寿？");
      	add_chat("明者防祸于未萌，智者图患于将来。");
     	call_out("my_heart",1); // begin my heart
}
mixed special_answer(object ob, string str)
{
        if( str == "job" ) check_job( ob );
	else if( str == "cancel" ) check_cancel( ob );
	else if( str == "skills" ) answer_skills( ob );
 	else return ::special_answer(ob, str);
}
int check_job(object who)
{
	int i, j;
	mapping job;
        object tool;
	string area, *areas, *color, *taste;

	color = ({"白色", "兰色", "青色", "红色", "黑色", "无色", "彩色", });
	taste = ({"无味", "苦味", "甜味", "酸味", "辣味", "涩味", "臭味", });
	job = who->query_job("hua tuo", "");

	if( job || mapp(job) )
	{
		if( job["beg_time"] > 0 )
		{
			this_object()->targetted_action("$N生气的对$T哼了一声：上次的活还没干完呢！\n", who);
                        return 0;
        }
        
        n_lasttimes=usr->query_job(JOBID,"count_lasttimes");
        m_lasttimes=JOB_D->query_job(JOBID,"count_lasttimes");
		
		if( sizeof(job["lasttimes"]) > 20 ){
			this_object()->targetted_action("$N满脸堆笑的说：$R应该休息一会啦。\n",who);
                        return 0;
		}
        }

	who->resign_job("hua tuo");
        who->add_job("hua tuo");
	tool = new(HUA_TOOL);
	tool->move(who);
	this_object()->targetted_action("$N对$T点了点头：来的正好，去帮我找点草药吧。\n", who);
	this_object()->targetted_action("$N递给$T一把小药锄。\n", who);

	i = random(sizeof(color));
	j = random(sizeof(taste));
	who->set_job("hua tuo", "color", i);
	who->set_job("hua tuo", "taste", j);

	areas = AREA_D->list_areas();
	area = areas[random(sizeof(areas))];
	this_object()->simple_action("$N道：这种药草是"+color[i]+taste[j]+"的，你要找仔细了。\n");
	this_object()->simple_action("$N道：去"+AREA_D->get_area(area, "name")+"一带找找吧。\n");
        who->set_job("hua tuo", "memo", color[i]+taste[j]+"的药草("+AREA_D->get_area(area, "name")+")");
	who->set_job("hua tuo", "area", area);

	return 1;
}
mixed indirect_give_obj_to_liv(object ob, object liv)
{
	string name;
	object who;
	mapping job;

	who  = this_body();
	name = who->query_id()[0];
	job  = who->query_job("hua tuo", "");

	if( job["beg_time"] <= 0 ){
		destruct(ob);
		return this_object()->short()+"衷心地道谢。\n";
	};
	if( ob->query(who->query_id()[0]) == "ok" ){ 
		this_object()->responda("admire");
		who->finish_job("hua tuo");
		who->set_job("hua tuo", "place", ({ }));
                destruct(ob);
		ROBOT->robot_test(who, (: do_award :) );
		return this_object()->short()+"衷心地道谢。\n";
	} else {
		destruct(ob);
		responda("heng");
		return this_object()->short()+"道：这是什么东西？\n";
	}

}
int do_award(object who)
{
	int rep, gold, point;
	string name, *sks, skill;

	name = who->query_primary_id();
	rep  = 50+random(50);
	gold = 10000+random(15000);	
	sks  = keys(who->get_sg_skills());
	if( who->query_robot() ){
		write("抱歉，错误的答案，没有任何奖励，下次再努力吧！\n");
                return 2;
        } else {
		this_object()->tegetted_action("$N拍着$T的肩膀道：好样的！\n", who);
                CHAR_D->set_char(name, "reputation",
                        CHAR_D->get_char(name,"reputation")+rep);
                who->set_all_con_money(who->query_all_con_money()+gold);
		write("你被奖励了"+chinese_number(gold/100)+"两白银。\n");
        	write("你的声望提高了"+chinese_number(rep)+"。\n");
		if( !sks||!arrayp(sks)||!sizeof(sks) ) return 1;
        	sks = filter_array(sks, (: SG_SKILL_D->query_type($1)==4 :));
        	if( !sks||!arrayp(sks)||!sizeof(sks) ) return 1;
        	skill = sks[random(sizeof(sks))];
        	point = who->query_job("hua tuo", "count");
        	if( point>200 ) point = 200;
        	point = point + 50 + random(50);

        	who->award_exp(point ,skill);
        	write("你的%^H_CYAN%^"+SG_SKILL_D->query_name(skill)+"%^RESET%^提高了"
                	+chinese_number(point)+"点！\n");
	}
	return 1;
}
int check_cancel(object who)
{
	mapping job;

        job = who->query_job("hua tuo", "");
        if( !job || !mapp(job) )
		this_object()->targetted_action("$N对$T惊讶的说：在下从未要您做过什么吧？\n",who);
        else if(  job["beg_time"] <= 0 )
		this_object()->targetted_action("$N对$T惊讶的说：您的任务已经完成了！\n",who);
        else if( time() - job["beg_time"] < 1800 )
		this_object()->targetted_action("$N对$T生气的说：先好好反省一会再来见我吧。\n", who);
        else {
                this_object()->responda("sigh2");
		this_object()->targetted_action("$N对$T生气的说：这点小事也办不好！\n",who);
                who->finish_job("hua tuo");
		who->set_job("hua tuo", "place", ({ }));
        }

        return 1;
}

void answer_skills(object ob)
{
	string msg  = "";
	string *sks = ({"jiaoma", "guwu", "shidu", "jiedu", "chenzhuo", });
	
	foreach(string s in sks) msg+=SG_SKILL_D->query_name(s)+"("+s+")，\n";
	this_object()->targetted_action("$N对$T大笑了几声道：老朽不才，但对\n"+msg+"诸计颇有些心得！\n", ob);
	ob->modal_push((: check_skills, sks:), "你对那一种计谋感兴趣呢？");
}
void check_skills(string *sks, string ans)
{
	int level;

	this_body()->modal_pop();
	if( !ans||ans==""||!stringp(ans)||member_array(ans,SG_SKILL_D->query_skills())==-1 )
		write("没有这种计谋！\n");
	else if( member_array(ans, sks)==-1 )
		write(this_object()->short()+"不会这种计谋！\n");
	else if( !(level=this_body()->query_sk_level(ans)) )
		write("你并不会这种计谋！\n");
	else if( level>=100 )
		write("已经没有人可以教你了！\n");
	else {
		this_body()->modal_push((: do_learn, ans, level:),
			"\n花费"+chinese_number((level+1)*2+1)+"两金学习吗？\n决定了的话请输入yes。");
	}
}
void do_learn(string sk, int lvl, string ans)
{
        int money;
        mixed tmp;
        object who;

        this_body()->modal_pop();
        this_body()->start_busy(5, "你正忙着学习呢！\n");
        who=this_body();
        money=((lvl+1)*2+1)*10000;

        if( !ans||!stringp(ans)||ans!="yes" )
                write("不想学，算了！\n");
        else if( (this_body()->query_all_con_money())<money )
                write("你那有哪么多钱！\n");
        else if( (tmp=LEARNCHECK_D->check_can_learn_skills(sk, lvl+10))==TOO_TIRED )
                this_object()->targetted_action("$N对$T笑道：“你太累了！\n",who);
	else if( tmp==LESS_LITERATE )
		this_object()->targetted_action("$N对$T道：你的文学修养不够，有些道理听不明白的。\n",who);
        else if( tmp==LESS_EXP )
                this_object()->targetted_action("$N对$T笑到：“经验不够，只怕神仙也教不会你呀。”\n",who);
        else if( tmp==15 )
                this_object()->targetted_action("$N对$T笑到：你学了太多种计谋了！\n", who);
        else {
                who->set_all_con_money(who->query_all_con_money()-money);
                who->responda("ok");
        }
}
