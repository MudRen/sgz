#include <mudlib.h>
#define JOB_MENU __DIR__"jobmenu.c"

inherit LIVING;
inherit M_CHAR;

private mapping leader;
private mapping player;

void check_job();
void check_order();
void do_consider();
void do_work(object who);
void do_award(object who, int many);

void setup()
{
        set_name("officer", "土地开发官员");
        add_id("land officer");
        set_in_room_desc("一位神采飞扬的土地开发官员(officer)");
        set_long("一位神采飞扬的官员(officer)");
        set_gender(1);
        add_question("order", "order");
        add_question("job", "job");
        add_ask_str("order","$N对$T大模大样的说：快召集人来，我要下命令啦。\n");
        add_ask_str("job", "$N向$T问道：现在有什么工作？\n");
	
	player = ([ ]);
	leader = ([ ]);

call_out("do_consider", 60);
}
mixed special_answer(object ob, string str)
{
	if( str == "job" ) check_job();
        else if( str == "order" ) check_order();
	else return ::special_answer(ob, str);
}
void check_job()
{
	string name, *names;
	mapping job;

	names = keys(player);
	name  = this_body()->query_id()[0];
	job   = this_body()->query_job("land_dp", "");

	if( !job||!mapp(job)||!sizeof(job) ) job = ([ ]);
	if( !names || !sizeof(names) )player = ([ ]);
	if( !leader || !sizeof(leader) )
		this_object()->targetted_action("$N对$T叹道：没有官员指导，你没法工作！\n",this_body());
	else if( member_array(name, keys(player) )!=-1 || job["beg_time"]>0 )
		this_object()->targetted_action("$N生气的对$T说：要干就干，别那么多废话！\n", this_body());
	else if( CHAR_D->get_char(name, "nation") )
		this_object()->targetted_action("$N对$T摇头道：大人怎可作这等工作。\n",this_body());
	else {
		player[name] = (["time":time(), ]);
		this_object()->targetted_action("$N点头道：好吧，开始工作吧。\n", this_body());
		this_body()->resign_job("land_dp");
		this_body()->add_job("land_dp");
		this_body()->set_job("land_dp", "time", time());
		this_body()->set_job("land_dp", "done", 0);
	}

	return;
}
void check_order()
{
	string name;
	mapping job;
	object menu;

	job  = this_body()->query_job("landlord", "");
	name = this_body()->query_id()[0];

	if( !job || !mapp(job) || !sizeof(job) )
		this_object()->targetted_action("$N对$T大喝一声：别捣乱，一边玩去。\n",this_body());
	else if ( job["beg_time"] <= 0 )
		this_object()->targetted_action("$N对$T迷惑的说：大人，您的任务已经完成了。\n", this_body());
	else if ( sizeof(job["lasttimes"]) > 5 )
		this_object()->targetted_action("$N对$T体贴的说：大人，您今天已经太劳累了。\n", this_body());
	else {
		if( !mapp(leader) || member_array(name, keys(leader)) == -1 ){
			leader[name] = (["time":time(),]);
			this_body()->set_job("landlord", "worker", ([]));
			this_body()->set_job("landlord", "quest", "");
			this_body()->set_job("landlord", "succ", 0);
			this_body()->set_job("landlord", "done", 0);
		}
		this_object()->targetted_action("$N对$T恭敬的说：大人，请下令！\n", this_body());
		new(JOB_MENU)->start_menu();
	};

	return;
}
void do_consider()
{
	int done;
	string ww, *objs, obj;
	mapping job, worker;
	object who, oo, *workers;

	string *good_news = ({"勤奋劳动，受到了大家的一致赞扬。",
			"一锄头挖下，哇！发现了一大锭金子。", 
			"喝了两口水，又精神百倍的干了起来。",
			"哼着小调，快乐的劳动着。", });
	string *bad_news = ({"一不小心被蛇咬了一口。",
			"一斧头砍在自己腿上。",
 			"偷偷的溜走了，躲在树下睡大觉。",
			"喝醉了，一个人在农田里打醉拳。"});

call_out("do_consider", 60);

	if( sizeof(player) ){
		workers = keys(player);
		foreach(ww in workers){
			who = CHAR_D->find_char(ww);
			if( !who->query_link() )continue;
			job = who->query_job("land_dp", "");
			if( job["beg_time"] <= 0 ) who->set_job("land_dp", "time", time());
			if( job["beg_time"] + 600 < time() ){
				tell_user(ww, "你的帮忙开发新田的任务完成了。\n");
				CHAR_D->set_char(ww, "reputation", CHAR_D->get_char(ww, "reputation")+5);
				who->set_all_con_money(this_body()->query_all_con_money()+job["done"]+100);
				who->finish_job("land_dp");
			};
		};
	};
	

	if( !sizeof(leader) )return;

	workers = keys(leader);
	foreach(ww in workers){
		who = CHAR_D->find_char(ww);
		if( !who->query_link() ){
			map_delete(leader, ww);
			continue;
		};
		job = who->query_job("landlord", "");
		if( job["beg_time"] + 900 > time() ){
			worker = job["worker"];
			if( sizeof(worker) ){
				done = 0;
				foreach(string ss in keys(worker)){
					if( !random(4) ){
						tell_user(ww, worker[ss]["name"]+bad_news[random(sizeof(bad_news))]+"\n");
						worker[ss]["eff"]-=1+random(2);
					} else if( !random(6) ){
						tell_user(ww, worker[ss]["name"]+good_news[random(sizeof(good_news))]+"\n");
						worker[ss]["tire"]-=1+random(3);
					};
					worker[ss]["tire"]+=random(2);
					worker[ss]["eff"]-=random(2);
					if( worker[ss]["eff"]<0  ) worker[ss]["eff"]=0;
					if( worker[ss]["eff"]>10 ) worker[ss]["eff"]=10;
					if( worker[ss]["tire"]>10) worker[ss]["tire"]=10;
					if( worker[ss]["tire"]<0 ) worker[ss]["tire"]=0;
					if( worker[ss]["job"]=="砍树" )done+=worker[ss]["str"];
					if( worker[ss]["job"]=="整地" )done+=worker[ss]["exp"];
					if( worker[ss]["job"]=="灌溉" )done+=worker[ss]["int"];
					done+=2*worker[ss]["eff"];
					done-=worker[ss]["tire"];
				}
				who->set_job("landlord","worker",worker);
				who->set_job("landlord","done",who->query_job("landlord","done")+done);
			}
			if( sizeof(worker)!=3 )
				tell_user(ww, "土地开发官员告诉你：赶紧分配农夫们去工作啊。\n");
			else if( job["quest"]&&job["quest"]!=""&&stringp(job["quest"]) )
				tell_user(ww, "土地开发官员告诉你：大伙儿要的"+who->query_job("landlord", "memo")+"呢，赶紧送来。\n");
			else if( !random(8) ){
				objs = keys(OBJ_D->get_obj());
                		objs = filter_array(objs, (: OBJ_D->get_obj($1, "level")==1&&OBJ_D->get_obj($1, "type")!="horse" :));
                		obj  = objs[random(sizeof(objs))];
				who->set_job("landlord","quest", obj);
				who->set_job("landlord","memo", OBJ_D->get_obj(obj,"name"));
				tell_user(ww,"土地开发官员告诉你：大伙儿精神都不太好，除非你能给大家些"+who->query_job("landlord", "memo")+"。\n");
			}
		} else {
			map_delete(leader, ww);
			who->finish_job("landlord");
			who->set_job("landlord", "worker", ([]));
			tell_user(ww, "你的开发新田的任务完成了。\n");
			tell_user(ww, "本次工作公完成了"+chinese_number(who->query_job("landlord","done"))+"的工作量。\n");
			do_award(who, job["done"]+job["succ"]*200);
			if( job["done"] == 0 )
				tell_user(ww, "但没有任何实质性的进展。\n");
			else if( job["succ"] == 0 ){
				tell_user(ww, "但只有一点点的进展。\n");
				CHAR_D->set_char(ww, "loyalty",CHAR_D->get_char(ww, "loyalty")+1);
				tell_user(ww, "你的忠诚度提高了。\n");
				CHAR_D->set_char(ww, "localcontribution",CHAR_D->get_char(ww, "localcontribution")+10);
				tell_user(ww, "你的地区贡献度提高了。\n");
			} else {
				tell_user(ww, "而且取得了相当大的进展。\n");
                                CHAR_D->set_char(ww, "loyalty",CHAR_D->get_char(ww, "loyalty")+2);
                                tell_user(ww, "你的忠诚度提高了。\n");
                                CHAR_D->set_char(ww, "localcontribution",CHAR_D->get_char(ww, "localcontribution")+20);
                                tell_user(ww, "你的地区贡献度提高了。\n");
			}
		}

	}

	return;
}
void do_work(object who)
{
	int hp;
	mapping job;
	string *msg;

	msg = ({"$N躺在树下睡着了。\n",
                "$N一本正经的砍着树。\n",
                "$N拼了命似的砍树，大树唰唰的倒在地上。\n",
                "$N倒在地睡着了。\n",
                "$N努力的整地，流了一身的汗。\n",
                "$N不紧不慢的灌溉着。\n",
                "$N一本正经的灌溉着。\n", });

	if( who->query_link() ){
		job = who->query_job("land_dp", "");
		hp  = who->query_cur_hp();
		if( hp < 20 ){
			write("你已经太劳累了。\n");
			return;
		}
		who->set_cur_hp(hp-10);
		if( !job || !mapp(job) || !sizeof(job) || job["beg_time"]<= 0 || member_array(who, keys(player))){
			this_object()->targetted_action("$N向$T致谢。\n", who);
			return;
		}
		who->set_job("land_dp", "done", who->query_job("land_dp", "done")+30+random(30));
	};

	who->simple_action(msg[random(sizeof(msg))]);
	who->start_busy(2, "你正忙着劳动呢。");

	return;
}
mixed indirect_give_obj_to_liv(object ob, object liv)
{
	string name, oid;
	object who;
	mapping job;

	oid = ob->query_id()[0];
	job = this_body()->query_job("landlord", "");

	this_object()->responda("nod");
	this_object()->responda("thank");

	if( !job||!mapp(job)||!sizeof(job)||job["beg_time"] <= 0 ){
		this_object()->targetted_action("$N对$T道：无论如何，谢谢$R。\n", this_body());
	} else {
		this_object()->targetted_action("$N对$T赞道：$R，干得好。\n", this_body());
		this_body()->set_job("landlord", "succ", liv->query_job("landlord","succ")+1);
		this_body()->set_job("landlord", "memo",  "");
		this_body()->set_job("landlord", "quest", "");
	}
	if( sizeof(player)&&mapp(player) )name = keys(player)[random(sizeof(player))];
	if( !name||!who=CHAR_D->find_char(name)||!objectp(who)||!who->query_link() ){
		destruct(ob);
		return this_object()->short()+"深深的叹了口气，我就自己收下了。\n";
	};
	ob->move(who);
	return this_object()->short()+"把"+ob->query_id()[1]+"交给"+who->query_id()[1]+"\n";
}
void do_award(object who, int many)
{
}
