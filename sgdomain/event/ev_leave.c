/* ev_leave.c
   this is used to handle an officer resign
   by fire on Aug,28, 1998 */
/* emperor add function NpcsInArea(string a_id,string para)
*/
mixed leave(string p_id);
private int has_retired;
private int times=0;

/************************************************************/
/*  adjust_npc() ����NPC���ڵ�����nation��npc��nation��һ��   */
/************************** emperor *************************/
void adjust_npc(){
	string *list_char,*list_area;
	list_area = AREA_D->list_areas();
	foreach(string a_id in list_area){
		list_char=CHAR_D->check_char("area",a_id);
		list_char=filter_array(list_char,(:CHAR_D->get_char(($1),"type")==TYPE_NPC:));
		foreach(string t_id in list_char){
/*
			if(AREA_D->get_area(CHAR_D->get_char(t_id,"area"),"nation")!=CHAR_D->get_char(t_id,"nation"))
			{
				CHAR_D->set_char(t_id,"nation",AREA_D->get_area(CHAR_D->get_char(t_id,"area"),"nation"));
				CHAR_D->set_char(t_id,"ranknation",2000+random(3000));
				CHAR_D->set_char(t_id,"ranklocal",2000+random(3000));
				(EV_POSITION)->npc_aut_localposition(t_id);
			}
*/
			if(CHAR_D->get_char(t_id,"ranklocal")>1000) {
				CHAR_D->set_char(t_id,"ranknation",0);
				CHAR_D->set_char(t_id,"ranklocal",0);
				CHAR_D->set_char_loyalty(t_id,CHAR_D->get_char(t_id,"nation"),80+random(20));
				CHAR_D->setchar_localcontribution(t_id,2000+random(3000),a_id);
				(EV_POSITION)->npc_aut_localposition(t_id);
			}
		}
	}
    CHAR_D->set_char_modified();
}

mixed check_npc(){
	mixed list_char;
	list_char=CHAR_D->list_chars();
	list_char=filter_array(list_char,(:CHAR_D->get_char(($1),"type")==TYPE_NPC:));
	list_char=filter_array(list_char,(:CHAR_D->get_char(($1),"is_tmp")==0:));

	list_char = filter_array( list_char, (: member_array( CHAR_D->get_char($1,"ranknation"),OFFICER_D->get_officer("list"))==-1 :) );
	return list_char;
}

mixed NpcsInArea(string a_id,string para){
	string *list_char;
	if(CHAR_D->get_char(AREA_D->get_area(a_id,"nation"),"type")!=TYPE_NPC) return 1000;
//	int o_count;
	list_char=CHAR_D->check_char("area",a_id);
	if(!list_char) return 0;
//	o_count=sizeof(list_char);
	if(!sizeof(list_char))return 0;
	list_char=filter_array(list_char,(:CHAR_D->get_char(($1),"type")==TYPE_NPC&&CHAR_D->get_char(($1),"is_tmp")==0:));
	switch(para){
	case "o"://����NPC��Ա����
		list_char=filter_array(list_char,function(string c_id){
			string n=CHAR_D->get_char(c_id,"nation");
			if((!n)||(n=="")) return 0;
			return 1;
		});
		break;
	case "ys"://����NPC��ʿ����
		list_char=filter_array(list_char,function(string c_id){
			string n=CHAR_D->get_char(c_id,"nation");
			if((!n)||(n=="")) return 1;
			return 0;
		});
		break;
	default ://��������NPC����
		break;
	}
	return list_char;
}

mixed area_npcnum(int i){
	string *list_area;
	list_area = AREA_D->list_areas();
	list_area = filter_array(list_area,(: sizeof(NpcsInArea($1,"o"))<$(i) :));
	return sort_array(list_area,(:strcmp($1,$2)<0?-1:1:));
}
void npc_leave(string p_id,string a_id){
	object p_o;
	string p_mess;
	p_o=CHAR_D->find_char(p_id);
	if(objectp(p_o))
	{
		p_o->simple_action("$N̾�˿��������������˴����ҷ�չ֮�ء�\n");
		p_o->simple_action("$N�Ҵ��뿪�ˡ�\n");
	}
	p_mess=sprintf("%s����%s��������Ȼ���ٳ��ߡ�\n",CHAR_D->get_char(p_id,"name"),
		COUNTRY_D->get_country(CHAR_D->get_char(p_id,"nation"),"name"));
	CHANNEL_D->deliver_tell("rumor","system",p_mess);
	CHAR_D->set_char(p_id,"ranknation",0);
	CHAR_D->set_char(p_id,"ranklocal",0);
	CHAR_D->set_char(p_id,"nation",0);

//	a2_id = a2[random(sizeof(a2))];
	CHAR_D->set_char(p_id,"area",a_id);
	CHAR_D->appear(p_id,a_id);
	CHANNEL_D->deliver_tell("rumor","system",
		sprintf("%sͶ��%sȥ�ˡ�",CHAR_D->get_char(p_id,"name"),
			AREA_D->get_area(a_id,"name")));
	CHAR_D->set_char(p_id,"nation",AREA_D->get_area(a_id,"nation"));
	CHAR_D->set_char_loyalty(p_id,CHAR_D->get_char(p_id,"nation"),80+random(20));
	CHAR_D->setchar_localcontribution(p_id,2000+random(3000),a_id);
}

void auto_transfernpc(){
	string *list_area,*a1,*a2;
	a2 = area_npcnum(4);
	a2=filter_array(a2,(:CHAR_D->get_char(AREA_D->get_area($1,"nation"),"type")==TYPE_NPC:));
	if(sizeof(a2)==0) return;
	list_area = AREA_D->list_areas();
	a1=list_area-area_npcnum(5);
	if(sizeof(a1)==0) return;	
	{
		object p_o;
		string *npcs,p_nation,a_id,p_id;
		int *my_task,task_id;
		a_id=a1[random(sizeof(a1))];
		npcs = NpcsInArea(a_id,"ys");
		if(!sizeof(npcs)){
			npcs = NpcsInArea(a_id,"o");
			p_id=npcs[random(sizeof(npcs))];
			p_nation=CHAR_D->get_char(p_id,"nation");
        	if(p_nation==p_id) {
        		call_out("auto_transfernpc",2);
        		return;// "����������ְ��\n";
			}
    		my_task = TASK_D->get_char_task(p_id);
    		task_id=my_task[0];
			if(task_id!=-1){
				call_out("auto_transfernpc",2);
				return;// "������æʱ������ְ��\n";
			}
			npc_leave(p_id,a2[random(sizeof(a2))]);
			(EV_POSITION)->npc_aut_localposition(p_id);
			call_out("auto_transfernpc",2);
			return;
		}
		p_id=npcs[random(sizeof(npcs))];
//		a_id = a2[random(sizeof(a2))];
		npc_leave(p_id,a2[random(sizeof(a2))]);
		(EV_POSITION)->npc_aut_localposition(p_id);
        call_out("auto_transfernpc",2);
	}
}

/*
mixed NpcOfficersInArea(string a_id){
	string *list_char;
//	int o_count;
	list_char=CHAR_D->check_char("area",a_id);
	if(!list_char) return 0;
//	o_count=sizeof(list_char);
	if(!sizeof(list_char))return 0;
	list_char=filter_array(list_char,(:CHAR_D->get_char(($1),"type")==TYPE_NPC:));
	return list_char;
}
*/
int auto_leave(string p_id)
{
	int p_loyalty;
	string p_area,p_nation;

	if(CHAR_D->get_char(p_id,"is_tmp")) return 0;
	if(CHAR_D->get_char(p_id,"type")==TYPE_PLAYER) return 0;

	if(CHAR_D->get_char(p_id,"task")) return 0;

	if(!COUNTRY_D->nation_exist(CHAR_D->get_char(p_id,"nation"))) return 0;
//Added by suicide for localleader will not cmd leave.
	if (AREA_D->get_area(CHAR_D->get_char(p_id,"area"),"leader")==p_id) return 0;
	p_loyalty=CHAR_D->get_char(p_id,"loyalty");
	if(p_loyalty>90) return 0;
	if(random(110)>p_loyalty) {
		leave(p_id);
		return 1;
	}
}
mixed leave(string p_id)
{
	string p_mess;
	int p_loyalty,p_reputation;
	int *my_task,task_id;
	string p_area,p_nation,p_leader;
	string a_id;// Emperor add the Var.
	p_area=CHAR_D->get_char(p_id,"area");
	p_nation=CHAR_D->get_char(p_id,"nation");
        if(p_nation==p_id) return "����������ְ��\n";

    my_task = TASK_D->get_char_task(p_id);
    task_id=my_task[0];
	if(task_id!=-1)
                return "������æʱ������ְ��\n";
// emperor add ��Ա��С��3ʱ�����뿪
	a_id=CHAR_D->get_char(p_id,"area");
	if(NpcsInArea(a_id,"o")!=1000)
        if(sizeof(NpcsInArea(a_id,"o"))<4 && CHAR_D->get_char(p_id,"type")==TYPE_NPC) 
		return "NPC��Ա������4ʱ������ְ��\n";
// emperor add
		
	p_mess=sprintf("%s����%s��������Ȼ���ٳ��ߡ�\n",
		CHAR_D->get_char(p_id,"name"),
	COUNTRY_D->get_country(CHAR_D->get_char(p_id,"nation"),"name"));
//Added by suicide for clear guoshi info when ind
	if (COUNTRY_D->get_country(CHAR_D->get_char(p_id,"nation"),"gs")==p_id)
	    COUNTRY_D->set_country(CHAR_D->get_char(p_id,"nation"),"gs",0);   
	p_loyalty=CHAR_D->get_char(p_id,"loyalty");
	p_reputation=CHAR_D->get_char(p_id,"reputation");
	p_loyalty/=3;
	if(p_loyalty>20)
		p_loyalty=20;
	p_reputation/=3;
	CHAR_D->set_char(p_id,"loyalty",p_loyalty);
	CHAR_D->set_char(p_id,"reputation",p_reputation);
	CHAR_D->set_char(p_id,"ranknation",0);
	CHAR_D->set_char(p_id,"ranklocal",0);
	CHAR_D->set_char(p_id,"nation",0);
	
	//2001.4.24 �ó��ߵ�NPC��������ǰ�趨��whisper job��������ڵ�
	{string f_id,f_area;
	if (f_id=CHAR_D->get_char(p_id,"friend"))
	   f_area = CHAR_D->get_char(f_id,"area");
	if (f_area)
	   CHAR_D->set_char(p_id,"area",f_area);
	else
	   CHAR_D->set_char(p_id,"area",AREA_D->pick_area());
	}
       CHAR_D->set_char(p_id,"nc",0);
	CHANNEL_D->deliver_tell("rumor","system",p_mess);
	return 1;
}

void addleave_all() {
	int i;
	string *list;
	times++;
	list=CHAR_D->check_char("type",TYPE_NPC);
	list=filter_array (list,
		(:CHAR_D->get_char(($1),"is_tmp")==0:));

	list=filter_array (list,
		(:CHAR_D->get_char(($1),"nation")==0:));

	if(sizeof(list)<60) {
		return;		// so the number of free npc should be limited
	}

	remove_call_out("addleave_all");
	if(times>5) return;
	call_out("addleave_all",30);
	for(i=0;i<20;++i)
		if(auto_leave(CHAR_D->pick_char()))
			return;
}
void addleave()
{
	times=0;
	call_out("addleave_all",1);
}

void must_retire() {
	string p_id;
	string n_id;
	string res;
	int age;
	p_id=CHAR_D->pick_char();

	if(has_retired==1) return;
	call_out("must_retire",1);
	if(CHAR_D->get_char(p_id,"is_tmp")) return;
	if(CHAR_D->get_char(p_id,"type")==TYPE_PLAYER) return;

	if(CHAR_D->get_char(p_id,"task")) return;

	n_id=CHAR_D->get_char(p_id,"nation");
		
	if(!COUNTRY_D->nation_exist(n_id)) return;
	if(n_id==p_id) return;

	if((CHAR_D->get_skill(p_id,"sk_wuli")>90) || 
		(CHAR_D->get_skill(p_id,"sk_zhimou")>90) ||
		(CHAR_D->get_skill(p_id,"sk_meili")>90) )
		return; // so the high level npc will not retire sigh
// emperor add ��Ա��С��3ʱ�����뿪
	if(sizeof(NpcsInArea(CHAR_D->get_char(p_id,"area"),"o"))<4) 
		return;
// emperor add
	age=CHAR_D->get_char(p_id,"age");
	if(age>45) 
		res="�������꣬��������������������һ��ʱ�䡣";
	else
		res="�������꣬��Ϊ���Ѿã������̽��һ��ĸ�ס�";

	CHANNEL_D->deliver_tell("gossip",CHAR_D->get_char(p_id,"name"),res);
	CHANNEL_D->deliver_tell("gossip",CHAR_D->get_char(n_id,"name"),"��. . . .");
	CHANNEL_D->deliver_tell("rumor","system",CHAR_D->get_char(p_id,"name")+
		"��Ұ�ˡ�");

	CHAR_D->set_char(p_id,"ranknation",0);
	CHAR_D->set_char(p_id,"ranklocal",0);
	CHAR_D->set_char(p_id,"nation",0);
	CHAR_D->set_char(p_id,"area",AREA_D->pick_area());
	CHAR_D->set_char(p_id,"retire",time()+86400+random(86400*3));
	has_retired=1;

}
void retire() {
	string *list;
	list=CHAR_D->check_char("type",TYPE_NPC);
	list=filter_array (list,
		(:CHAR_D->get_char(($1),"is_tmp")==0:));

	list=filter_array (list,
		(:CHAR_D->get_char(($1),"nation")==0:));

	if(sizeof(list)<10) {
		has_retired=0;
		call_out("must_retire",1);
	}
	
	
}
