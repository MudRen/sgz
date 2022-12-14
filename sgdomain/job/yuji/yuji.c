#include <ansi.h>
#define YU_TOOL __DIR__"yu_tool.c"

inherit LIVING;
inherit M_CHAR;
inherit "/sgdomain/modules/m_charnpc/xianren/xianren_act";
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

        set_name("yu ji", HIY+"流浪的仙人"+NOR+"于吉");
        add_id("yuji");
        set_gender(1);
        set_age(72);
	set_proper_name(HIY+"流浪的仙人"+NOR+"于吉(yu ji)");
        set_in_room_desc(HIY+"流浪的仙人"+NOR+"于吉(yu ji)");

        add_question("job", "job");
        add_ask_str("job", "$N向$T躬身问道：先生，可有吩咐？\n");
        add_question("cancel", "cancel");
	add_ask_str("cancel","$N满脸赤红的对$T道：先生任务实在是太难。。。。\n");
	add_question("skills", "skills");
        add_ask_str("skills","$N向$T躬身问道：不知先生有合本领？\n");
      	clear_chat(); // clear default chat
        add_chat("工欲善其事，必先利其器也。");
        add_chat("大厦之将倾，非一木所支也。");
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
	object tool;
	string area, *areas, room, *rooms, memo;

	job = who->query_job("yu ji", "");
        if( job || mapp(job) ){
                if( job["beg_time"] > 0 ){
			this_object()->targetted_action("$N生气的对$T哼了一声：上次的活还没干完呢！\n", who);
                        return 0;
                }
                if( sizeof(job["lasttimes"]) > 20 ){
			this_object()->targetted_action("$N满脸堆笑的说：$R应该休息一会啦。\n",who);
                        return 0;
                }
        }
	
        who->resign_job("yu ji");
        who->add_job("yu ji");
        tool = new(YU_TOOL);
        tool->move(who);
	tool->set_in_room_desc("一根细短的青竹棒，上面刻着几个小字：于吉赠"+CHAR_D->get_char(who->query_id()[1], "name"));

	areas = AREA_D->list_areas();
	area  = areas[random(sizeof(areas))];
	rooms = AREA(area)->get_room("list");
	room  = rooms[random(sizeof(rooms))];
	memo  = AREA_D->get_area(area, "name")+"之"+AREA(area)->get_room(room,"b");

	who->set_job("yu ji", "job_type", "place");
	who->set_job("yu ji", "job_para", "/a/"+area+"/"+room);
	who->set_job("yu ji", "memo", memo);
	who->set_job("yu ji", "num", 1);
	who->set_job("yu ji", "stage", "start");

	this_object()->targetted_action("$N对着$T诡异的一笑：好吧，在下正有点小事要阁下帮忙。\n", who);
	this_object()->targetted_action("$N递给$T一根"+tool->short()+"。\n", who);
	this_object()->targetted_action("$N对$T道：就请你到"+memo+"走一趟吧！\n", who);

	return 1;
}
int check_cancel(object who)
{
        mapping job;

        job = who->query_job("yu ji", "");
        if( !job || !mapp(job) )
		this_object()->targetted_action("$N对$T惊讶的说：在下从未要您做过什么吧？\n",who);
        else if(  job["beg_time"] <= 0 )
		this_object()->targetted_action("$N对$T惊讶的说：您的任务已经完成了！\n",who);
        else if( time() - job["beg_time"] < 1800 )
		this_object()->targetted_action("$N对$T生气的说：先好好反省一会再来见我吧。\n", who);
        else {
                this_object()->responda("sigh2");
		this_object()->targetted_action("$N对$T生气的说：这点小事也办不好！\n",who);
                who->finish_job("yu ji");
        }

        return 1;
}
mixed indirect_give_obj_to_liv(object ob, object liv)
{
        string name;
        object who;
	mapping job;

	who  = this_body();
        name = who->query_id()[0];
	job  = who->query_job("yu ji", "");
	
	if( job["beg_time"] <= 0 ){
		destruct(ob);
                return this_object()->short()+"点了点头。\n";
	};
        if( ob->query(who->query_id()[0]) == "ok" ){
                this_object()->responda("admire");
                this_object()->responda("handshake");
                who->finish_job("yu ji");
                who->set_job("yu ji", "place", ({ }));
		who->tegetted_action("$N悄悄的把一根青竹棒递给$T，低声道：先生，东西到手了。\n", this_object());
                this_object()->tegetted_action("$N拍着$T的肩膀道：好样的！\n",who);
		ROBOT->robot_test(who, (: do_award :) );
		destruct(ob);
		return this_object()->short()+"「嘻嘻」笑了两声。\n";
        } else {
		destruct(ob);
                return this_object()->short()+"道：这是什么东西？\n";
        }
}
int do_award(object who)
{
	int gold, rep, point;
	string name, *sks, skill;

	name = who->query_id()[0];
	if( who->query_robot() ){
		write("抱歉，错误的答案，没有任何奖励，下次再努力吧！\n");
                return 2;
        } else {
		sks  = keys(who->get_sg_skills());
                gold = 40000+random(30000);
		rep  = 100+random(50);
               	CHAR_D->set_char(name, "reputation",
                        CHAR_D->get_char(name, "reputation")+rep);
                who->set_all_con_money(who->query_all_con_money()+gold);
		write("你被奖励了"+chinese_number(gold/100)+"两白银。\n");
        	write("你的声望提高了"+chinese_number(rep)+"。\n");
		if( !sks||!arrayp(sks)||!sizeof(sks) ) return 1;
        	sks = filter_array(sks, (: SG_SKILL_D->query_type($1)==4 :));
        	if( !sks||!arrayp(sks)||!sizeof(sks) ) return 1;
        	skill = sks[random(sizeof(sks))];
        	point = who->query_job("yu ji", "count");
		if( point>200 ) point = 200;
        	point = point + 50 + random(50);
		who->award_exp(point ,skill);
        	write("你的%^H_CYAN%^"+SG_SKILL_D->query_name(skill)+"%^RESET%^提高了"
                	+chinese_number(point)+"点！\n");
	}
	return 1;
}
void answer_skills(object ob)
{
	string msg  = "";
	string *sks = ({"maifu", "fenfa", "luanshe", "qibing" });
	
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
