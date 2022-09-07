//basejob_control
#define WORKER "/sgdomain/base/npc/worker/"

private object master,slave,room;
private string p_area,f_id,r_id,p_id;
private string p_roomname,p_workername;
private int score,round; // score is the score you get the round 1 to 10
private int starttime;
private string task;
private object usr;
private int stage;
private object worker1,worker2;
//static private string *tasks=({ "sleep","workhard","nowork","idle",
//							 "fight","nomal","rest","steal"});

static private string *tasks=({ "sleep","workhard","idle","poor"});

object get_master() {
	return SGBASE(p_area,f_id);
}

void destruct_me() {
	if(objectp(master))
	master->finish_job("basejob");
	remove_call_out("check_status");
	if(objectp(worker1))
		worker1->disappear();
	if(objectp(worker2))
		worker2->disappear();

	if(objectp(slave)) slave->set_busy(0);
	if(score>5)
		SGROBOT(master,score*2);
	destruct(this_object());
}
void finish_job() {
	if(score <=5) {
		slave->responda("snicker");
		tell(master,"�ܲ��ң�������ɵ�һ����Ϳ��\n");
	}
	else if(score<10) {
		slave->responda("addoil "+p_id);
		tell(master,"������ɵĲ����ش�������Ϳ��Եý��ˡ�\n");
	}
	else if(score < 15) {
		slave->responda("admire "+p_id);
		tell(master,"������ɵĺü��ˣ��ش�������Ϳ��Եý��ˡ�\n");
	}
	else {
		slave->responda("flatter "+p_id);
		tell(master,"������ɵĲ���˼��غã��ش�������Ϳ��Եý��ˡ�\n");
	}
	destruct_me();
	return;
}
string new_task() {
	return tasks[random(sizeof(tasks))];
}

void add_score(int i) {
	int spr=SGBASE(p_area,f_id)->get_room(r_id,"spr");
	SGBASE(p_area,f_id)->set_spr(r_id,spr+i);
	score+=i;
	round++;
	stage=-1;
	task="";
}
void start_task(string t,string f) {
	worker1=new(WORKER+f);
	worker1->init(master,slave,t);
	worker1->move(room);
	worker1->set_menu(this_object());
	worker1->show_start();

}

void show_task() {
	switch(task) {
	case "sleep":
		start_task(task,"sleeper");
		break;
	case "workhard":
		start_task(task,"hardworker");
		break;
	case "idle":
		start_task(task,"idler");
		break;
	case "poor":
		start_task(task,"poorer");
		break;
	default:
	}
}
void ask_task() {
	if(objectp(worker1))
		worker1->gave_problem();
}
void show_task_noise() {
	if(objectp(worker1))
		worker1->show_noise();
}
void task_check() {
	if(stage<0) {
		stage++; return;
	}
	if(!sizeof(task)) {
		task=new_task();
		stage=0;
	}

	switch(stage) {
	case 0: show_task(); break;
	case 1: ask_task(); break;
	default:
		if(random(3)==0) {
			show_task_noise();
		}
	}
	stage++;
	if(stage>30) {
		if(objectp(worker1))
			worker1->disappear();
		if(objectp(worker2))
			worker2->disappear();

		add_score(0);
	}

}

int check_status() {
	remove_call_out("check_status");
	call_out("check_status",5);

	if(!objectp(master)||!objectp(slave)||!objectp(room)||
		(master->query_room()!=room)||(!objectp(usr))) {
		destruct_me(); return;
	}
	if((round>=10)||(time()-starttime>900)) {
		finish_job();
		return;
	}
	task_check();	
}

void start() {
	slave->targetted_action("$N��$Tһ�������$R����롣\n",master);
	DELAY_D->delay_targetted_action(master,slave,
		"$N��$T�߽���"+p_roomname+"��\n",1);
	call_out("check_status",2);
}
void  init(object m,object s){
	master=m;
	slave=s;
	p_area=s->get_area();
	f_id=s->get_f_id();
	r_id=s->get_r_id();
	p_id=master->query_primary_id();
	usr=find_user(p_id);
	p_roomname=BASE_D->get_base(f_id,"roomname");
	p_workername=BASE_D->get_base(f_id,"workername");
	score=0;
	round=0;
	room=master->query_room();
	starttime=time();
	task="";
	call_out("start",5);
}