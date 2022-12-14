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
	set_name("officer", "土地开发官员");
	add_id("land officer");
	set_in_room_desc("一位神采飞扬的土地开发官员(officer)");
	set_long("一位神采飞扬的官员(officer)");
	set_gender(1);
	add_question("order", "order");
	add_question("job", "job");
	add_ask_str("order", "$N对$T大模大样的说：快召集人来，我要下命令啦。\n");
	add_ask_str("job", "$N向$T问道：现在有什么工作？\n");
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
		this_object()->targetted_action("$N撇了$T一眼，是谁派你来的？\n", ob);
		return 1;
	};
	if( ob->query_job("landlord", "status") == "over" ){
		this_object()->targetted_action("$N向$T笑到：这位$R您的工作已经完成了。\n", ob);
		return 1;
	};	
	if( !owner || owner == "" || this_body()->query_id()[0] == owner ){
		this_object()->targetted_action("$N恭敬的对$T说：$R请下令吧。\n", ob);
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
			worker1->simple_action("$N急急忙忙的从外面赶了过来。\n");
			worker2->simple_action("$N急急忙忙的从外面赶了过来。\n");
			worker3->simple_action("$N急急忙忙的从外面赶了过来。\n");

			workers = ({ });
			workers = workers + ({worker1, worker2, worker3,});
		};
		menu = new( JOB_MENU );
		menu->set_workers( workers );
		menu->start_menu();
	} else {
		this_object()->simply_action("$N摆手道："+CHAR_D->get_char(owner, "name")+"正忙着呢。\n");
	};
	return 1;
}
void answer_job()
{
	object player;

	mapping att = (["str":random(5)+5, "int":random(5)+5, "exp":random(5)+5,
                "eff":random(5)+5, "wrk":0, "job":"帮忙" ]);
	player = this_body();
	new_worker = player;

	if ( !owner || owner == ""){
		this_object()->simple_action("$N摇了摇头道：现在没有什么工作干。\n");
		return;
	};
	this_object()->simple_action("$N点头道：快干吧，正等着你呢。\n");
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
			ob->simple_action("$N申了一下腰：终于干完了。\n");
			destruct( ob );
		};
	};	

	officer = find_body(owner);
	if( officer ){
		tell(officer, this_object()->short()+"：工作完成了，请向太守汇报吧。\n");
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
		this_object()->simple_action("$N微微一笑：原来如此，好吧。\n");
		this_object()->targetted_action("$N给$T一张百圆纸钱。\n", ob);
        	ob->simple_action("$N高兴地直乐：终于有钱了！\n");
        	money=new(PMONEY+"fmoney");
        	money->move(ob);
	} else {
		CHAR_D->set_char(ob->query_id()[0],"reputation",
        		CHAR_D->get_char(ob->query_id()[0], "reputation")+5);
		this_object()->simple_action("$N道：不错，不错。\n");
		this_object()->targetted_action("$N给$T几两银子。\n", ob);
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
	string *msg = ({"$N躺在树下睡着了。\n",
			"$N一本正经的砍着树。\n",
			"$N拼了命似的砍树，大树唰唰的倒在地上。\n",
			"$N倒在地睡着了。\n",
			"$N努力的整地，流了一身的汗。\n",
			"$N不紧不慢的灌溉着。\n",
			"$N一本正经的灌溉着。\n", });

	if( !sizeof(workers) || member_array(ob, workers) == -1){
		this_object()->simple_action("$N道：要工作，先申请。\n");
		return;
	};
	hp = ob->query_cur_hp();
	att = ob->query_job("land_dp", "att");
	if( hp < 50 ){
		printf("你已经太累了，还是先休息一下再干吧。\n");
                return;
        } else ob->set_cur_hp( hp -40+random(10) );
	ob->simple_action( msg[random(sizeof(msg))] );
	att["wrk"] = att["wrk"] + (att["int"]+att["str"]+att["exp"]+att["eff"])/4;
	ob->set_job("land_dp", att);
	
	return;
}
