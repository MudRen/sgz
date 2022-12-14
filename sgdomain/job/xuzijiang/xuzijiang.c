#include <mudlib.h>
#include <ansi.h>

#define XIANREN __DIR__"xianren.c"

inherit LIVING;
inherit M_CHAR;
inherit "/sgdomain/modules/m_charnpc/xianren/xianren_act";
inherit M_SMARTMOVE; // so it can move

int check_job(object who);
int check_cancel(object who);
void check_ob();
void do_learn(string sk, int lvl, string ans);
void answer_skills(object ob);
void check_skills(string *sks, string ans);

void setup()
{
	object cloth;
	cloth = new("/sgdomain/obj/cloth/torso/hechang.c");
        cloth->move(this_object());
	cloth->do_wear();
	set_name("xu zijiang", "许邵");
	add_id("xu");
	set_gender(1);
	set_age(80);
	set_proper_name(HIY+"流浪的仙人"+NOR+"许邵(xu zijiang)");
	set_in_room_desc(HIY+"流浪的仙人"+NOR+"许邵(xu zijiang)");
	add_question("job", "job");
	add_ask_str("job", "$N向$T躬身问道：先生，可有吩咐？\n");
	add_question("cancel", "cancel");
	add_ask_str("cancel","$N满脸赤红的对$T道：先生任务实在是太难。。。。\n");
	add_question("skills", "skills");
        add_ask_str("skills","$N向$T躬身问道：不知先生有合本领？\n");
      	clear_chat(); // clear default chat
        add_chat("临渊羡鱼，不如退而结网也。");
        add_chat("单者易折，众则难摧。戮力一心，则社稷可固也。");
	call_out("check_ob", 60);
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
	mapping job;
	object xianren;

	job = who->query_job("xu zijiang", "");
	if( job || mapp(job) ){
		if( job["beg_time"] > 0 ){
			this_object()->targetted_action("$N生气的对$T哼了一声：上次的活还没干完呢！\n", who); 
			return 0;
		}
		if( sizeof(job["lasttimes"])>20 ){
			this_object()->targetted_action("$N满脸堆笑的说：$R应该休息一会啦。\n",who);
			return 0;
		}
	}

	who->resign_job("xu zijiang");
	who->add_job("xu zijiang");

	xianren = new(XIANREN);
	xianren->move(environment(this_object()));
	xianren->set_leader(who->query_id()[0]);
	xianren->set_in_room_desc(who->query_id()[1]+"正带领着这位贤人到出游历。");

	this_object()->responda("nod");
	this_object()->simple_action("$N道：就请你带这位贤人到处走走吧。\n");
	xianren->simple_action("$N慢腾腾的走了出来。\n");
	xianren->do_consider();
	return 1;
}
void check_ob()
{
	object *obs;

	obs = children("/sgdomain/job/xuzijiang/xianren.c");
	remove_call_out("check_ob");
	foreach(object oo in obs){
		if( oo->query_leader() ) oo->do_consider();
	}
	call_out("check_ob", 60);
}
int check_cancel(object who)
{
	mapping job;

	job = who->query_job("xu zijiang", "");

	if( !job || !mapp(job) )
		this_object()->targetted_action("$N对$T惊讶的说：在下从未要您做过什么吧？",who);
	else if(  job["beg_time"] <= 0 )
		this_object()->targetted_action("$N对$T惊讶的说：您的任务已经完成了！\n",who);
	else if( time() - job["beg_time"] < 1800 )
		this_object()->targetted_action("$N对$T生气的说：先好好反省一会再来见我吧。\n", who);
	else {
		this_object()->responda("sigh2");
		this_object()->targetted_action("$N对$T生气的说：这点小事也办不好！\n", who);
		who->finish_job("xu zijiang");
	}

	return 1;
}
void answer_skills(object ob)
{
	string msg  = "";
	string *sks = ({"hunluan", "shoushi", "tianbian", "fengbian","zhanbu" });
	
	foreach(string s in sks) msg+=SG_SKILL_D->query_name(s)+"("+s+")，\n";
	this_object()->targetted_action("$N对$T大笑了几声道：老朽不才，但对\n"+msg+"诸计颇有些心得！\n",ob);
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
