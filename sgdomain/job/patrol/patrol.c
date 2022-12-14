// the job of patrol
// by fire on March 1999
#define PATROLTIME 600 // ten minute
#define MAXTASKS 10 // no more than 10 tasks
#define JOBID "patrol"
mapping patrols=([]);
void job_judge();

int check_finish_task(string p_id);
mixed new_task(string p_id);
void finish_task(string p_id);
void remind_task(string p_id);
void find_thief(string p_id);

void create()
{
	string *mlist;
	mlist=CHAR_D->check_char("type",TYPE_PLAYER);
	mlist=filter_array(mlist,(: CHAR_D->get_char($1,"patrol")!=0 :));
	if(sizeof(mlist))
		foreach(string p in mlist)
	{
		patrols[p]=CHAR_D->get_char(p,"patrol");
	}
	job_judge();
}
mixed job(string m_id,string officer_id)
{
   string m_area=CHAR_D->get_char(officer_id,"area");

	mixed tmp=([]);
   object o=find_body(m_id);

   if(!objectp(o)) return 0;

	tmp["beg_time"]=time();
	tmp["area"]=m_area;
	tmp["tasks"]=0;
	patrols[m_id]=tmp;
	CHAR_D->set_char(m_id,"patrol",tmp);

   o->add_job("patrol");
   o->set_job("patrol","status","begin");
   o->set_job("patrol","score",0);

   o->set_job("patrol","area",m_area);
   o->set_job("patrol","memo","巡逻"+AREA_D->get_area(m_area,"name"));
   
   return "$N对$T道：那就麻烦$R去本地区巡逻一下。\n"+
	   "\n有困难就用 help patrol。\n";
}
mixed stat_me()
{
	return patrols;
}
void job_judge()
{
	string *ids;
	object o;
	mixed p_task;
	int p_time=time();
	remove_call_out("job_judge");
	call_out("job_judge",5);
	if(!sizeof(patrols))
		return;
	ids=keys(patrols);
	foreach(string p_id in ids)
	{
		o=find_body(p_id);
		if(((p_time-patrols[p_id]["beg_time"])>PATROLTIME)||
			(patrols[p_id]["tasks"]>MAXTASKS))
		{
			map_delete(patrols,p_id);
			CHAR_D->set_char(p_id,JOBID,0);
			if(objectp(o))
			{
				o->set_job(JOBID,"status","done");
				tell_user(p_id,
				  "%^H_GREEN%^任务完成，快去太守处领赏吧。\n%^RESET%^");
			}
			continue;
		}
		if((!patrols[p_id]["curtask"]))
		{
			if(random(2)==0)
			{
				p_task=new_task(p_id);
				patrols[p_id]["curtask"]=p_task;
				remind_task(p_id);
			}
			continue;
		}
		patrols[p_id]["curtask"]["time"]++;

		if(check_finish_task(p_id)==1){
			finish_task(p_id);
			continue;
		}
		if((patrols[p_id]["curtask"]["time"]%4)==0)
		{
			remind_task(p_id);
			continue;
		}
	}
}

mixed new_task(string p_id)
{
	string p_area=patrols[p_id]["area"];
	string p_path, *mlist;
	string p_roomname,p_room,p_myroomname;
	object me,env;
	mixed ret=([]);

	//printf("p_area = %s\n",p_area);
	me=find_body(p_id);
	if(!objectp(me)) return 0;
	env=environment(me);
	if(!objectp(env)) return 0;
	p_myroomname=env->short();

	p_path=AREA_D->get_area(p_area,"path");
	mlist=AREA(p_area)->get_room("list");
	/*printf("mlist =\n");	//debug start
	foreach(string temp in mlist)
	{
		printf("%s ",temp);
	}
	printf("\n");			//debug end*/
	p_room=mlist[random(sizeof(mlist))];
	env=load_object(p_path+p_room);
	p_roomname=env->short();
	while(p_myroomname==p_roomname)
	{
		p_room=mlist[random(sizeof(mlist))];
		env=load_object(p_path+p_room);
		p_roomname=env->short();
	}
	ret["time"]=0;	
    switch(random(10))
	{
	default: // this is the simplest job
		ret["task"]="goto";
		ret["room_name"]=p_roomname;
		me->set_job(JOBID,"memo","到"+p_roomname);
		break;
	}
	return ret;
}

void find_thief(string p_id)
{
	string p_area=patrols[p_id]["area"],n_id,p_room;
	object me,env,o_thief;
	mixed ret=([]);

	me=find_body(p_id);
	if(!objectp(me)) return 0;
	env=me->query_room();
	if(!objectp(env)) return 0;

	ret["time"]=0;	
	ret["task"]="thief";
	ret["get_thief"]=0;

	me->set_job(JOBID,"memo","抓小偷");
	me->set_job(JOBID,"get_thief",0);


	patrols[p_id]["curtask"]=ret;

	n_id=p_area+" thief";
    CHAR_D->add_char(n_id);

    CHAR_D->set_char(n_id,"my_master",p_id);
    CHAR_D->set_char(n_id,"name","小偷");
    CHAR_D->set_char(n_id,"is_tmp",1);
    CHAR_D->set_char(n_id,"is_thief",1);
    CHAR_D->set_char(n_id,"body","thief");
	p_room=file_name(env);
	CHAR_D->put_char(n_id,p_room);
	o_thief=CHAR_D->find_char(n_id);
	o_thief->set_leader(p_id);
	me->targetted_action(
		"$N一抬头，发现一个$T正偷偷摸摸地溜过来，大喊一声：站住。\n",o_thief);
	tell_user(p_id,"抓住小偷，用：cmd catch thief\n");
	return ;

}
int check_finish_task(string p_id)
{
	string p_myroomname;
	object me,env;

	me=find_body(p_id);
	if(!objectp(me)) return 0;
	env=environment(me);
	if(!objectp(env)) return 0;
	p_myroomname=env->short();

    switch(patrols[p_id]["curtask"]["task"])
	{
	case "goto":
		if(patrols[p_id]["curtask"]["room_name"]==p_myroomname)
			return 1;
		break;
	case "thief":
		if(me->query_job("patrol","get_thief"))
			return 1;
		break;
	}
	return 0;
}

void finish_task(string p_id)
{
	object me;
	object o;
	int score;
	me=find_body(p_id);
	if(!objectp(me)){
		patrols[p_id]["curtask"]=0;
		return;
	}
	patrols[p_id]["tasks"]++;
	switch(patrols[p_id]["curtask"]["task"])
	{
	case "goto":
		switch(random(10))
		{
		case 0:
			me->simple_action("$N在"+patrols[p_id]["curtask"]["room_name"]+
				"转了一转，突然发现墙角有什么东西在闪光。\n"+
                                  "拣起一细看，原来是一些银子。\n");
			me->responda("jump");
			me->simple_action("$N喜道：发财啦，赶忙把银子塞入口袋。\n");
	        o=new(M_SILVER);
			o->set_m_num(random(50)+1);
			o->move(me);
			break;
		case 1: // find thief
			find_thief(p_id);
			return;
		default:
			me->simple_action("$N在"+patrols[p_id]["curtask"]["room_name"]+
				"转了一转，发现一切正常。\n"+
				"$N满意地点了点头。\n");
			tell_user(p_id,"你的工作成绩提高了。\n");
			score=me->query_job(JOBID,"score");
			me->set_job(JOBID,"score",score+1); 
			break;
		}
		break;

	case "thief":
		if(me->query_job("patrol","get_thief")==1)
		{
			me->simple_action("$N抓住了小偷，$N的成绩提高许多。\n");
			AREA_D->set_area(patrols[p_id]["area"],"safe",
				AREA_D->get_area(patrols[p_id]["area"],"safe")+1);
	       CHANNEL_D->deliver_tell("rumor","system",
                sprintf("%s抓住小偷，当地百姓纷纷称赞。",CHAR_D->get_char(p_id,"name")));	
			score=me->query_job(JOBID,"score");
			me->set_job(JOBID,"score",score+5);
			break;
		}
		else
		{
			me->simple_action("$N左看右看，没了小偷的踪影。\n");
			me->simple_action("$N没有抓住小偷，$N的成绩下降了。\n");
			score=me->query_job(JOBID,"score");
			me->set_job(JOBID,"score",score+5);
			break;
		}
	}
	patrols[p_id]["curtask"]=0;
	return;
}
void remind_task(string p_id)
{
	object me,o,env;
	string n_id;
	me=find_body(p_id);
	if(!objectp(me)){
		patrols[p_id]["curtask"]=0;
		return;
	}
	switch(patrols[p_id]["curtask"]["task"])
	{
	case "goto":
			me->simple_action("$N左右看看，突然觉得有必要到"
				+patrols[p_id]["curtask"]["room_name"]+
				"转转。\n");
			break;
	case "thief":
			n_id=patrols[p_id]["area"]+" thief";
			o=CHAR_D->find_char(n_id);
			if(objectp(o))
			{
				env=environment(o);
				if(objectp(env))
				{
					me->simple_action("$N一算，小偷估计在"+
						env->short()+"，快去抓吧。\n");
					break;
				}
			}
			me->simple_action("$N急得团团转，不知小偷跑哪去了。\n");
			me->set_job(JOBID,"get_thief",-1);
			break;
	default:
			break;
	}
	return;
}
