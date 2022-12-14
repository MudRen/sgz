// ev_party.c 
// this is used to handle the local meeting
// this in fact is a task
// by group on 25 Nov, 1999
// this is to check if an area can hold a
// party
#include <mudlib.h>
#include <party.h>
#include <ansi.h>
#define MAXNUMBER 8
//inherit __DIR__+"ev_localmeeting/pass";
//inherit __DIR__+"ev_localmeeting/train";
//inherit __DIR__+"ev_localmeeting/suggestion";
//inherit __DIR__+"ev_localmeeting/agree";
//inherit __DIR__+"ev_localmeeting/judge";
//inherit __DIR__+"ev_localmeeting/consider";
//inherit __DIR__+"ev_localmeeting/absent";
string *u_list, s_room;
int gold, food,b_num,size;
void meet_process(string p_id);

int can_party(string a_id)
{
	int* task;
	int p_month,p_day,last;
	array p_date;
	string p_leader;
	string* a_list;
	int i,a_num;
	p_leader=AREA_D->get_area(a_id,"leader");
	task=TASK_D->get_char_task(p_leader);
	if(task[0]!=-1)  // has some task
	{
		if(task[1]==TT_PARTY)
			return PT_ALREADYPARTY;
		else
			return PT_OTHERTASK;
	}
	gold = AREA_D->get_area(a_id,"gold");
	food = AREA_D->get_area(a_id,"food");
	a_list=CHAR_D->check_char_area("nation",
		AREA_D->get_area(a_id,"nation"),a_id);
	
	a_num=0;
	for(i=0;i<sizeof(a_list);++i)
	{
		task=TASK_D->get_char_task(a_list[i]);
		if(task[0]==-1)
			a_num++;
	}
	if (gold < 500 * sizeof(a_list) || food < 1200 * sizeof(a_list))
	return PT_NOMONEY;
	p_date = DAY_D->query_date();
	p_month = p_date[2];
	p_day = p_date[1];
	if (!(p_month==1|| p_month == 7) || !(p_day == 1 || p_day == 2 || p_day == 3)) 
	return PT_TIME;

	if((sizeof(a_list)-a_num)>=PT_MINABSENT)
		return PT_TOOMANYABSENT;
	if(a_num<PT_MINCHAR)
	{
		return PT_NOENOUTHCHAR;
	}
	
	last = AREA_D->get_area(a_id,"last_party_time");
        if( time()<last+40000)
        return PT_TIME;
	return PT_OK;
}
//int can_auto_lmeeting(string a_id)
//{
//	string p_leader;
//	p_leader=AREA_D->get_area(a_id,"leader");
//	if((CHAR_D->get_char(p_leader,"status"))==
//		STATUS_ONLINE)
//		return 0; // a player is the leader can't auto meeting
//	if(can_lmeeting( a_id)==LM_OK)
//		return 1;
//	return 0;
//}
// this is used for the system to hold local meeting
// in a regular schedule 
void party(string a_id)
{
	int t_num;
	mapping m_us;
	string *u_all;
	string p_leader;
	string tmp;
	int *task,i;
	object ob_char;
	CHANNEL_D->deliver_tell("rumor","system",
sprintf("%s??????????????",AREA_D->get_area(a_id,"name")));
	AREA_D->set_area(a_id,"last_party_time",time());
	t_num=TASK_D->add_task(TT_PARTY);
	TASK_D->set_task(t_num,"area",a_id);
	s_room=AREA_D->get_area(a_id,"path")+
		AREA_D->get_area(a_id,"meeting");
	TASK_D->set_task(t_num,"room",s_room);
	u_all=CHAR_D->check_char_area("nation",
		AREA_D->get_area(a_id,"nation"),a_id);

	p_leader=AREA_D->get_area(a_id,"leader");

	if(sizeof(u_all)<=MAXNUMBER){
		u_list=u_all;
	}
	else {
		u_list=filter_array(u_all,(:CHAR_D->get_char($1,"status")==STATUS_ONLINE:));
		u_list-=({p_leader});
		u_list+=({p_leader});
		u_all-=u_list;
		while(sizeof(u_list)<MAXNUMBER){
			tmp=u_all[random(sizeof(u_all))];
			u_list+=({tmp});
			u_all-=({tmp});
		}
	}

	m_us=([]);
	for(i=0;i<sizeof(u_list);++i)
	{
		task=TASK_D->get_char_task(u_list[i]);
		if(task[0]==-1)
		{
       	                m_us[u_list[i]]=LMP_ATTEND;
               	        CHAR_D->set_char(u_list[i],"task",TASK_PARTY);
			if(CHAR_D->get_char(u_list[i],"status")==STATUS_ONLINE) // a player
			{
				if(file_name(environment(CHAR_D->find_char(u_list[i])))!=
					s_room)
				(EV_INFORMSB)->inform_sb(u_list[i], AREA_D->get_area(a_id,"name")+"??????????????$R??????");    
			}
                        else
			{
                        	ob_char=CHAR_D->find_char(u_list[i]);
				if(CHAR_D->get_char(u_list[i],"status")==STATUS_ACTIVE) // active
{
                                        if(CHAR_D->get_char(u_list[i],"room")!=
						s_room)
				{
					(EV_INFORMSB)->inform_sb(u_list[i],
                                                AREA_D->get_area(a_id,"name")+"??????????????$R??????");    
					if(objectp(ob_char))
					{
                                                ob_char->simple_action("$N????????$s????????????????????????????????\n");
                                                ob_char->simple_action("$N????????????????\n");
					}
		                        CHAR_D->put_char(u_list[i],s_room); if(objectp(ob_char))
                                        ob_char->simple_action("$N??????????????????\n");
				}
}
				else
				{
					if(!objectp(ob_char)||
					(file_name(environment(CHAR_D->find_char(u_list[i])))!=
						s_room))
					{
			                        CHAR_D->put_char(u_list[i],s_room);
						ob_char=CHAR_D->find_char(u_list[i]); if(objectp(ob_char))
                                                ob_char->simple_action("$N??????????????????\n");
					}
				}
			}
		}
	}
	AREA_D->set_area(a_id,"status",ST_MEETING);
	ob_char=CHAR_D->find_char(p_leader);
	if(objectp(ob_char))
	ob_char->simple_action("$N????????????????????????????????????\n");
	m_us[p_leader]=LMP_LEADER;
	AREA_D->set_area(a_id,"gold",gold - sizeof(u_list) * 500);
	AREA_D->set_area(a_id,"food",food - sizeof(u_list) * 1200);	
	TASK_D->set_task(t_num,"start_time",time());
	TASK_D->set_task(t_num,"chars",m_us);
	TASK_D->set_task(t_num,"timaim",LML_BEGIN);
	TASK_D->set_task(t_num,"stage",LMS_BEGIN);
}
void auto_local_meeting()
{
}
void meet_announce(int p_id)
{
	string p_area;
	string p_leader;
	object o_char,o_room,o;
	mixed obs;
	int i;
	p_area=TASK_D->get_task(p_id,"area");
	p_leader=AREA_D->get_area(p_area,"leader");
	o_char=CHAR_D->find_char(p_leader);
	if(objectp(o_char))
	{
		o_char->simple_action
                ("$N??????????????????????????????????????$S??????????????????\n");
                o_char->simple_action
                ("$N??????????????????????????????????\n");
	}
	o_room=load_object(s_room);
        if(!objectp(o_room)) return;
        obs=OBJ_D->check_obj("type","food");
        for(i=0;i<3;++i) { // less drink and food
                o=OBJ_D->clone_obj(obs[random(sizeof(obs))]);
                if(!objectp(o)) continue;
                o->move(o_room);
        }
        obs=OBJ_D->check_obj("type","drink");
        for(i=0;i<3;++i) {
                o=OBJ_D->clone_obj(obs[random(sizeof(obs))]);
                if(!objectp(o)) continue;
                o->move(o_room);
	}
	TASK_D->set_task(p_id,"stage",LMS_DISCUSS);
	TASK_D->set_task(p_id,"timaim",LML_PROCESS);
	return;
}
void meet_happens(int p_id)
{
	int h;
	string u_name;
	object o_char;
	size = sizeof(u_list) / 3;
	if(size <1) size =1;
	if(b_num<=size) {
	b_num++;
	u_name = u_list[random(sizeof(u_list))];
	o_char = CHAR_D->find_char(u_name);
	if (CHAR_D->get_char(u_name,"gender")==1)h = 1+random(2);
	else {h = random(2);}
	switch (h) {
	case 0:
	o_char->simple_action(
	"$N??????????????????????$S????????????????????\n");
	TASK_D->set_task(p_id,"stage",LMS_IDLE);
	call_out("party_happen",5,u_name,p_id,h);
	break;
	case 1:
	o_char->simple_action(
        "$N??????????????????????$S????????????????????\n");
	 TASK_D->set_task(p_id,"stage",LMS_IDLE);
        call_out("party_happen",5,u_name,p_id,h);
        break;
	case 2:
	o_char->simple_action(
        "$N??????????????????????$S??????????????????????\n");
	 TASK_D->set_task(p_id,"stage",LMS_IDLE);
        call_out("party_happen",5,u_name,p_id,h);
        break;	
	}
		
}	 
	TASK_D->set_task(p_id,"stage",LMS_PROCESS);
        TASK_D->set_task(p_id,"timaim",LML_BEGIN);
        return;
}

void meet_readytoend(int p_id)
{
	string p_area;
	string p_leader;
	object o_char;
	p_area=TASK_D->get_task(p_id,"area");
	p_leader=AREA_D->get_area(p_area,"leader");
	o_char=CHAR_D->find_char(p_leader);
	if(objectp(o_char))
	{
		o_char->simple_action
                ("$N????????????????????????????????????????????????\n");
		o_char->simple_action
                ("$N??????????????????????????????????????????\n");
	}
	TASK_D->set_task(p_id,"stage",LMS_END);
	TASK_D->set_task(p_id,"timaim",LML_END);
	return;
}
void meet_over(int p_id)
{
	string p_area, p_nation;
	string p_leader;
	object o_char;
	mapping m_us;
	string *p_list;
	int i, loyalty;
	p_area=TASK_D->get_task(p_id,"area");
	p_leader=AREA_D->get_area(p_area,"leader");
	p_nation= AREA_D->get_area(p_area,"nation");
	o_char=CHAR_D->find_char(p_leader);
	if(objectp(o_char))
	{
			o_char->simple_action
					("$N??????????????????????????????????????????????\n");
			
		
	}
	b_num = 0;
	m_us=TASK_D->get_task(p_id,"chars");
	p_list=keys(m_us);
	
	for(i=0;i<sizeof(p_list);++i)
	{	loyalty = CHAR_D->get_char(p_list[i],"lo")[p_nation];
		loyalty =loyalty +random(10)+5;	
		if (loyalty >=100) loyalty = 100;
		CHAR_D->set_char_loyalty(p_list[i],p_nation,loyalty);	
		if((CHAR_D->get_char(p_list[i],"status"))!=STATUS_ONLINE)
		{
			o_char=CHAR_D->find_char(p_list[i]);
			if(objectp(o_char))
			{
				o_char->simple_action
                                ("$N????????$s??????\n$N????????????????\n");
			}
		}
		CHAR_D->set_char(p_list[i],"task",TASK_NONE);
		CHAR_D->remove_npc_char(p_list[i]);
	}
	CHANNEL_D->deliver_tell("rumor","system",
	sprintf("%s????????????????????????",AREA_D->get_area(p_area,"name")));
	AREA_D->set_area(p_area,"status",ST_NORMAL);

	TASK_D->remove_task(p_id);
	
}
void meet_process(int p_id)
{
	int p_stage;
	p_stage=TASK_D->get_task(p_id,"stage");
	switch(p_stage)
	{
	case LMS_BEGIN:
		meet_announce(p_id);
		break;
	case LMS_PROCESS:
		meet_readytoend(p_id);
		break;
	case LMS_DISCUSS:
		meet_happens(p_id);
		break;
	case LMS_IDLE:
		break;
	case LMS_END :
	default:
		meet_over(p_id);
	}
}

void party_happen(string c_id,string p_id,int happen)
{
	int wl,ml,rep,rep1;
	int count=0;
	object o_char;
	remove_call_out("party_happen");
	o_char = CHAR_D->find_char(c_id);
	wl = CHAR_D->get_char(c_id,"skills")["sk_wuli"];
	ml = CHAR_D->get_char(c_id,"skills")["sk_meili"];
	rep = CHAR_D->get_char(c_id,"reputation");
	switch(happen) 
{
	case 0:
	if (random(ml) > 15) {
	DELAY_D->delay_simple_action(o_char,
"%^H_RED%^$N????????????????????????????????????????????????\n ???????????????????????????? %^RESET%^ \n",4);
	count++;	
	}
	else
	DELAY_D->delay_simple_action(o_char,
"%^H_GREEN%^$N??????????????????????????????????????\n ??????????????????????????????????????%^RESET%^ \n",4);
	if (random(ml) > 25) {
 	DELAY_D->delay_simple_action(o_char,
"%^H_RED%^$N????????????????????????????????????????????????\n ????????????????????????????????????????????????%^RESET%^ \n",8);
 	count+= 3;
	}
	else 
	DELAY_D->delay_simple_action(o_char,
"%^H_GREEN%^$N??????????????????????????????????\n ??????????????????%^RESET%^ \n",8);
	if (random(ml) >30) {
	DELAY_D->delay_simple_action(o_char,
"%^H_RED%^$N???????????????????????????????????????????????????????????? \n ??????????????????????????????????????????????????????%^RESET%^ \n",12);
	count +=5;
	}
	else
	DELAY_D->delay_simple_action(o_char,
"%^H_GREEN%^$N????????????????????????????????????????????????\n ??????????????????????%^RESET%^ \n",12);
	if (count >=4) 
	DELAY_D->delay_simple_action(o_char,
"%^H_RED%^$N????????????????????????%^RESET%^ \n",13);
	else 
	DELAY_D->delay_simple_action(o_char,
"%^H_RED%^$N????????????????????????????????%^RESET%^ \n",13);
	rep1 = count * (100 +random(100));
	rep = rep + rep1;
	CHAR_D->set_char(c_id,"reputation",rep);
	DELAY_D->delay_simple_action(o_char,
"$N????????"+chinese_number(rep1)+"????\n",14);
	break;

	case 1:
	if (random(ml) > 15) {
        DELAY_D->delay_simple_action(o_char,
"%^H_RED%^$N????????????????????????\n ??????????????????????????????????????%^RESET%^ \n",4);
        count++;
        }
        else
        DELAY_D->delay_simple_action(o_char,
"%^H_GREEN%^$N????????????????????????????\n ??????????????%^RESET%^ \n",4);
        if (random(ml) > 25) {
        DELAY_D->delay_simple_action(o_char,
"%^H_RED%^$N??????????????????????????????\n ????????????????????????????%^RESET%^ \n",8);
        count+= 3;
        }
        else
        DELAY_D->delay_simple_action(o_char,
"%^H_GREEN%^$N??????????????????????????????????\n ??????????????%^RESET%^ \n",8);
        if (random(ml) >30) {
        DELAY_D->delay_simple_action(o_char,
"%^H_RED%^$N????????????????????????????????????????????\n ????????????????????????????????????????%^RESET%^ \n",12);
        count +=5;	
	}
        else
        DELAY_D->delay_simple_action(o_char,
"%^H_GREEN%^$N??????????????????????????????????????\n ??????????????????????????????????????????%^RESET%^ \n",12);
        if (count >=4)
        DELAY_D->delay_simple_action(o_char,
"%^H_RED%^$N????????????????????????%^RESET%^ \n",13);
        else 
	DELAY_D->delay_simple_action(o_char,
"%^H_RED%^$N????????????????????????????????%^RESET%^ \n",13);
        rep1 = count * (100 +random(100));
	rep = rep + rep1;
        CHAR_D->set_char(c_id,"reputation",rep);
	DELAY_D->delay_simple_action(o_char,
"$N????????"+chinese_number(rep1)+"????\n",14);
        break;
		
	case 2:
	if (random(wl) > 15) {
        DELAY_D->delay_simple_action(o_char,
"%^H_RED%^$N????????????????????????????????????\n ??????????????????%^RESET%^ \n",4);
        count++;
        }
        else
        DELAY_D->delay_simple_action(o_char,
"%^H_GREEN%^$N????????????????????????\n ??????????????%^RESET%^ \n",4);
        if (random(wl) > 25) {
        DELAY_D->delay_simple_action(o_char,
"%^H_RED%^$N??????????????????????????????????????????????????????\n ??????????????????????????????????????%^RESET%^ \n",8);
        count+= 3;
        }
        else
        DELAY_D->delay_simple_action(o_char,
"%^H_GREEN%^$N??????????????????????????\n ??????????????????%^RESET%^ \n",8);
        if (random(wl) >30) {
        DELAY_D->delay_simple_action(o_char,
"%^H_RED%^$N????????????????????????????????????????????\n ??????????????????????????????????%^RESET%^ \n",12);
        count +=5;
        }
        else
        DELAY_D->delay_simple_action(o_char,	
	"%^H_GREEN%^$N????????????????????????????????\n ????????????????%^RESET%^ \n",12);
        if (count >=4)
        DELAY_D->delay_simple_action(o_char,
"%^H_RED%^$N????????????????????????%^RESET%^ \n",13);
        else 
	DELAY_D->delay_simple_action(o_char,
"%^H_RED%^$N????????????????????????????????%^RESET%^ \n",14);
        rep1 = count * (50 +random(30));
        rep = rep + rep1;
        CHAR_D->set_char(c_id,"reputation",rep);
	DELAY_D->delay_simple_action(o_char,
"$N????????"+chinese_number(rep1)+"????\n",11);
        break;
	} 
	call_out("idle_process",5,p_id);
	return;
}		

void idle_process(string p_id)
{
	remove_call_out("idle_process");
	if (b_num<=size)
	TASK_D->set_task(p_id,"stage",LMS_DISCUSS);
	return;
}
//void ask_localmeeting(object who, object officer)
//{
//   string m_id,y_id;
//    string m_area;
//	int p_check;
//    m_id=(officer->query_id())[0];
//    y_id=(who->query_id())[0];
//    m_area=CHAR_D->get_char(m_id,"area");
//    if((AREA_D->get_area(m_area,"leader"))!=m_id)
//    {
//        string m_title;
//        m_title=OFFICER_D->query_rank_name(
//        (OFFICER_D->query_area_officer_title(
//         AREA_D->get_area(m_area,"level"),0,0))[0]);
//          officer->targetted_action
// 
//("$N??$T????????????????????????$s??????????????????????"+m_title+"??\n",who);
//         return;
//    }
//	
//if(((CHAR_D->get_char(m_id,"nation"))!=(CHAR_D->get_char(y_id,"nation")))||
//	
//((CHAR_D->get_char(m_id,"nation"))!=(CHAR_D->get_char(y_id,"nation"))))
//	{
//        officer->targetted_action
//         ("$N??$T??????????$m$R??????????????????????\n",who);
//         return;
//	}
//	if((file_name(environment(officer)))!=
//	
//((AREA_D->get_area(m_area,"path"))+(AREA_D->get_area(m_area,"meeting"))))/
//	{
//       officer->targetted_action
//         ("$N??$T??????????????????????????????\n",who);
//         return;
//	}
//
//	if(CHAR_D->get_char(y_id,"level")<2)
//	{
//        	officer->targetted_action
//	
//("$N??$T????????$R??????????????????????????????????????\n",who);
//         	return;
//	}
//
//	p_check=can_lmeeting(CHAR_D->get_char(m_id,"area"));
//
//        switch(p_check)
//	{
//	case LM_OK:
//      officer->targetted_action
//         ("$N??$T????$m$R????$s??????????\n",who);
//		if(CHAR_D->get_char(m_id,"status")==STATUS_ONLINE)
//		{
//                        tell_user(m_id,"?????????????? cmd
//localmeeting??\n");
//		}
//		else
//		{
//        officer->targetted_action
//         ("$N??$T??????????????\n",who);
//		local_meeting(CHAR_D->get_char(m_id,"area"));
//		}
//		return;
//	case LM_OTHERTASK:
//        officer->targetted_action
//         ("$N??$T??????????????$s??????????????????????\n",who);
//         return;
//	case LM_ALREADYLOCALMEETING:
//        officer->targetted_action
// 
//("$N??$T????$m$R??????????????????????????????????????????????????\n",who);
//         return;
//	case LM_NOENOUTHCHAR :
//        officer->targetted_action
//         ("$N??$T??????$m$R??????????????????????????\n",who);
//         return;
//	case LM_TOOMANYABSENT:
//	default:
//      officer->targetted_action
// 
//("$N??$T??????$m$R??????????????????????????????????????????\n",who);
//         return;
//	}
//}
