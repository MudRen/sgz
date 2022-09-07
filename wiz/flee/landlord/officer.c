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
        set_name("officer", "���ؿ�����Ա");
        add_id("land officer");
        set_in_room_desc("һλ��ɷ�������ؿ�����Ա(officer)");
        set_long("һλ��ɷ���Ĺ�Ա(officer)");
        set_gender(1);
        add_question("order", "order");
        add_question("job", "job");
        add_ask_str("order","$N��$T��ģ������˵�����ټ���������Ҫ����������\n");
        add_ask_str("job", "$N��$T�ʵ���������ʲô������\n");
	
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
		this_object()->targetted_action("$N��$T̾����û�й�Աָ������û��������\n",this_body());
	else if( member_array(name, keys(player) )!=-1 || job["beg_time"]>0 )
		this_object()->targetted_action("$N�����Ķ�$T˵��Ҫ�ɾ͸ɣ�����ô��ϻ���\n", this_body());
	else if( CHAR_D->get_char(name, "nation") )
		this_object()->targetted_action("$N��$Tҡͷ����������������ȹ�����\n",this_body());
	else {
		player[name] = (["time":time(), ]);
		this_object()->targetted_action("$N��ͷ�����ðɣ���ʼ�����ɡ�\n", this_body());
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
		this_object()->targetted_action("$N��$T���һ�������ң�һ����ȥ��\n",this_body());
	else if ( job["beg_time"] <= 0 )
		this_object()->targetted_action("$N��$T�Ի��˵�����ˣ����������Ѿ�����ˡ�\n", this_body());
	else if ( sizeof(job["lasttimes"]) > 5 )
		this_object()->targetted_action("$N��$T������˵�����ˣ��������Ѿ�̫�����ˡ�\n", this_body());
	else {
		if( !mapp(leader) || member_array(name, keys(leader)) == -1 ){
			leader[name] = (["time":time(),]);
			this_body()->set_job("landlord", "worker", ([]));
			this_body()->set_job("landlord", "quest", "");
			this_body()->set_job("landlord", "succ", 0);
			this_body()->set_job("landlord", "done", 0);
		}
		this_object()->targetted_action("$N��$T������˵�����ˣ������\n", this_body());
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

	string *good_news = ({"�ڷ��Ͷ����ܵ��˴�ҵ�һ�����",
			"һ��ͷ���£��ۣ�������һ�󶧽��ӡ�", 
			"��������ˮ���־���ٱ��ĸ���������",
			"����С�������ֵ��Ͷ��š�", });
	string *bad_news = ({"һ��С�ı���ҧ��һ�ڡ�",
			"һ��ͷ�����Լ����ϡ�",
 			"͵͵�������ˣ���������˯�����",
			"�����ˣ�һ������ũ�������ȭ��"});

call_out("do_consider", 60);

	if( sizeof(player) ){
		workers = keys(player);
		foreach(ww in workers){
			who = CHAR_D->find_char(ww);
			if( !who->query_link() )continue;
			job = who->query_job("land_dp", "");
			if( job["beg_time"] <= 0 ) who->set_job("land_dp", "time", time());
			if( job["beg_time"] + 600 < time() ){
				tell_user(ww, "��İ�æ�����������������ˡ�\n");
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
					if( worker[ss]["job"]=="����" )done+=worker[ss]["str"];
					if( worker[ss]["job"]=="����" )done+=worker[ss]["exp"];
					if( worker[ss]["job"]=="���" )done+=worker[ss]["int"];
					done+=2*worker[ss]["eff"];
					done-=worker[ss]["tire"];
				}
				who->set_job("landlord","worker",worker);
				who->set_job("landlord","done",who->query_job("landlord","done")+done);
			}
			if( sizeof(worker)!=3 )
				tell_user(ww, "���ؿ�����Ա�����㣺�Ͻ�����ũ����ȥ��������\n");
			else if( job["quest"]&&job["quest"]!=""&&stringp(job["quest"]) )
				tell_user(ww, "���ؿ�����Ա�����㣺����Ҫ��"+who->query_job("landlord", "memo")+"�أ��Ͻ�������\n");
			else if( !random(8) ){
				objs = keys(OBJ_D->get_obj());
                		objs = filter_array(objs, (: OBJ_D->get_obj($1, "level")==1&&OBJ_D->get_obj($1, "type")!="horse" :));
                		obj  = objs[random(sizeof(objs))];
				who->set_job("landlord","quest", obj);
				who->set_job("landlord","memo", OBJ_D->get_obj(obj,"name"));
				tell_user(ww,"���ؿ�����Ա�����㣺�������񶼲�̫�ã��������ܸ����Щ"+who->query_job("landlord", "memo")+"��\n");
			}
		} else {
			map_delete(leader, ww);
			who->finish_job("landlord");
			who->set_job("landlord", "worker", ([]));
			tell_user(ww, "��Ŀ����������������ˡ�\n");
			tell_user(ww, "���ι����������"+chinese_number(who->query_job("landlord","done"))+"�Ĺ�������\n");
			do_award(who, job["done"]+job["succ"]*200);
			if( job["done"] == 0 )
				tell_user(ww, "��û���κ�ʵ���ԵĽ�չ��\n");
			else if( job["succ"] == 0 ){
				tell_user(ww, "��ֻ��һ���Ľ�չ��\n");
				CHAR_D->set_char(ww, "loyalty",CHAR_D->get_char(ww, "loyalty")+1);
				tell_user(ww, "����ҳ϶�����ˡ�\n");
				CHAR_D->set_char(ww, "localcontribution",CHAR_D->get_char(ww, "localcontribution")+10);
				tell_user(ww, "��ĵ������׶�����ˡ�\n");
			} else {
				tell_user(ww, "����ȡ�����൱��Ľ�չ��\n");
                                CHAR_D->set_char(ww, "loyalty",CHAR_D->get_char(ww, "loyalty")+2);
                                tell_user(ww, "����ҳ϶�����ˡ�\n");
                                CHAR_D->set_char(ww, "localcontribution",CHAR_D->get_char(ww, "localcontribution")+20);
                                tell_user(ww, "��ĵ������׶�����ˡ�\n");
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

	msg = ({"$N��������˯���ˡ�\n",
                "$Nһ�������Ŀ�������\n",
                "$Nƴ�����ƵĿ����������৵ĵ��ڵ��ϡ�\n",
                "$N���ڵ�˯���ˡ�\n",
                "$NŬ�������أ�����һ��ĺ���\n",
                "$N���������Ĺ���š�\n",
                "$Nһ�������Ĺ���š�\n", });

	if( who->query_link() ){
		job = who->query_job("land_dp", "");
		hp  = who->query_cur_hp();
		if( hp < 20 ){
			write("���Ѿ�̫�����ˡ�\n");
			return;
		}
		who->set_cur_hp(hp-10);
		if( !job || !mapp(job) || !sizeof(job) || job["beg_time"]<= 0 || member_array(who, keys(player))){
			this_object()->targetted_action("$N��$T��л��\n", who);
			return;
		}
		who->set_job("land_dp", "done", who->query_job("land_dp", "done")+30+random(30));
	};

	who->simple_action(msg[random(sizeof(msg))]);
	who->start_busy(2, "����æ���Ͷ��ء�");

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
		this_object()->targetted_action("$N��$T����������Σ�лл$R��\n", this_body());
	} else {
		this_object()->targetted_action("$N��$T�޵���$R���ɵúá�\n", this_body());
		this_body()->set_job("landlord", "succ", liv->query_job("landlord","succ")+1);
		this_body()->set_job("landlord", "memo",  "");
		this_body()->set_job("landlord", "quest", "");
	}
	if( sizeof(player)&&mapp(player) )name = keys(player)[random(sizeof(player))];
	if( !name||!who=CHAR_D->find_char(name)||!objectp(who)||!who->query_link() ){
		destruct(ob);
		return this_object()->short()+"�����̾�˿������Ҿ��Լ������ˡ�\n";
	};
	ob->move(who);
	return this_object()->short()+"��"+ob->query_id()[1]+"����"+who->query_id()[1]+"\n";
}
void do_award(object who, int many)
{
}
