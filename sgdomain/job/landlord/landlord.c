// Created by flee@sgz on 03201999
#include <mudlib.h>

#define JOB_MENU  __DIR__"job_menu.c"
#define WORKER    __DIR__"workers.c"

inherit LIVING;
inherit M_CHAR;

string owner;
object officer, new_worker, *workers;

void answer_job();
void finsih_job();
void award(object ob);
void do_work(object ob);
int job(string who, string ob)
{
	object obj;
	obj = find_body( who );
	obj->add_job("landlord");
	obj->set_job("landlord", "status", "start");
	return 1;
}
void setup()
{
	set_name("officer", "���ؿ�����Ա");
	add_id("land officer");
	set_in_room_desc("һλ��ɷ�������ؿ�����Ա(officer)");
	set_long("һλ��ɷ���Ĺ�Ա(officer)");
	set_gender(1);
	add_question("order", "order");
	add_question("job", "job");
	add_ask_str("order", "$N��$T��ģ������˵�����ټ���������Ҫ����������\n");
	add_ask_str("job", "$N��$T�ʵ���������ʲô������\n");
}
mixed special_answer(object ob, string str)
{
	object worker1, worker2, worker3, menu;

	if( !str || !stringp(str) )return ::special_answer(ob, str);
	if( str == "job" ) {
		answer_job();
		return;
	};
	if( str != "order" )return ::special_answer(ob, str);
	if( !ob->query_job("landlord", "") ){
		this_object()->targetted_action("$NƲ��$Tһ�ۣ���˭�������ģ�\n", ob);
		return 1;
	};
	if( ob->query_job("landlord", "status") == "over" ){
		this_object()->targetted_action("$N��$TЦ������λ$R���Ĺ����Ѿ�����ˡ�\n", ob);
		return 1;
	};	
	if( !owner || owner == "" || this_body()->query_id()[0] == owner ){
		this_object()->targetted_action("$N�����Ķ�$T˵��$R������ɡ�\n", ob);
		if( !ob->query_job("landlord", "start") ){

			owner = this_body()->query_id()[0];
			call_out("finish_job", 300+random(300));
			ob->set_job("landlord", "start", 1);

			worker1 = new( WORKER );
			worker2 = new( WORKER );
			worker3 = new( WORKER );
			worker1->move(environment(this_object()));
			worker2->move(environment(this_object()));
			worker3->move(environment(this_object()));
			worker1->simple_action("$N����ææ�Ĵ�������˹�����\n");
			worker2->simple_action("$N����ææ�Ĵ�������˹�����\n");
			worker3->simple_action("$N����ææ�Ĵ�������˹�����\n");

			workers = ({ });
			workers = workers + ({worker1, worker2, worker3,});
		};
		menu = new( JOB_MENU );
		menu->set_workers( workers );
		menu->start_menu();
	} else {
		this_object()->simply_action("$N���ֵ���"+CHAR_D->get_char(owner, "name")+"��æ���ء�\n");
	};
	return 1;
}
void answer_job()
{
	object player;

	mapping att = (["str":random(5)+5, "int":random(5)+5, "exp":random(5)+5,
                "eff":random(5)+5, "wrk":0, "job":"��æ" ]);
	player = this_body();
	new_worker = player;

	if ( !owner || owner == ""){
		this_object()->simple_action("$Nҡ��ҡͷ��������û��ʲô�����ɡ�\n");
		return;
	};
	this_object()->simple_action("$N��ͷ������ɰɣ����������ء�\n");
	if( member_array(player, workers) == -1 ){ 
		workers = workers + ({ new_worker });
		new_worker->resign_job("land_dp");
		new_worker->add_job("land_dp");
		new_worker->set_job("land_dp", "att", att);
	};
	return;
}
void finish_job()
{
	int i, total;
	string area;
	object ob;

	for( i = 0; i < sizeof(workers); i++ ){
		ob = workers[i];
		if( ob && ob->query_link() ){
			total = total + ob->query_job("land_dp", "att")["wrk"];
			ob->finish_job("land_dp");
			ROBOT->robot_test(ob, (: award :) );
		} else {
			total = total + ob->query("wrk");
			ob->simple_action("$N����һ���������ڸ����ˡ�\n");
			destruct( ob );
		};
	};	

	officer = find_body(owner);
	if( officer ){
		tell(officer, this_object()->short()+"����������ˣ�����̫�ػ㱨�ɡ�\n");
		officer->set_job("landlord", "reward", total);
		officer->set_job("landlord", "start", 0);
		officer->set_job("landlord", "status", "done");
	};

	area = CHAR_D->get_char("owner", "area");
	AREA_D->set_area(area, "food", AREA_D->get_area(area, "food")+total);
	AREA_D->set_area(area, "gold", AREA_D->get_area(area, "food")+to_int(total/100) );
			
	workers = ({ });
	owner = "";
	return;
}	
void award(object ob)
{
	object money;
	
	if( ob->query_robot() ){
		this_object()->simple_action("$N΢΢һЦ��ԭ����ˣ��ðɡ�\n");
		this_object()->targetted_action("$N��$Tһ�Ű�ԲֽǮ��\n", ob);
        	ob->simple_action("$N���˵�ֱ�֣�������Ǯ�ˣ�\n");
        	money=new(PMONEY+"fmoney");
        	money->move(ob);
	} else {
		CHAR_D->set_char(ob->query_id()[0],"reputation",
        		CHAR_D->get_char(ob->query_id()[0], "reputation")+5);
		this_object()->simple_action("$N������������\n");
		this_object()->targetted_action("$N��$T�������ӡ�\n", ob);
		money = new(M_SILVER);
		money->set_m_num(10+random(10));
		money->move( ob );
	}
	return;
}
void do_work(object ob)
{
	int hp;
	mapping att;
	string *msg = ({"$N��������˯���ˡ�\n",
			"$Nһ�������Ŀ�������\n",
			"$Nƴ�����ƵĿ����������৵ĵ��ڵ��ϡ�\n",
			"$N���ڵ�˯���ˡ�\n",
			"$NŬ�������أ�����һ��ĺ���\n",
			"$N���������Ĺ���š�\n",
			"$Nһ�������Ĺ���š�\n", });

	if( !sizeof(workers) || member_array(ob, workers) == -1){
		this_object()->simple_action("$N����Ҫ�����������롣\n");
		return;
	};
	hp = ob->query_cur_hp();
	att = ob->query_job("land_dp", "att");
	if( hp < 50 ){
		printf("���Ѿ�̫���ˣ���������Ϣһ���ٸɰɡ�\n");
                return;
        } else ob->set_cur_hp( hp -40+random(10) );
	ob->simple_action( msg[random(sizeof(msg))] );
	att["wrk"] = att["wrk"] + (att["int"]+att["str"]+att["exp"]+att["eff"])/4;
	ob->set_job("land_dp", att);
	
	return;
}
