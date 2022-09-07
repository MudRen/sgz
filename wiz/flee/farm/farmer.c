#include <mudlib.h>
#define JOB_MENU __DIR__"jobmenu.c"

inherit LIVING;
inherit M_CHAR;

private string *leader;

int check_order(object ob);
void do_finish_job(object ob);
void do_consider();
string get_quest(string job);
void do_reward(object who);

void setup()
{
	object cloth;

        cloth = new("/sgdomain/obj/cloth/torso/buyi.c");
        cloth->move(this_object());
        cloth->do_wear();

        set_name("farmer", "ũ��");
        set_gender(1);
	set_age(20+random(40));
	set_proper_name("һλ�����͸��ŵ�ũ��(farmer)");
        set_in_room_desc("һλ�����͸��ŵ�ũ��(farmer)");
	
	add_question("order", "order");
        add_ask_str("order", "$N��$T���е�ѯ�ʵ�������ׯ�ڵĳ�����ΰ���\n");

call_out("do_consider", 60);
}
mixed special_answer(object ob, string str)
{
	if( str == "order" ) return check_order(ob);
	else return ::special_answer(ob, str);
}
int check_order(object ob)
{
	string name;
	mapping job;

	job = ob->query_job("do_farm", "");
	name = ob->query_id()[0];
	if( !job||!mapp(job)||job["beg_time"]<=0 )
		this_object()->targetted_action("$N��$T��ͷЦ�����и����и���һ�ж��ã�\n", ob);
	else if( job["beg_time"]+3600<time() ){
		this_object()->responda("sigh");
		this_object()->targetted_action("$N��$T���ĵ�˵��$R���ڲ鿴�������������գ�\n", ob);
		ob->finish_job("do_farm");
		ob->set_job("do_farm","succ",0);
		ob->set_job("do_farm","time",0);
	        ob->set_job("do_farm", "job",  0);
		ob->set_job("do_farm", "fail", 0);
	} else {
		if( !leader||!arrayp(leader) )leader = ({ });
		if( member_array(name,leader)==-1 ){
			leader-=({name});
			leader+=({name});
		}
		this_object()->targetted_action("$N��$T������˵��$R����ָʾ��\n", ob);
		new(JOB_MENU)->start_menu();
	}
	return 1;
}
void do_consider()
{
	object ob;
	mapping job;

call_out("do_consider", 60);
	if( !arrayp(leader)||!sizeof(leader) )return;
	foreach(string nn in leader){
		ob = CHAR_D->find_char(nn);
		if( !ob->query_link() ){
			leader-=({nn});
			continue;
 		};
		job= ob->query_job("do_farm", "");
		if( job["time"]>24 ){
			leader-=({nn});
			do_finish_job( ob );
			continue;
		};
		if( (!job["job"]||job["job"]=="")&&random(3)==1 ){
			job["job"] = get_quest("");
			ob->set_job("do_farm","job_d",2+random(3));
		};
		if( job["job"]&&stringp(job["job"])&&job["job"]!="" ){
			tell_user(nn, get_quest(job["job"]) );
			ob->set_job("do_farm", "fail", job["fail"]+1);
		}
		ob->set_job("do_farm", "time", job["time"]+1);
		ob->set_job("do_farm", "job",  job["job"]);
	}
}
string get_quest(string msg)
{
	string *jobs = ({ "bugs", "fire", "water", "rats" });

	if( !msg||msg==""||!stringp(msg) )  return jobs[random(sizeof(jobs))];
        if( member_array(msg, jobs) == -1 ) return "No such type\n";
        switch( msg ){
                case "fire" : return "ͻ������ׯ�ڵ���ȼ�ա�\n";
                case "water": return "�콵���꣬ׯ�ڱ���ˮ��û��\n";
                case "rats" : return "������ֳ��ׯ��Σ�ڵ�Ϧ��\n";
		case "bugs" : return "�ȳ������Ұ�ķ�������ʳ��ׯ�ڡ�\n";
        }
}
void do_finish_job(object ob)
{
        tell_user(ob->query_id()[0], "\n�����ֲׯ�ڵĹ�������ˡ�\n");
        ob->finish_job("do_farm");
        ob->set_job("do_farm", "job",  0);
        ob->set_job("do_farm", "time", 0);
	do_reward( ob );
}
void do_reward(object ob)
{
	int sk_meili, sk_wuli, succ, fail, tt;
	string id, area;

	succ 	 = ob->query_job("do_farm", "succ");
	fail 	 = ob->query_job("do_farm", "fail");
	id   	 = ob->query_id()[0];
	area 	 = CHAR_D->get_char(id, "area");
	sk_meili = ob->query_sk_level("sk_meili");
	sk_wuli  = ob->query_sk_level("sk_wuli");

	ob->set_job("do_farm", "succ", 0);
	ob->set_job("do_farm", "fail", 0);

	// cost some gold of the city
	tt = 200 + random(200) - (sk_meili+sk_wuli)/2;
	if( AREA_D->get_area(area, "gold")>=tt )
		AREA_D->set_area(area, "gold", AREA_D->get_area(area,"gold")-tt);
	else AREA_D->set_area(area, "gold", 0);

	// add food of the city
	tt = 20*AREA_D->get_area(area, "agriculture"); 	// agriculture level
	tt = tt + 5*AREA_D->get_area(area, "safe");    	// safe level
	tt = tt + 5*(sk_meili+sk_wuli);		      	// player skills
	tt = tt + succ*200 - fail*20;			// player performance
	if( tt<= 0 ) tt = 100 + random(100);

	AREA_D->set_area(area, "food", AREA_D->get_area(area,"food")+tt);
}
