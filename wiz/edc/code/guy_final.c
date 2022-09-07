// guy_final.c by fire on Dec 1998
#include <security.h>
inherit M_ACCESS;
#define LOG_FILE "/sgdomain/modules/m_charnpc/guy/setppl.log"
private string act;
string query_leader();
void do_my_dispear();
void award(object usr);
void set_act(string p)
{
   act=p;
}
int log_me(string msg) {
	unguarded(1, (: write_file, LOG_FILE, msg :));
	return 1;
}
void  select_num()
{
   string p_id;
   object usr;
   p_id=query_leader();
   usr=find_user(p_id);
   if(!objectp(usr)) 
   {
       do_my_dispear();
   }
   if (this_object()->query("is_fake")) //fake people no robot test
   	   award(usr);
	else
	{
	   this_object()->targetted_action(
			"һ$N��$T������������֮ǰ��������⣬����᲻�ᡣ\n",find_body(p_id));
	   ROBOT->robot_test(usr,(:award:));
	}
}
void award(object usr)
{
   string p_id;
   int isrobot;
   mapping troop;
   int p_population,p_safe;
   int p_left;
   object master;
   string p_area;
   string f_id;
   string r_id;
   string m_area;
   object bs;
   string p_tmp;
   int old_data;
   string what_i_got="�±�";  //added by edc
   int rdm_i_got=0; // added by edc


   p_id=query_leader();
   if(!objectp(usr)) {do_my_dispear();return;}
   usr=usr->query_body();
   if(!objectp(usr)) {do_my_dispear();return;}
   
   if (this_object()->query("is_fake")) //do penalty
   {
	this_object()->targetted_action(
		"��$N��$T����$m$R������Ҳ��������չ��һ������ǰ;��\n",usr);
//this is for temp track of success rate
	CHAR_D->set_char("listen","setpplsuccess",
		CHAR_D->get_char("listen","setpplsuccess")+1); 
//temp end here
	if(act=="followme")
	{
		old_data= CHAR_D->get_char(p_id,"gold");
		CHAR_D->set_char(p_id,"gold",
		   CHAR_D->get_char(p_id,"gold")-50);
		if (CHAR_D->get_char(p_id,"gold")<0)
		   CHAR_D->set_char(p_id,"gold",0);
		tell_user(p_id,"%^H_GREEN%^�ܲ��ң��㱻ƭ��50�����ӡ�%^RESET%^\n");
		p_tmp=sprintf("\n time at %s ,%s  gold change from %d to %d",
			CHINESE_D->chinese_time(time()),p_id,old_data,CHAR_D->get_char(p_id,"gold"));
		log_me(p_tmp);
		if (stringp(this_object()->query("master")))
			tell_user(this_object()->query("master"),"%^H_RED%^���ɸ봫�顿�ܱ���"+
				"�᷽����ѳɹ�����"+CHAR_D->get_char(p_id,"name")+"���С�%^RESET%^\n");
	}
	else if(act=="recruit")
	{
		p_area=CHAR_D->get_char(p_id,"area");

		old_data=AREA_D->get_area_soldier(p_area,"sum");
		if (!AREA_D->reduce_soldier(p_area,"sum",100)) //no enough soldier to reduce
		{
			p_safe=AREA_D->get_area(p_area,"safe"); //safe -10
			p_population=AREA_D->get_area(p_area,"population");//population -2%-200
			
			p_safe-=10;
			if (p_safe<0)
				p_safe=0;
			AREA_D->set_area(p_area,"safe",p_safe);
			p_population-=(p_population/20+200);
			if (p_population<100)
				p_population=100;
			AREA_D->set_area(p_area,"population",p_population);
      		}
      		p_tmp=sprintf("\n time at %s ,%s troop change from %d to %d",
			CHINESE_D->chinese_time(time()),p_area,old_data,AREA_D->get_area_soldier(p_area,"sum"));
		log_me(p_tmp);
		usr->simple_action("�������Ŵ��ˣ�$N�ĵ������ܵ�������ʧ��\n");
		if (stringp(this_object()->query("master")))
			tell_user(this_object()->query("master"),"%^H_RED%^���ɸ봫�顿�ܱ���"+
				"�᷽����ѳɹ�����"+AREA_D->get_area(p_area,"name")+"���ӡ�%^RESET%^\n");
	
		p_left=(PJOB+"recruit/recruit")->get_recruit_left(p_id);
		p_left-=50;
		usr->finish_job("recruit");
		if(p_left>=50)
		{
			usr->add_job("recruit");
			usr->set_job("recruit","left",p_left);
			usr->set_job("recruit","memo","��"+p_left+"��");
			tell_user(p_id,"�㻹��Ҫ��"+chinese_number(p_left)+
// edc
				"��ʿ����\n");
/*				"���±���\n");*/
////
		}
	}
	else if(act=="getppl")
	{
		master=find_body(p_id);
		p_area=master->query_job("getppl","p_area");
		f_id=master->query_job("getppl","f_id");
		r_id=master->query_job("getppl","r_id");
		m_area=this_object()->query_room()->get_area();
		bs=SGBASE(p_area,f_id);
		
		usr->simple_action("�������Ŵ���,$N��ũ���⵽������ʧ��\n");
		if (stringp(this_object()->query("master")))
			tell_user(this_object()->query("master"),"%^H_RED%^���ɸ봫�顿�ܱ���"+
				"�᷽����ѳɹ�����"+AREA_D->get_area(p_area,"name")+"ũ����%^RESET%^\n");
		usr->finish_job("getppl");
		if(objectp(bs)) 
		{
			old_data= bs->get_base_pplnum();
			bs->reduce_ppl(r_id,100);
			p_tmp=sprintf("\n time at %s ,%s level %d farmers change from %d to %d",
				CHINESE_D->chinese_time(time()),p_area,bs->get_level(),old_data,bs->get_base_pplnum());
			log_me(p_tmp);
		}
	}
	else
	{
		SGSYS("Not one of getppl,recruit & followme happened in guy_final action!");
		usr->simple_action("�ڲ�������,�뾡������ʦ������һ����лл���ĺ�����\n");
	}
		
	do_my_dispear();
	return;
   }

//End of fake guy penalty

   isrobot=usr->query_body()->query_robot();
   if(isrobot)
   { this_object()->targetted_action(
         "��$N��$T���������Ǹ��׳գ��治�ܸ�$m�ܡ�\n",usr);
      do_my_dispear(); 
      return;
   } 

   if(act=="followme")
   {    CHAR_D->set_char(p_id,"newqb",50);
        tell_user(p_id,"%^H_GREEN%^��ϲ�����е���ʮ���ױ���%^RESET%^\n");
   }
   else if(act=="recruit")
   {
       int p_soldier,p_morale,p_train; 
	   p_area=CHAR_D->get_char(p_id,"area");
        //      p_soldier=AREA_D->get_area(p_area,"soldier");
	troop = AREA_D->get_area(p_area, "troop");
	if( !troop || !mapp(troop) || !sizeof(troop) )troop = ([ ]);
	foreach(string tt in keys(troop))p_soldier+=troop[tt];
        p_morale=AREA_D->get_area(p_area,"morale");
        p_train=AREA_D->get_area(p_area,"train");
        p_train=(p_train*p_soldier+750)/(p_soldier+50);
        p_morale=(p_morale*p_soldier+750)/(p_soldier+50);

// edc 08/04/2001
	// random get multitroop, 1/5 possibility get bowman, cavalry, and 3/5 get footman
	
	rdm_i_got = random(5);
	switch (rdm_i_got)
	{
		case 0:	if( !troop["bowman"] ) troop["bowman"] = 50;
			else troop["bowman"] = troop["bowman"] + 50;
			what_i_got = "����";
			break;
		case 1: if( !troop["cavalry"] ) troop["cavalry"] = 50;
			else troop["cavalry"] = troop["cavalry"] + 50;
			what_i_got = "���";
			break;
		default:
			if( !troop["footman"] ) troop["footman"] = 50;
			else troop["footman"] = troop["footman"] + 50;
			what_i_got = "�±�";
	}
/* edc
//      AREA_D->set_area(p_area,"soldier",p_soldier+50);
	if( !troop["footman"] ) troop["footman"] = 50;
	else troop["footman"] = troop["footman"] + 50;
*/	
////

	AREA_D->set_area(p_area,"troop", troop);
        AREA_D->set_area(p_area,"morale",p_morale);
        AREA_D->set_area(p_area,"train",p_train);
        usr->award_exp(50);
        CHAR_D->set_char(p_id,"reputation",
        CHAR_D->get_char(p_id,"reputation")+50);
        CHAR_D->set_char(p_id,"localcontribution",
        CHAR_D->get_char(p_id,"localcontribution")+2);
// edc  08/04/2001
/*	usr->simple_action("$N�е���ʮ���±���$N�ľ�������������ˡ�\n"); */
	usr->simple_action("$N�е���ʮ��"+what_i_got+"��$N�ľ�������������ˡ�\n");
////	
        p_left=(PJOB+"recruit/recruit")->get_recruit_left(p_id);
        p_left-=50;
        usr->finish_job("recruit");
        if(p_left>=50)
        {
           usr->add_job("recruit");
           usr->set_job("recruit","left",p_left);
		   usr->set_job("recruit","memo","��"+p_left+"��");
           tell_user(p_id,"�㻹��Ҫ��"+chinese_number(p_left)+
// edc
		"��ʿ����\n");
/*            "���±���\n");  */
////
        }
	p_area=usr->query_room()->get_area(); 
	{
		p_population=AREA_D->get_area(p_area,"population");
		p_safe=AREA_D->get_area(p_area,"safe");
		p_safe--; p_safe=bmax(p_safe,0);
		p_population-=50; p_population=bmax(100,p_population);
		AREA_D->set_area(p_area,"safe",p_safe);
		AREA_D->set_area(p_area,"population",p_population);
		CHANNEL_D->deliver_tell("rumor","system",
			usr->query_chinese_id()+"��"+AREA_D->get_area(p_area,"name")+
			"�����������˿ںͰ����½��ˡ�");
	}
   }
   else if (act=="getppl") {
		master=find_body(p_id);
	   p_area=master->query_job("getppl","p_area");
	   f_id=master->query_job("getppl","f_id");
	   r_id=master->query_job("getppl","r_id");
	m_area=this_object()->query_room()->get_area();
	bs=SGBASE(p_area,f_id);
		AWARD(usr,20);
        usr->simple_action("$N��������ʮ��"+BASE_D->get_base(f_id,"workername")+
			"��$N�õ��˽�����\n");

        usr->finish_job("getppl");
		{
			p_population=AREA_D->get_area(m_area,"population");
			p_safe=AREA_D->get_area(m_area,"safe");
			p_safe--; p_safe=bmax(p_safe,0);
			p_population-=50; p_population=bmax(100,p_population);
			AREA_D->set_area(m_area,"safe",p_safe);
			AREA_D->set_area(m_area,"population",p_population);
			CHANNEL_D->deliver_tell("rumor","system",
				usr->query_chinese_id()+"��"+AREA_D->get_area(m_area,"name")+
				"����һ��"+BASE_D->get_base(f_id,"workername")+"�������˿ںͰ����½��ˡ�");
		}
		if(objectp(bs)) 
			bs->add_ppl(r_id,50);
   }
   do_my_dispear();
}
