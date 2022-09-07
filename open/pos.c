//qb.c this is used to give qb command by fire on Jan 1999
//pos.c  Modified by suicide in 2000.08 for taishou&guoshi system

#include <menu.h>
#include <mudlib.h>
#include <verb.h>

inherit MENUS;
inherit M_ACCESS;
inherit M_GRAMMAR;
inherit M_GLOB;
//inherit __DIR__ + "/pos/pos2";
MENU toplevel;
MENU_ITEM quit_item;
MENU_ITEM seperator;

private string p_id,p_area,p_nation,p_name;
private string t_id,t_area,t_nation,t_name;
private int p_ranklocal,p_ranknation,t_ranklocal,t_ranknation;
private mixed ret;
private string dis;
mixed check_confirm(string cfm);
mixed am_i_king();
void show_invalid_check();
void init_me();

//added by suicide to confirm if the area is under guoshi's control
int is_under_guoshi_control(string p_area)
{string m_id,na;
 mixed grant;
 na = AREA_D->get_area(p_area,"nation");
 if (!COUNTRY_D->get_country(na,"gs")) return 1;
 m_id = AREA_D->get_area_leader(p_area);
 if (!CHAR_D->char_exist(m_id)) return 1;
 if (m_id==p_id) return 1;
 if (CHAR_D->get_char(m_id,"fealty")==p_id) 
    return 1;
 if (CHAR_D->get_char(m_id,"fealty")==CHAR_D->get_char(p_id,"fealty")) 
    return 1;
 grant = CHAR_D->get_char(m_id,"grant");  //�Ƿ����ݴ�̫��
 if ((!grant)&&(CHAR_D->get_char(m_id,"type")==TYPE_NPC)) return 1;
 if (grant) 
    if (CHAR_D->get_char(grant["leader"],"fealty")==p_id)
        return 1;
 return 0;
}


////////////////////// general check /////////////////////////
mixed does_he_fit_position(int r) {
	mixed rr;
	rr=(EV_POSITION)->check_whole(t_id,r);
	if(stringp(rr))
		return t_name+"��"+rr+"����";
	return 1;
}

mixed am_i_him() {
	if(t_id==p_id) return "��ʲô��Ц��";
	return 1;
}
mixed am_i_busy(){
	int *my_task;
	my_task=TASK_D->get_char_task(p_id);
	if(my_task[0]!=-1) return "��������æ�أ���æ���ٴ�����Щ�ɡ�";
	return 1;
}


mixed am_i_king() {
	if(p_nation==p_id)
		return 1;
	if(COUNTRY_D->get_country(p_nation,"gs")==p_id)
		return 0;
	return "�㲻�ǹ�����";
}

mixed am_i_local_leader() {
	if(AREA_D->get_area(p_area,"leader")==p_id)
		return 1;
	return "�㲻�ǵط����졣";
}

mixed am_i_potential_leader() {
	mixed p_grant;
	if(!p_nation) return "�㻹���ǹ�Ա��";

	t_id=AREA_D->get_area(p_area,"leader");
	if(t_id==p_id) return "��û��̫��ְȨ��ʱ����ȥ�";
	if(p_id==p_nation) return 1; // i am king
	p_grant=CHAR_D->get_char(t_id,"grant");
	if((!p_grant)|| 
		(p_grant["area"]!=p_area) ||
		(p_grant["leader"]!=p_id) ||
		(p_grant["nation"]!=p_nation))
			return "�㲻�Ǳ�����������̫�ذɡ�";
	return 1;
}

mixed is_he_busy() {
	int *his_task;
	his_task=TASK_D->get_char_task(t_id);
	if(his_task[0]!=-1) return t_name+"������æ�أ�����æ����˵�ɡ�";
	return 1;
}

mixed is_he_local_officer() {
	if(t_id==p_id) return "��ʲô��Ц��";
	if(!t_name) return "û��"+t_id+"�����ɫ��";
	if(t_area!=p_area) return t_name+"���ڱ�������";
	if(!t_ranklocal) return t_name+"���Ǳ��ع�Ա��";
	return 1;
}
mixed is_he_local_officera() {
	if(t_id==p_id) return "��ʲô��Ц��";
	if(!t_name) return "û��"+t_id+"�����ɫ��";
	if(t_area!=p_area) return t_name+"���ڱ�������";
	if((!t_ranklocal)&&(t_nation!=p_nation)) return t_name+"���Ǳ��ع�Ա��";
	return 1;
}
mixed is_he_not_king() {
	if(t_id==p_nation) return "��ʲô��Ц��"; // try adjust king
	return 1;
}
mixed is_he_our_nation() {
	if(!t_name) return "û��"+t_id+"�����ɫ��";
	if(t_nation!=p_nation) return t_name+"���Ǳ�����Ա��";
	return 1;
}
///////////////////////// withdraw gold for king ////////////////////////////
mixed can_i_withdraw(int n) {
	int p_safe;
	int p_gold;
	mixed rr;
	if(p_id!=p_nation) return "ֻ�����������������";
	p_safe=AREA_D->get_area(p_area,"safe");
	p_gold=MONEY_D->get_all_money(find_body(p_id));
	if(p_gold>50000000) return "���Ǯ�Ѿ������ˣ���Ҫ̫̰�ġ�";
	if(p_safe<50) return "���������Ĳ��ȣ������������⡣"; 
        if(n<=10)
            return "��Ľ�̫���ˡ�";
        if(n>100) return "һ�β������̫�ࡣ";
	if(n>COUNTRY_D->get_country(p_nation,"gold"))
            return "����û����ô���";
        rr=(EV_POSITION)->check_whole(p_id,R_KING);      
	if(stringp(rr)) return "���"+rr+"̫�ͣ�û���ʸ�ӹ�����Ǯ��";
        return rr;
}
void done_real_getgold(string str,string cfm) {
        int p_tm;
        ret=check_confirm(cfm);
        if(!ret) return;
	p_tm=to_int(str);
        init_me();
        ret=am_i_king();
        if(stringp(ret)) { show_invalid_check(); return;} 
        ret=can_i_withdraw(p_tm);
        if(stringp(ret)) { show_invalid_check(); return;} 
        COUNTRY_D->set_country(p_nation,"gold",
           COUNTRY_D->get_country(p_nation,"gold")-p_tm);
        CHAR_D->set_char(p_id,"gold",
           CHAR_D->get_char(p_id,"gold")+p_tm);
	
	"/daemons/nation_channel_d"->deliever_enter(p_id, 
           "��������̫����ƶ������������"+chinese_number(p_tm)+
           "������ʹʹ��������");
        if(random(COUNTRY_D->get_country(p_nation,"gold")) <
            CHAR_D->get_char(p_id,"gold")) {
	    AREA_D->set_area(p_area,"safe",
              AREA_D->get_area(p_area,"safe")-10);
            CHANNEL_D->deliver_tell("rumor","system",
               AREA_D->get_area(p_area,"name")+
               "��������������ӻ����⣬���ذ������½���");
        }
}
void done_getgold(string str) {
        get_input_then_call
     ((: done_real_getgold, str:), "ȷ����[y/n]");   
}
void init_me() {
	p_id=this_body()->query_id()[0];
	p_area=CHAR_D->get_char(p_id,"area");
	p_nation=CHAR_D->get_char(p_id,"nation");
	p_name=CHAR_D->get_char(p_id,"name");
	p_ranklocal=CHAR_D->get_char(p_id,"ranklocal");
	p_ranknation=CHAR_D->get_char(p_id,"ranknation");

}
void start_menu()
{
	init_menu_application( toplevel );
}

void feed_target(string pp_id) {
	t_id=pp_id;
	t_area=CHAR_D->get_char(pp_id,"area");
	t_nation=CHAR_D->get_char(pp_id,"nation");
	t_name=CHAR_D->get_char(pp_id,"name");
	t_ranklocal=CHAR_D->get_char(pp_id,"ranklocal");
	t_ranknation=CHAR_D->get_char(pp_id,"ranknation");
}


mixed check_confirm(string cfm) {
	if(!sizeof(cfm)) return 0;
	if((cfm[0]=='y')||(cfm[0]=='Y'))
		return 1;
	return 0;
}
void show_invalid_check() {
	if(stringp(ret)) 
		write("%^H_RED%^"+ret+"%^RESET%^\n");
	prompt_then_return();
}


void done_give(string id,string cfm) {

	mixed p_grant;
	string mm_id;
	ret=check_confirm(cfm);
	if(!ret) return;
	init_me();
	ret=am_i_local_leader();
	if(stringp(ret)) {	show_invalid_check(); return;}

	feed_target(id);

	ret=is_he_local_officer();
	if(stringp(ret)) { show_invalid_check(); return;} 

	ret=am_i_busy();
	if(stringp(ret)) { show_invalid_check(); return;} 

	ret=does_he_fit_position(p_ranklocal);
	if(stringp(ret)) { show_invalid_check(); return;} 

	ret=is_he_busy();
	if(stringp(ret)) { show_invalid_check(); return;} 

	
	
	p_grant=CHAR_D->get_char(p_id,"grant");
	if(p_grant) {
		mm_id=p_grant["leader"];
		if(CHAR_D->get_char(mm_id,"area")!=p_area)
			p_grant=0;
		if(CHAR_D->get_char(mm_id,"nation")!=p_nation)
			p_grant=0;
		if(!CHAR_D->get_char(mm_id,"ranklocal"))
			p_grant=0;
	}
	if(p_grant&&(mm_id!=t_id)) { // means not the original leader
            ret="�������̫��ְ֮�����ҽ������ˡ�";
            show_invalid_check();return;
        }
	if(!p_grant) {
		p_grant=([]);
		p_grant["area"]=p_area;
		p_grant["nation"]=p_nation;
		p_grant["leader"]=p_id;
	}
	if(mm_id==t_id) p_grant=0;

	CHAR_D->set_char(p_id,"ranklocal",R_SG);
	CHAR_D->set_char(t_id,"ranklocal",p_ranklocal);
	CHAR_D->set_char(t_id,"grant",p_grant);
	CHAR_D->set_char(t_id,"fealty",CHAR_D->get_char(p_id,"fealty"));
	CHAR_D->set_char(p_id,"grant",0);

	dis=sprintf("%s��%s��˾%s%sְ֮��",CHAR_D->get_char(p_id,"name"),
			t_name,AREA_D->get_area(p_area,"name"),
			OFFICER_D->query_rank_name(p_ranklocal));
	CHANNEL_D->deliver_tell("rumor","system",dis);
	tell_user(t_id,"%^H_GREEN%^"+sprintf("%s������˾%s%sְ֮��\n",
		CHAR_D->get_char(p_id,"name"),AREA_D->get_area(p_area,"name"),
		OFFICER_D->query_rank_name(p_ranklocal))+"%^RESET%^");

	p_ranklocal=t_ranklocal;

}


void do_give (string str) {
	get_input_then_call
     ((: done_give, str:), "ȷ������̫��ְ֮��[y/n]");	
}
void done_back(string cfm) {
	ret=check_confirm(cfm);
	if(!ret) return;

	init_me();
	ret= am_i_potential_leader();
	if(stringp(ret)) { show_invalid_check(); return;} 

	feed_target(t_id);

	ret=am_i_busy();
	if(stringp(ret)) { show_invalid_check(); return;} 

	ret=is_he_busy();
	if(stringp(ret)) { show_invalid_check(); return;} 

	CHAR_D->set_char(t_id,"ranklocal",R_SG);
	CHAR_D->set_char(p_id,"ranklocal",t_ranklocal);
	CHAR_D->set_char(t_id,"grant",0);

	dis=sprintf("%s�ִ�%s����Ҫ����%s%s��ְλ��",CHAR_D->get_char(p_id,"name"),
		t_name,AREA_D->get_area(p_area,"name"),
			OFFICER_D->query_rank_name(t_ranklocal));
		CHANNEL_D->deliver_tell("rumor","system",dis);
	tell_user(t_id,"%^H_RED%^"+sprintf("%sҪ����%s%s��ְλ��\n",
			p_name,AREA_D->get_area(p_area,"name"),
			OFFICER_D->query_rank_name(p_ranklocal)));
	return;
	p_ranklocal=t_ranklocal;

}
////////////////// adjust_local_position //////////////////////////////
mixed is_he_fit_local_position(int p_newrank) {
	int *list;
	list=(EV_POSITION)->get_area_vacancy(p_area);
	if(p_newrank==-1) return 1; // dismiss is always acceptable
	if(p_newrank==t_ranklocal) return "�������������ְ��";
	if(!sizeof(list)) return "����û�п�ȱ��";
	if(member_array(p_newrank,list)==-1) return "����û�п�ȱ��";
	return does_he_fit_position(p_newrank);
}
void done_adjust_local(string id, string pos,string cfm) {
	int p_newrank;
	ret=check_confirm(cfm);
	if(!ret) return;
	init_me();
	ret=am_i_local_leader();
	if(stringp(ret)) {	show_invalid_check(); return;}
	feed_target(id);
	ret=is_he_local_officera(); // sure he is local not localofficer but a nation officer
	if(stringp(ret)) { show_invalid_check(); return;} 
	ret=am_i_busy();
	if(stringp(ret)) { show_invalid_check(); return;} 
	ret=is_he_busy();
	if(stringp(ret)) { show_invalid_check(); return;} 

	p_newrank=to_int(pos);
	ret=is_he_fit_local_position(p_newrank);
	if(stringp(ret)) { show_invalid_check(); return;} 
	if(p_newrank!=-1)
		(EV_POSITION)->give_position(t_id,p_newrank,p_area);
	else {
		(EV_POSITION)->give_position(t_id,R_SG,p_area);
	}
}

void which_local_pos(string id,string pos) {
	get_input_then_call
     ((: done_adjust_local, id,pos:), "ȷ����[y/n]��");
}
void do_adjust_local(string id) {
	int *list;
	int i;

	init_me();
	ret=am_i_local_leader();
	if(stringp(ret)) { show_invalid_check(); return;} 


	list=(EV_POSITION)->get_area_vacancy(p_area);
	printf("  ����      ��ְ\n");
	for(i=0;i<sizeof(list);++i)
	{	printf("��%4d��    %s\n",list[i],
			OFFICER_D->query_rank_name(list[i]));
	}
	printf("��%4d��    %s\n",-1,"ת����ְ��Ա");

	get_input_then_call
     ((: which_local_pos, id:), "����Ϊ��ְ��");	
}
///////////////// ���� ///////////////////////////////////////////
mixed can_i_independent() {
	if(p_id==p_nation) return "���Ѿ���һ��֮���ˡ�";
	ret=am_i_local_leader();
	if(ret!=1) return "ֻ�еط�����ſ��ԳƵۡ�";
	if(CHAR_D->get_char(p_nation,"area")==p_area) 
		return "�������ڱ��أ�������������";

	ret=(EV_POSITION)->check_whole(p_id,R_KING);
	if(stringp(ret)) return "���"+ret+"̫���ˡ�";
	return 1;
}
void done_independence(string cfm) {
	int tmp;
	ret=check_confirm(cfm);
	if(!ret) return;

	init_me();

	ret= can_i_independent();
	if(stringp(ret)) { show_invalid_check(); return;} 

	CHAR_D->set_char(p_id,"loyalty",1); // no relations
	CHAR_D->set_char(p_id,"reputation",
		CHAR_D->get_char(p_id,"reputation")*2);
//Added by suicide for clear guoshi info when ind
	if (COUNTRY_D->get_country(CHAR_D->get_char(p_id,"nation"),"gs")==p_id)
	    COUNTRY_D->set_country(CHAR_D->get_char(p_id,"nation"),"gs",0);   
        
        //Added by suicide for in area soldier morale, dec gold for ind
	tmp = AREA_D->get_area(p_area,"morale");
	if (tmp>150) tmp=200;
	   else tmp += 50;
	AREA_D->set_area(p_area,"morale",tmp);
	tmp = AREA_D->get_area(p_area,"gold")-3000*AREA_D->get_area(p_area,"level");
	AREA_D->set_area(p_area,"gold",tmp);
   
	//Added end
	
	dis=sprintf("%s��%s����������",p_name,
		AREA_D->get_area(p_area,"name"));

	CHANNEL_D->deliver_tell("rumor","system",dis);
	
	feed_target(p_nation);

	CHANNEL_D->deliver_tell("gossip",t_name,
		p_name+"���㵨���ѹ����ѣ����Ľ�����ʬ��Ρ�\n");

	CHANNEL_D->deliver_tell("gossip",p_name,
		t_name+"ų�򣬷�������ɡ�\n");

	COUNTRY_D->add_country(p_id,p_area);
        "/sgdomain/menu/buzzer"->room_update(
          AREA_D->get_area(p_area,"path")+
          AREA_D->get_area(p_area,"meeting"));
        "/sgdomain/menu/buzzer"->room_update(
          AREA_D->get_area(p_area,"path")+
          AREA_D->get_area(p_area,"go"));
	
	HIS(p_name+"��"+AREA_D->get_area(p_area,"name")+
		"��"+t_name+"ӵ������������Ϊ��"+p_name+"����");
	return;
}

/////////////////////////�������ҹ�ְ////////////////////////////////////
mixed is_he_fit_nation_position(int p_newrank) {
	int *list;
	list=(EV_POSITION)->get_nation_vacancy(p_nation);
	if((p_newrank==-1)&&(t_ranknation==0)) return "������û�й��ҹ�ְ��";
	if(p_newrank==-1) return 1; // dismiss is always acceptable
	if(p_newrank==t_ranknation) return "�������������ְ��";
	if(!sizeof(list)) return "����û�п�ȱ��";
	if(member_array(p_newrank,list)==-1) return "����û�п�ȱ��";
	return does_he_fit_position(p_newrank);
}
void done_adjust_nation(string id, string pos,string cfm) {
	int p_newrank;
	ret=check_confirm(cfm);
	if(!ret) return;
	init_me();
	ret=am_i_king();
	if(stringp(ret)) {	show_invalid_check(); return;}

	feed_target(id);
	ret=is_he_our_nation(); 
	if(stringp(ret)) { show_invalid_check(); return;} 
	ret=is_he_not_king(); 
	if(stringp(ret)) { show_invalid_check(); return;} 

	ret=am_i_busy();
	if(stringp(ret)) { show_invalid_check(); return;} 
	ret=is_he_busy();
	if(stringp(ret)) { show_invalid_check(); return;} 

	p_newrank=to_int(pos);
	ret=is_he_fit_nation_position(p_newrank);
	if(stringp(ret)) { show_invalid_check(); return;} 

	if(p_newrank!=-1)
		(EV_POSITION)->give_position_n(t_id,p_newrank,p_nation);
	else {
		CHAR_D->set_char(t_id,"ranknation",0);
	      CHANNEL_D->deliver_tell("rumor","system",
         sprintf("%s�������%s%s��ְ��",t_name,
               COUNTRY_D->get_country(p_nation,"name"),
		OFFICER_D->query_rank_name(t_ranknation)));      
	}
}

void which_nation_pos(string id,string pos) {
	get_input_then_call
     ((: done_adjust_nation, id,pos:), "ȷ����[y/n]��");
}
void do_adjust_nation(string id) {
	int *list;
	int i;

	init_me();
	ret=am_i_king();
	if(stringp(ret)) { show_invalid_check(); return;} 

	list=(EV_POSITION)->get_nation_vacancy(p_nation);
	printf("  ����      ��ְ\n");
	for(i=0;i<sizeof(list);++i)
	{	printf("��%4d��    %s\n",list[i],
			OFFICER_D->query_rank_name(list[i]));
	}
	printf("��%4d��    %s\n",-1,"ȡ�����ҹ�ְ");

	get_input_then_call
     ((: which_nation_pos, id:), "����Ϊ��ְ��");	
}


/////////////////////// ��פ��Ա /////////////////////////////////

int can_zm_do(string p_where) {
	string zhou,zhouhd;
	zhou=AREA_D->get_area(t_area,"zhou");
	if(AREA_D->get_area(p_where,"zhou")!=zhou) return 0; // can't
	zhouhd=AREA_D->get_zhou_head(zhou);
	if(AREA_D->get_area(zhouhd,"nation")!=p_nation) return 0; // can't
	if(AREA_D->get_area(zhouhd,"zm")!=p_id) return 0;
	return 1;
}
void done_move_officer(string id,string p_where,string cfm ) {
	ret=check_confirm(cfm);
	if(!ret) return;
	init_me();

	feed_target(id);

	ret=can_zm_do(p_where);
	if(ret!=1) {
		ret=am_i_king();
		if (!ret)   //�ǹ�ʦ
		   {if (!is_under_guoshi_control(p_where))
		       ret = "���޷����ɹ�Ա����������ϵ���յĵ���!";
		    if (!is_under_guoshi_control(CHAR_D->get_char(id,"area")))
		       ret = "���޷��Ѳ�������ϵ���յĵ����Ĺ�Ա����!";
		   }
		if(stringp(ret)) {	show_invalid_check(); return;}
	}


	ret=is_he_our_nation();
	if(stringp(ret)) { show_invalid_check(); return;} 

	ret=am_i_busy();
	if(stringp(ret)) { show_invalid_check(); return;} 

	ret=is_he_busy();
	if(stringp(ret)) { show_invalid_check(); return;} 
	
	if(AREA_D->get_area(p_where,"nation")!=p_nation) {
		ret="���ﲻ�Ǳ���Ͻ����"; show_invalid_check(); return;
	}
	if(t_area==p_where) {
		ret=t_name+"�Ѿ��������ˡ�"; show_invalid_check(); return;
	}

	if(t_id==p_nation) {
		ret="���������ҵ�����"; show_invalid_check(); return;
	}

	CHAR_D->set_char(t_id, "area", p_where);
	CHAR_D->set_char(t_id,"ranklocal",R_SG);

	dis=sprintf("%s��%s�ɵ�%s��",
		p_name,t_name,AREA_D->get_area(p_where,"name"));
	CHANNEL_D->deliver_tell("rumor","system",dis);
}

void move_to_where(string id , string where) {
	get_input_then_call
     ((: done_move_officer, id,where:), "ȷ����[y/n]");	
}
void do_move_officer(string str) {
	get_input_then_call
     ((: move_to_where, str:), "�ɵ����");	
}

//////////////////////// assign localleader /////////////////////////////////////
int can_zm_doa() {
	string zhou,zhouhd;
	zhou=AREA_D->get_area(t_area,"zhou");
	zhouhd=AREA_D->get_zhou_head(zhou);
	if(AREA_D->get_area(zhouhd,"nation")!=p_nation) return 0; // can't
	if(AREA_D->get_area(zhouhd,"zm")!=p_id) return 0;
	return 1;
}

void done_localleader(string id,string cfm) {
	string old_leader;
	int title;
	ret=check_confirm(cfm);
	if(!ret) return;
	init_me();
	feed_target(id);

	ret=can_zm_doa();
	if(ret!=1) {
		ret=am_i_king();
		if (!ret)   //�ǹ�ʦ
		   {
		    if (!is_under_guoshi_control(CHAR_D->get_char(id,"area")))
		       ret = "�㲻���ڲ�������ϵ���յĵ�������̫��!";
		   }
		if(stringp(ret)) {	show_invalid_check(); return;}
	}
	else
	{
	if (!is_under_guoshi_control(CHAR_D->get_char(id,"area")))
		       ret = "�㲻���ڲ�������ϵ���յĵ�������̫��!";
        if(stringp(ret)) {show_invalid_check(); return;}
	}


	ret=is_he_our_nation();
	if(stringp(ret)) { show_invalid_check(); return;} 

	ret=am_i_busy();
	if(stringp(ret)) { show_invalid_check(); return;} 

	ret=is_he_busy();
	if(stringp(ret)) { show_invalid_check(); return;} 
	
	old_leader=AREA_D->get_area(t_area,"leader");
	title=OFFICER_D->query_area_officer_title(AREA_D->get_area(t_area,"level"),0,0)[0];
	ret=does_he_fit_position(title);
	if(stringp(ret)) { show_invalid_check(); return;} 

	if(stringp(old_leader)) {
		CHAR_D->set_char(old_leader,"ranklocal",R_SG);
		CHAR_D->set_char(old_leader,"grant",0);
	}
	CHAR_D->set_char(t_id,"ranklocal",title);
	CHAR_D->set_char(t_id,"grant",0);
	CHAR_D->set_char(t_id,"fealty",CHAR_D->get_char(p_id,"fealty"));

	dis=sprintf("%s��%sΪ%s��%s��",
		p_name,t_name,AREA_D->get_area(t_area,"name"),
		OFFICER_D->query_rank_name(title));
	CHANNEL_D->deliver_tell("rumor","system",dis);

}

void do_localleader(string str) {
	get_input_then_call
     ((: done_localleader, str:), "ȷ����[y/n]");	
}
//////////////////////// change captal city ////////////////////////////////////
void done_move_me(string p_where,string cfm) {
	ret=check_confirm(cfm);
	if(!ret) return;
	init_me();
	ret=am_i_king();
	if (!ret)   //�ǹ�ʦ
	   ret = "����������Ҫ�͹�������,��һ��������������!";
	if(stringp(ret)) {	show_invalid_check(); return;}

	ret=am_i_busy();
	if(stringp(ret)) { show_invalid_check(); return;} 

	if(AREA_D->get_area(p_where,"nation")!=p_nation) {
		ret="���ﲻ�Ǳ���Ͻ����"; show_invalid_check(); return;
	}
	p_area=CHAR_D->get_char(p_nation,"area");
	if(p_area==p_where) {
		ret="�׶��Ѿ��������ˡ�"; show_invalid_check(); return;
	}

	if((p_id!=p_nation)&&(AREA_D->get_area(p_where,"population")<
		AREA_D->get_area(p_area,"population"))) {
		ret="��ô�ܰ��׸�Ǩ�Ƶ�һ���˿�ϡ�ٵĵط���"; show_invalid_check(); return;
	}
	if(COUNTRY_D->get_country(p_nation,"gold")<100) {
		ret="����𲻹��ˡ�"; show_invalid_check(); return;
	}
	COUNTRY_D->set_country(p_nation,"gold",
		COUNTRY_D->get_country(p_nation,"gold")-100);
	CHAR_D->set_char(p_nation, "area", p_where);
	CHAR_D->set_char(p_nation,"ranklocal",R_SG);

	dis=sprintf("%s���׶�Ǩ�Ƶ�%s��",
		COUNTRY_D->get_country(p_nation,"name"),
		AREA_D->get_area(p_where,"name"));
	CHANNEL_D->deliver_tell("rumor","system",dis);

}
void do_move_me(string str) {
	get_input_then_call
     ((: done_move_me, str:), "ȷ����[y/n]");	
}
/////////////////////////���ù��� //////////////////////////////////////////////
mixed is_right_name(string nam) {
	if((sizeof(nam)<2)||(sizeof(nam)>6))
		return "����������һ���������֡�";
	return 1;
}
void done_name(string nam,string cfm) {
	ret=check_confirm(cfm);
	if(!ret) return;
	init_me();
	ret=am_i_king();
	if (!ret)   //�ǹ�ʦ
	   ret = "����������Ҫ�͹�������,��һ��������������!";
	if(stringp(ret)) { show_invalid_check(); return;} 
	ret=is_right_name(nam);
	if(stringp(ret)) { show_invalid_check(); return;} 
	if(nam[<2..<1]!="��")
		nam+="��";
	dis=p_name+"���������Ϊ��"+nam;

	CHANNEL_D->deliver_tell("rumor","system",dis);
	COUNTRY_D->set_country(p_nation,"name",nam);
	return;
}
void do_name(string str) {
	get_input_then_call
     ((: done_name, str:), "ȷ�ϴ�����[y/n]");	
}
/////////////////// for black name list ////////////////////////////
mixed can_he_on_bn(int tm) {	
	mixed bn;
	if(!t_name)
	{
	bn=AREA_D->get_area(p_area,"bn");
	if(!sizeof(bn)) bn=([]);
	map_delete(bn,t_id);
	return "û��"+t_id+"�����ɫ��";
	}
	if((EV_MERCHANT)->get_market("area")==p_area)
		return "�������ھٰ켯�У�����ʹ�ú�������\n";
	if((t_nation==p_nation)&&(tm>0)) return t_name+"�Ǳ�����Ա��";
	return 1;
}

void done_add_list(string id,string tm,string cfm) {
	mixed bn;
	int p_tm;
	ret=check_confirm(cfm);
	if(!ret) return;
	init_me();
	ret=am_i_local_leader();

	if(stringp(ret)) {show_invalid_check(); return;}

	feed_target(id);

	if(stringp(ret)) { show_invalid_check(); return;} 

	p_tm=to_int(tm);
	if(p_tm<0)p_tm=0;
	if(p_tm>72) {
		ret="ʱ�䳬����Χ�ˡ�\n";show_invalid_check();return;
	}
	ret=can_he_on_bn(p_tm);

	if(stringp(ret)) { show_invalid_check(); return;} 

	ret=am_i_busy();
	if(stringp(ret)) { show_invalid_check(); return;} 

//	ret=is_he_busy();
//	if(stringp(ret)) { show_invalid_check(); return;} 
	
	AREA_D->clear_bn(p_area);
	bn=AREA_D->get_area(p_area,"bn");
	if(!sizeof(bn)) bn=([]);
	if(p_tm==0) {
		map_delete(bn,t_id);
		dis=sprintf("%s��%s��%s�ĵ����������й����ˡ�\n"
			,p_name,t_name,AREA_D->get_area(p_area,"name"));
	}
	else
	{
		if(sizeof(bn)>4) {
			ret="���ֻ���������ڵ����������ϡ�\n";
			show_invalid_check();
			return;
		} else
		{
			bn[t_id]=time()+p_tm*3600;
			dis=sprintf("%s��%s������д���������������ֹ�����%s��\n"
			,p_name,t_name,AREA_D->get_area(p_area,"name"));
		}

	}
//	CHANNEL_D->deliver_tell("rumor","system",dis);
	AREA_D->set_area(p_area,"bn",bn);
	write("�ɹ���\n");
	return;
}

void time_add_list(string id,string str) {
     get_input_then_call
     ((: done_add_list, id,str:), "ȷ����[y/n]����������ؿ��ǡ�\n");	

    return;
}
void do_add_list(string str) {
     get_input_then_call
     ((: time_add_list, str:), "���ö���Сʱ[0-72]\n");	
}
/////////////////////////////���ò��Զ�¼�� ///////////////////////////////////
void done_set_no_auto_pos(string tm,string cfm) {
	int p_tm;
	ret=check_confirm(cfm);
	if(!ret) return;
	init_me();
	ret=am_i_local_leader();
	if(stringp(ret)) { show_invalid_check(); return;} 
	p_tm=to_int(tm);
	if((p_tm<0)||(p_tm>(120))) 
	{	ret="ʱ�䲻����\n"; show_invalid_check(); return;} 
	p_tm=p_tm*3600;
	if(!p_tm) 
		CHAR_D->set_char(p_id,"no_pos",0);
	else
		CHAR_D->set_char(p_id,"no_pos",time()+p_tm);
	write("�ɹ���\n");
}
void do_set_no_auto_pos(string str) {
	get_input_then_call
     ((: done_set_no_auto_pos, str:), "ȷ����[y/n]");	
}

void done_emperor(string str) {

}

///////////// ��ְ /////////////////////////////////////////////////////
void done_cancelofficer(string id,string cfm) {
	ret=check_confirm(cfm);
	if(!ret) return;
	init_me();
	ret=am_i_king();
	if (!ret)   //�ǹ�ʦ
           {
	   if (!is_under_guoshi_control(CHAR_D->get_char(id,"area")))
	       ret = "���޷��ӳ����������յĵ����Ĺ�Աְ��!";
	   }
	if(stringp(ret)) {	show_invalid_check(); return;}

	feed_target(id);

	ret=is_he_our_nation();
	if(stringp(ret)) { show_invalid_check(); return;} 

	
	if(t_id==p_nation) {ret="�����췴��"; show_invalid_check(); return;} 


	ret=am_i_busy();
	if(stringp(ret)) { show_invalid_check(); return;} 

	ret=is_he_busy();
	if(stringp(ret)) { show_invalid_check(); return;} 
	
	CHAR_D->set_char(t_id,"loyalty",1); // cut to 1 can't be zero
	CHAR_D->set_char(t_id,"reputation",CHAR_D->get_char(t_id,"reputation")/2);
	
	CHAR_D->set_char(t_id,"ranklocal",0);
	CHAR_D->set_char(t_id,"nation",0);
	CHAR_D->set_char(t_id,"ranknation",0);
	
	CHAR_D->set_char(t_id,"nc",0);
	CHAR_D->set_char(t_id,"ps",0);

	dis=sprintf("%s�����%s��%s��һ��ְ��",
		p_name,t_name,COUNTRY_D->get_country(p_nation,"name"));
	CHANNEL_D->deliver_tell("rumor","system",dis);

	dis=sprintf("%s���������%s��һ��ְ��\n",
		p_name,	COUNTRY_D->get_country(p_nation,"name"));

	tell_user(t_id,"%^H_RED%^"+dis+"%^RESET%^");

	dis=sprintf("%s����������%s�Ĺ�ϵ�½��ˡ�",
		t_name,	COUNTRY_D->get_country(p_nation,"name"));
	CHANNEL_D->deliver_tell("rumor","system",dis);
}

void do_cancelofficer(string str) {
	get_input_then_call
     ((: done_cancelofficer, str:), "ȷ����[y/n]");	
}

///////////////////�趨����//////////////////////////////////////
mixed can_he_be_zm(string zhou) {
	string zhouhd;

	zhouhd=AREA_D->get_zhou_head(zhou);
	if(AREA_D->get_area(zhouhd,"nation")!=t_nation) 
		return zhou+"�׸�����������С�";
	if(!CHAR_D->get_char(t_id,"ranknation"))
		return "ֻҪ���ҹ�Ա�ſ��Գ�Ϊ������";
	return 1;
}


void done_set_zm(string id,string cfm) {
	string zhou;
	string zhouhd;
	ret=check_confirm(cfm);
	if(!ret) return;
	init_me();
	ret=am_i_king();
	if(stringp(ret)) {	show_invalid_check(); return;}

	feed_target(id);

	ret=is_he_our_nation();
	if(stringp(ret)) { show_invalid_check(); return;} 

	
	ret=am_i_busy();
	if(stringp(ret)) { show_invalid_check(); return;} 

	ret=is_he_busy();
	if(stringp(ret)) { show_invalid_check(); return;} 

	zhou=AREA_D->get_area(t_area,"zhou");
	ret=can_he_be_zm(zhou);
	if(stringp(ret)) { show_invalid_check(); return;} 

	zhouhd=AREA_D->get_zhou_head(zhou);
	AREA_D->set_area(zhouhd,"zm",t_id);	

	dis=sprintf("%s����%sΪ%s��������",
		p_name,t_name,zhou);
	CHANNEL_D->deliver_tell("rumor","system",dis);

	dis=sprintf("%s������Ϊ%s��������",
		p_name,	zhou);

	tell_user(t_id,"%^H_GREEN%^"+dis+"%^RESET%^");

}

void do_set_zm(string str) {
	get_input_then_call
     ((: done_set_zm, str:), "ȷ����[y/n]");	
}

///////////////////////// ���� //////////////////////////////////////////////
mixed handover() {
	string *chr;
	object o;

	int money;
	o=find_body(p_id);
	if(!objectp(o)) return;
	money=MONEY_D->get_all_money(o);
	MONEY_D->sub_all_money(o,money);
	MONEY_D->add_poket_money(o,10000);

	COUNTRY_D->trans_country(p_id,t_id);
	chr=CHAR_D->check_char("nation",p_nation);
	foreach(string c in chr) {
		CHAR_D->set_char(c,"nation",t_id);
		CHAR_D->set_char(c,"ps",0);
	}
	chr=AREA_D->check_area("nation",p_nation);
	foreach(string c in chr) {
		AREA_D->set_area(c,"nation",t_id);
	        "/sgdomain/menu/buzzer"->room_update(
        	  AREA_D->get_area(c,"path")+
          		AREA_D->get_area(c,"meeting"));

	}
	CHAR_D->set_char(t_id,"ranknation",R_KING);
	CHAR_D->remove_char(p_id);	

}
mixed can_i_handover() {
	if(p_id!=p_nation) return "ֻ����������������λ��";
        return 1;
}
mixed can_he_be_king() {
	if(!CHAR_D->get_char(t_id,"ranknation"))
		return "ֻҪ���ҹ�Ա�ſ��Խ��չ���֮λ��";
	if(t_id==p_id) 
		return "��λ�����Լ���";
	return 1;
}
mixed any_body_busy() {
	string *chr;
	chr=CHAR_D->check_char("nation",p_nation);
	foreach(string c in chr) {
		if(CHAR_D->get_char(c,"task")) 
			return "������"+CHAR_D->get_char(c,"name")+"����ִ������";
	}
	return 1;
}
void done_handover(string id,string cfm) {
	ret=check_confirm(cfm);
	if(!ret) return;
	init_me();

	ret=can_i_handover();
	if(stringp(ret)) { show_invalid_check(); return;} 

	feed_target(id);

	ret=is_he_our_nation();
	if(stringp(ret)) { show_invalid_check(); return;} 

	ret=can_he_be_king();
	if(stringp(ret)) { show_invalid_check(); return;} 

	ret=any_body_busy();
	if(stringp(ret)) { show_invalid_check(); return;} 

	handover();

	return;
}
void do_handover(string str) {
	get_input_then_call
     ((: done_handover, str:), "ȷ��������[y/n]���ó���Ҫ�������ˡ�");	
}

///////////////////////// �������� /////////////////////////////////////////////
mixed can_give_price(string what) {
	object o_t;
	int nb,prise;
	int w;
	o_t=find_body(t_id);
	if(!objectp(o_t)) return t_name+"Ŀǰû�����ߡ�";
	nb=CHAR_D->get_char(t_id,"nationcontribution");
	prise=CHAR_D->get_char(t_id,"ps");
	if((nb-prise)<100) return t_name+"Ŀǰ���Ͳ��������ܽ�����";
	w=to_int(what);
	if((w>6)||(w<1)) return "û�����ֽ�����";
	if((w==1)&&(COUNTRY_D->get_country(p_nation,"gold")<1000))
		return "Ŀǰ������飬û��������Ǯ��";
	return 1;
}

void done_price(string id,string what,string cfm) {
	int w,r,p,bas,hon;
	string st;
	object ot;
	ret=check_confirm(cfm);
	if(!ret) return;
	init_me();

	feed_target(id);

	ret=is_he_our_nation();
	if(stringp(ret)) { show_invalid_check(); return;} 

	ret=can_give_price(what);
	if(stringp(ret)) { show_invalid_check(); return;} 

	w=to_int(what);

	bas=CHAR_D->get_char(t_id,"nationcontribution")-
		CHAR_D->get_char(t_id,"ps");
	
	ot=find_body(t_id);
	CHAR_D->set_char(t_id,"ps",CHAR_D->get_char(t_id,"ps")+bas);
	r=bas/2;
	hon=COUNTRY_D->get_country(p_nation,"hon");
	COUNTRY_D->set_country(p_nation,"hon",hon+(bas-r));
	switch(w) {
		case 1: // gold
			p=r/5;
			st="���ƽ�";
			MONEY_D->add_salary_money(ot,p*10000);
			COUNTRY_D->set_country(p_nation,"gold",
				COUNTRY_D->get_country(p_nation,"gold")-p);
			break;
		case 2: // reputation
			p=r*2;
			st="������";
			CHAR_D->set_char(t_id,"reputation",
				CHAR_D->get_char(t_id,"reputation")+p);
			break;
		case 3: // loyalty
			p=r/5;
			st="���ҳ϶�";
			CHAR_D->set_char(t_id,"loyalty",
                                CHAR_D->get_char(t_id,"loyalty")+p);
			break;
		case 4: // wuli
			p=r;
			st="����ѧ����";
			ot->award_exp(p,"sk_wuli");
			break;
		case 5: // meili
			p=r;
			st="���ι�����";
			ot->award_exp(p,"sk_meili");
			break;
		case 6: // zhimou
			p=r;
			st="���������";
			ot->award_exp(p,"sk_zhimou");
			break;
	}


	dis=sprintf("%s�Ϳ๦�ߣ����ش˼ν�%s%s%s��",
		t_name,(ot->query_gender()==1 ? "��":" ��" ),
		chinese_number(p),st);
	CHANNEL_D->deliver_tell("gossip",p_name,dis);
	CHANNEL_D->deliver_tell("gossip",t_name,"л�����ʹ͡�");


}
void price_what(string id,string what) {
	get_input_then_call
     ((: done_price, id,what:), "ȷ�Ͻ�����[y/n]��");	
}
void do_price(string id) {

	init_me();
	ret=am_i_king();
	if(stringp(ret)) { show_invalid_check(); return;} 

	printf("��1��     ��Ǯ\n");
	printf("��2��     ����\n");
	printf("��3��     �ҳ�\n");
	printf("��4�� ��ѧ����\n");
	printf("��5�� �ι�����\n");
	printf("��6�� ��������\n");
	get_input_then_call
     ((: price_what, id:), "����ʲô��");	
}



//////////////////////////////���ҽ���///////////////////////////////////////
mixed can_country_price() {
	int p_year=DAY_D->query_date()[3];
	int hon=COUNTRY_D->get_country(p_nation,"hon");
	if(p_year==COUNTRY_D->get_country(p_nation,"hon_year"))
		return "�����Ѿ��������ˡ�\n";
	if(hon<1000) 
		return "�ܽ��㲻��һǧ��̫���ˡ�";
	return 1;
}
mixed done_country_pricea(string list) {
	string *tmp;
	string post_string;
	int num,i,p_year;
	int cp_hon,hon;
	mapping cp_ids=([]);
	tmp=explode(list,",");
	num=sizeof(tmp);

	if((num<1)||(num>5)) {
		return "����������һ�����ˡ�\n"; 
	}
	cp_hon=0;
	for(i=0;i<num;++i) {
		string *kk;
		string cp_id;
		int cp_val;
		kk=explode(tmp[i]," ");
		if(sizeof(kk)!=2) 
			return ""+tmp[i]+"�����ʽ���ԡ�\n";
		cp_id=kk[0];
		cp_val=to_int(kk[1]);
		if(cp_val<10) return "ÿλ��Ա����Ҫ����10�㡣\n";
		if(CHAR_D->get_char(cp_id,"nation")!=p_nation)
			return ""+cp_id+"���Ǳ�����Ա��\n";
		cp_hon+=cp_val;
		cp_ids[cp_id]=cp_val;
	}
	hon=COUNTRY_D->get_country(p_nation,"hon");
	if(hon<cp_hon)
		return "û����ô�ཱ�㡣\n";
	COUNTRY_D->set_country(p_nation,"hon",hon-cp_hon);

	p_year=DAY_D->query_date()[3];
	COUNTRY_D->set_country(p_nation,"hon",hon-cp_hon);
	COUNTRY_D->set_country(p_nation,"hon_year",p_year);
	post_string=chinese_number(p_year)+"���ر�����\n";
	foreach(string cp_id,int cp_val in cp_ids) {
CHAR_D->add_honor_point(cp_id,cp_val);
		post_string+=sprintf("%8s�� %d��\n",
			CHAR_D->get_char(cp_id,"name"),cp_val);
	}
	NEWS_D->system_post("nation."+p_nation,chinese_number(p_year)+"���ر���", 
		post_string,  p_name+"("+p_id+")");
	return 1;
}
void done_country_price(string list,string cfm) {
	ret=check_confirm(cfm);
	if(!ret) return;
	ret=done_country_pricea( list);
	if(stringp(ret)) { show_invalid_check(); return;} 

    CHANNEL_D->deliver_tell("rumor","system",COUNTRY_D->get_country(p_nation,
		"name")+"�Ա������й�֮���ɷ��ر��͡�");
	return;

}

void country_price_what(string list) {
	get_input_then_call
     ((: done_country_price, list:), "ȷ�Ͻ�����[y/n]��");	

}

void do_country_price() {
	int hon;
	init_me();
	ret=am_i_king();
	if(stringp(ret)) { show_invalid_check(); return;} 

	hon=COUNTRY_D->get_country(p_nation,"hon");
	printf("Ŀǰ���н��㣺%d\n",hon);

	ret=can_country_price();
	if(stringp(ret)) { show_invalid_check(); return;} 

	printf("���Խ����������������ı�����Ա�������취�������ԱID���ո�ӵ�����\n");
	printf("��Ա֮���ö��ŷֿ�������Ҫ��cdd��rob����200�㣬noise����300�㣬�����룺\n");
	printf("cdd 200,rob 200,noise 300\n");

	get_input_then_call
     ((: country_price_what:), "�����Ĺ�Ա�͵�����");	
}

//////////////////////////////����������������/////////////////////////////////////
mixed is_he_fit_base_leader(string f_id) {
	string *list;
	object cont;
	mixed ret;
	list=AREA_D->get_area(p_area,"base");
	if(!sizeof(list)) list=({});
	if(member_array(f_id,list)==-1) return "����û������������ء�";
	cont=SGBASE(p_area,f_id);
	if(!objectp(cont)) {
		return "û��������أ���֣�";
	}
	ret=cont->set_leader(t_id);
	return ret;
}
void done_adjust_base_leader(string id, string f_id,string cfm) {
	int p_newrank;
	string dis;
	ret=check_confirm(cfm);
	if(!ret) return;
	init_me();
	ret=am_i_local_leader();
	if(stringp(ret)) {	show_invalid_check(); return;}
	feed_target(id);
	ret=is_he_local_officera(); // sure he is local not localofficer but a nation officer
	if(stringp(ret)) { show_invalid_check(); return;} 
	ret=am_i_busy();
	if(stringp(ret)) { show_invalid_check(); return;} 
	ret=is_he_busy();
	if(stringp(ret)) { show_invalid_check(); return;} 

	ret=is_he_fit_base_leader(f_id);
	if(stringp(ret)) { show_invalid_check(); return;} 
	dis=p_name+"����"+t_name+"Ϊ"+AREA_D->get_area(p_area,"name")+
		"��"+BASE_D->get_base(f_id,"name")+"�ܼࡣ";
	CHANNEL_D->deliver_tell("rumor","system",dis);
}

void which_base(string id,string f_id) {
	get_input_then_call
     ((: done_adjust_base_leader, id,f_id:), "ȷ����[y/n]��");
}
void do_adjust_base_leader(string id) {
	array bases;
	int i;
	init_me();
	ret=am_i_local_leader();
	if(stringp(ret)) { show_invalid_check(); return;} 
	bases=AREA_D->get_area(p_area,"base");
	if(!sizeof(bases)) {
		ret="��������û���κ��������ء�";
		show_invalid_check();
		return;
	}

	printf("����ID      ��������    \n");
	for(i=0;i<sizeof(bases);++i)

	{
		printf("%-12s%s\n",bases[i],
			BASE_D->get_base(bases[i],"name"));
	}

	get_input_then_call
     ((: which_base, id:), "���������������أ�");
}

//////////////////send merchant/////////////////////////////////
void sent_watch_goods(string goods) {
	printf("���ڻ������ԣ�ʲôʱ����ԣ��뿴��ʦͨ�档\n");
	return;
}
void do_send_merchant() {
	printf("һ�����˿���Я��������������Ʒ�����뷽���ǻ���ID����������Ǯ�����磺\n");
	printf("��Ҫ����Я��500��ʳ��ÿ��λ�ۼ�10�����Ӻ�20Ƥ��,ÿ��λ�ۼ�1���ƽ������룺\n");
	printf("food,50,10,leather,20,100\n");
	printf("ע���Ǯһ���԰���Ϊ��λ��\n");

	get_input_then_call
     ((: sent_watch_goods :), "����Я��ʲô��Ʒ��");	

}

//////////////////////////��ļ��Ա/////////////////////////////////
// this part is created by group, modified by fire in May 2000
mixed can_recruit_soldier(int sold) {
	int safe,population,soldiers;
	int c_population,c_soldiers;
	array p_date;
	int p_month,p_year,a_year,a_month;
	safe = AREA_D->get_area(p_area,"safe");
	population = AREA_D->get_area(p_area,"population");
	soldiers = AREA_D->get_area(p_area,"soldier");
	p_date = DAY_D->query_date();
	p_month = p_date[2];
	p_year = p_date[3];	
	c_population = COUNTRY_D->get_country(AREA_D->get_area(p_area,"nation"),"population");
	c_soldiers = COUNTRY_D->get_country(AREA_D->get_area(p_area,"nation"),"soldier");
	if(c_soldiers > (c_population/12)) return "��Ա�����˿ڳ���������\n";
	if(population < 10000) return "�˿ڲ��㣬�޷�ļ����\n";
	if(safe <170) return "�������㣬�޷�ļ����\n";
	if(soldiers > (population/12)) return "���б�Ա�����˿ڳ���������\n";
if(AREA_D->get_area(p_area,"gold")< (sold*20)) return "���п��飬�޷�ļ����\n";
if(AREA_D->get_area(p_area,"food")< (sold*20)) return "���п��飬�޷�ļ����\n";	
	if (p_month != 4 && p_month != 10) return "ֻ��ÿ�����º�ʮ�¿���ļ����\n";
	 if(AREA_D->get_area(p_area,"recruit_soldier"))	 
	{	a_year = AREA_D->get_area(p_area,"recruit_soldier")["year"];
		a_month = AREA_D->get_area(p_area,"recruit_soldier")["month"];
	  if(p_year == a_year)
		return "ÿ��ֻ��ļ��һ�Ρ�\n";
	  }
	  return 1;
	
}
void do_recruit_soldier(string cfm)
{
	int safe,population,soldiers;
	array p_date;
	int wl,zhili,meili,li;
	int c_gold,c_food;
	int p_month,p_year;
	int p_soldier;
	string dis;

	ret=check_confirm(cfm);
        if(!ret) return;

    init_me();
    ret= am_i_local_leader();
    if(stringp(ret)) { show_invalid_check(); return;}
	

	safe = AREA_D->get_area(p_area,"safe");
	population = AREA_D->get_area(p_area,"population");

	p_date = DAY_D->query_date();
	p_month = p_date[2];
	p_year = p_date[3];	

	wl = CHAR_D->get_skill(p_id,"sk_wuli");
	zhili = CHAR_D->get_skill(p_id,"sk_zhimou");
	meili = CHAR_D->get_skill(p_id,"sk_meili");
	li = (wl*3 + zhili*2 + meili*5) / 10;

	soldiers = population* li / (8600*3);

	if(soldiers>5000)
	soldiers = 5000; 

	ret=can_recruit_soldier(soldiers);
        if(stringp(ret)) { show_invalid_check(); return;}
	AREA_D->set_area(p_area,"recruit_soldier",(["year":p_year,"month":p_month]));

	safe = safe - 30;
	AREA_D->set_area(p_area,"safe",safe);

	population = population - soldiers * 10;
	AREA_D->set_area(p_area,"population",population);

	c_gold = AREA_D->get_area(p_area,"gold");
	c_gold = c_gold - soldiers*20;
	AREA_D->set_area(p_area,"gold",c_gold);

	c_food = AREA_D->get_area(p_area,"food");	
	c_food = c_food - soldiers*20;
	AREA_D->set_area(p_area,"food",c_food);

	AREA_D->add_soldier(p_area,"footman",soldiers,50,10);

	dis=p_name+"Ϊ"+AREA_D->get_area(p_area,"name")+
                "ļ����Ա"+chinese_number(soldiers)+"�ˡ�";
        CHANNEL_D->deliver_tell("rumor","system",dis);
}	
///////////////////////�Ƶ�//////////////////////////////////
// this part no process yet, later may add some. ////////////


mixed can_i_chengdi() {
	return "/sgdomain/event/ev_chengdi"->can_chengdi( p_nation);
}
void done_chengdi(string cfm) {
	int pop;
	ret=check_confirm(cfm);
	if(!ret) return;

	init_me();

	ret=am_i_king();
	if(stringp(ret)) {	show_invalid_check(); return;}

	ret= can_i_chengdi();
	if(stringp(ret)) { show_invalid_check(); return;} 

	"/sgdomain/event/ev_chengdi"->do_chengdi( p_nation);
	return;

}


void create()
{
    set_privilege(1);
    toplevel = new_menu("\n̫�ع���˵���");
    quit_item = new_menu_item("�˳�", (:quit_menu_application:), "q");
    seperator = new_seperator
    ("-------------------------------------------------------------------------");
    add_menu_item(toplevel, seperator);
    add_menu_item(toplevel, new_menu_item("����̫��֮λ", (: get_input_then_call,
		(: do_give :),"����̫��λ����λ��Ա��" :) ,"1"));

    add_menu_item(toplevel, new_menu_item("�ջ�̫��֮λ",(: get_input_then_call,
		(: done_back :),"ȷ���ջ�̫��֮λ��[y/n]" :) ,"2"));

    add_menu_item(toplevel, new_menu_item("������Ա�ط�ְλ", (: get_input_then_call,
		(: do_adjust_local :),"������λ��Ա�ط�ְλ��" :) ,"3"));

    add_menu_item(toplevel, new_menu_item("���ò��Զ�¼��",	(: get_input_then_call,
		(: do_set_no_auto_pos :),"���ö���Сʱ�ڲ��Զ�¼��[0__120]" :) ,"4"));
    
    add_menu_item(toplevel, new_menu_item("����",	(: get_input_then_call,
		(: done_independence :),"ȷ�϶�����[y/n]" :) ,"5"));

	add_menu_item(toplevel, new_menu_item("������",	(: get_input_then_call,
		(: do_add_list :) ,"��˭�����������":),"6"));

    add_menu_item(toplevel, new_menu_item("�������������ܼ�", (: get_input_then_call,
		(: do_adjust_base_leader :),"������λ��ԱΪ���������ܼࣺ" :) ,"7"));
    
    add_menu_item(toplevel, new_menu_item("��������", 	(: do_send_merchant :),"8"));

   add_menu_item(toplevel, new_menu_item("��ļʿ��", (:get_input_then_call,
		(: do_recruit_soldier :),"ȷ��ļ����[y/n]" :) ,"9"));

    add_menu_item(toplevel, new_seperator("\n"));

    add_menu_item(toplevel, seperator);
    add_menu_item(toplevel, new_seperator("��������˵���"));
    add_menu_item(toplevel, seperator);

	add_menu_item(toplevel, new_menu_item("������Ա����ְλ",	(: get_input_then_call,
		(: do_adjust_nation :) ,"������Ա����ְλ��" :) ,"a"));

    add_menu_item(toplevel, new_menu_item("��פ��Ա", (: get_input_then_call,
		(: do_move_officer :) ,"��פ��λ��Ա��" :) ,"b"));

    add_menu_item(toplevel, new_menu_item("����̫��",(: get_input_then_call,
		(: do_localleader :) ,"������Ϊ��ԱΪ̫�أ�" :) ,"c"));

    add_menu_item(toplevel, new_menu_item("��ְ",(: get_input_then_call,
		(: do_cancelofficer :) ,"������Ϊ��Աְ��" :) ,"d"));

    add_menu_item(toplevel, new_menu_item("Ǩ��",	(: get_input_then_call,
		(: do_move_me :) ,"Ǩ���εأ�" :) ,"e"));

    add_menu_item(toplevel, new_menu_item("�趨����",	(: get_input_then_call,
		(: do_name :),"���������" :) ,"f"));

    add_menu_item(toplevel, new_menu_item("�趨����",	(: get_input_then_call,
		(: do_set_zm :),"�����ɫID��" :) ,"g"));


        add_menu_item(toplevel, new_menu_item("�������",   (: get_input_then_call,
        (: done_getgold :),"����ٽ�" :) ,"h"));

    add_menu_item(toplevel, new_menu_item("��������",	(: get_input_then_call,
		(: do_price :),"�����ɫID��" :) ,"i"));


    add_menu_item(toplevel, new_menu_item("����ر���",	(: do_country_price :),"j"));

    add_menu_item(toplevel, new_menu_item("����",(: get_input_then_call,
		(: do_handover :) ,"��λ����Ϊ��Ա��" :) ,"k"));
    
    add_menu_item(toplevel, new_menu_item("�Ƶ�",	(: get_input_then_call,
		(: done_chengdi :),"ȷ�ϳƵ���[y/n]" :) ,"l"));

   add_menu_item(toplevel, quit_item);
    add_menu_item(toplevel, new_seperator("\n"));

   add_menu_item(toplevel, seperator);
   set_menu_prompt (toplevel, "����ָ��[1-cq]: ");
}

