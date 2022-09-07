// check_result
// check_result.c
void release_army(int p_id);
void war_att_win(int p_id);
void war_def_win(int p_id);


void war_log(int p_id,int r) {
	string msg;
	array a_tmp,a_gen,a_trp;
	mapping m_trp;
	int i;
	string title,aut;
	title=AREA_D->get_area(TASK_D->get_task(p_id,"att_area"),"name")+
		"����"
		+AREA_D->get_area(TASK_D->get_task(p_id,"def_area"),"name");
	aut="ս����"
		+CHAR_D->get_char(TASK_D->get_task(p_id,"att_leader"),"name")+
		"("+TASK_D->get_task(p_id,"att_leader")+")";

	if(r==0) 
		TASK_D->set_task(p_id,"msg_result","��������ط�ʤ����");
	else
		TASK_D->set_task(p_id,"msg_result","�����������ʤ����");
	msg=TASK_D->get_task(p_id,"msg_title");
	msg+="\n��������\n";
	a_tmp=TASK_D->get_task(p_id,"msg_att_party");
	if(sizeof(a_tmp)) {
		for(i=0;i<sizeof(a_tmp);++i) {
			msg+="    ��"+chinese_number(i+1)+"���ţ�\n      ������";
			m_trp=a_tmp[i];
			a_gen=m_trp["generals"];
			foreach(string s in a_gen) {
				msg+=CHAR_D->get_char(s,"name")+" ";
			}
			a_trp=m_trp["troops"]; 
			if(sizeof(a_trp))
			foreach(string t,int n in a_trp) {
				msg+="\n     "+WARAI_D->get_soldier(t,"name")+"��"+
					chinese_number(n);
			}
			msg+="\n";
		
		}
	}
	msg+=TASK_D->get_task(p_id,"msg_total_att_soldiers");


	msg+="\n���ط���\n";
	a_tmp=TASK_D->get_task(p_id,"msg_def_party");
	if(sizeof(a_tmp)) {
		for(i=0;i<sizeof(a_tmp);++i) {
			msg+="    ��"+chinese_number(i+1)+"���ţ�\n      ������";
			m_trp=a_tmp[i];
			a_gen=m_trp["generals"];
			foreach(string s in a_gen) {
				msg+=CHAR_D->get_char(s,"name")+" ";
			}
			a_trp=m_trp["troops"]; 
			if(sizeof(a_trp))
			foreach(string t,int n in a_trp) {
				msg+="\n     "+WARAI_D->get_soldier(t,"name")+"��"+
					chinese_number(n);
			}
			msg+="\n";
		}
	}
	msg+=TASK_D->get_task(p_id,"msg_total_def_soldiers");

	msg+="\nս��������\n";
	msg+=TASK_D->get_task(p_id,"msg_att_left")+"\n";
	msg+=TASK_D->get_task(p_id,"msg_def_left")+"\n";
	msg+=TASK_D->get_task(p_id,"msg_result")+"\n";

        NEWS_D->system_post("war",title, msg,  aut);

	

}
void bandit_def_win(int p_id)
{
        string att_name,def_area;
        string p_dis;
	string def_leader;
        att_name=TASK_D->get_task(p_id,"att_name");
        def_area=TASK_D->get_task(p_id,"def_area");
        def_leader=TASK_D->get_task(p_id,"def_leader");
        p_dis=CHAR_D->get_char(def_leader,"name")+
 "�ʾ�������ս�����ڴ�����"+att_name+"�Ľ�����"+AREA_D->get_area(def_area,"name")+
"����ϲ�칦��\n";
        CHANNEL_D->deliver_tell("rumor","system",p_dis);
       	release_army(p_id);
        TASK_D->remove_task(p_id);
	HIS(CHAR_D->get_char(def_leader,"name")+"�ʾ�������ս�����ڴ�����"+att_name+"�Ľ�����������"+AREA_D->get_area(def_area,"name")+"��");
}
void bandit_att_win(int p_id)
{
        string att_name,def_area;
        string p_dis;
	string def_leader;
	string att_leader;
        att_name=TASK_D->get_task(p_id,"att_name");
        def_area=TASK_D->get_task(p_id,"def_area");
        def_leader=TASK_D->get_task(p_id,"def_leader");
        att_leader=TASK_D->get_task(p_id,"att_leader");
        p_dis=CHAR_D->get_char(def_leader,"name")+
 "ָ�Ӳ�����������ɽ����"+CHAR_D->get_char(att_leader,"name")+
"���Ѫϴ"+AREA_D->get_area(def_area,"name")+"��\n";
        CHANNEL_D->deliver_tell("rumor","system",p_dis);
       	release_army(p_id);
        TASK_D->remove_task(p_id);
	HIS(CHAR_D->get_char(def_leader,"name")+"ָ�Ӳ�����������ɽ����"+CHAR_D->get_char(att_leader,"name")+"���Ѫϴ"+AREA_D->get_area(def_area,"name")+"��");
}
void check_result(int p_id)
{
	string a_leader;
	string def_area,att_area;
	int *pos,*t,*def_army;
	int bandit_attack=0;
	a_leader=TASK_D->get_task(p_id,"att_leader");
	att_area=TASK_D->get_task(p_id,"att_area");
	if(!AREA_D->area_exist(att_area))
		bandit_attack=1;
	if(!CHAR_D->get_char(a_leader,"troop")) {
		if(bandit_attack)
			bandit_def_win(p_id);	
		else
			war_def_win(p_id);
		return;
	}
	if(bandit_attack) // this is a bandit attack
	{
		def_area=TASK_D->get_task(p_id,"def_area");
		pos=MAP_D->get_city(def_area,"center");
		t=MAP_D->get_map_cell(def_area,pos[1],pos[0],"t");
		if(sizeof(t))
		{
			if(TROOP_D->get_troops(t[0],"side")=="a")
			{
				bandit_att_win(p_id);
				return;
			}
		}
	}
	else 
	{
	string def_stage,att_arrange_step;
		def_stage=TASK_D->get_task(p_id,"def_stage");
		def_army=TASK_D->get_task(p_id,"def_army");
		if((!sizeof(def_army))&&(def_stage=="enter_warfield")) {
			war_att_win(p_id);
			return;
		}
		att_arrange_step=TASK_D->get_task(p_id,
			"att_arrange_step");
        if((def_stage=="no leader")&&(att_arrange_step=="over")) {
               war_att_win(p_id);
               return ;
        }

	}
    TASK_D->set_task(p_id,"timaim",2); // 10 sec check
}
void announce_att_win(string def_leader,string att_leader,string def_area) {
	string p_dis;
	string d_name,a_name,a_nation,d_nation;

	d_name=CHAR_D->get_char(def_leader,"name");
	d_nation=CHAR_D->get_char(def_leader,"nation");

	a_name=CHAR_D->get_char(att_leader,"name");
	a_nation=CHAR_D->get_char(att_leader,"nation");

	if(stringp(d_name))
		p_dis=a_name+"�ʾ�������ս����"+d_name+"�ľ���һ�ټ���Ϊ"+
			COUNTRY_D->get_country(a_nation,"name")+
			"������"+AREA_D->get_area(def_area,"name")+"��";
	else
		p_dis=a_name+"ͻ�������Ϊ"+
			COUNTRY_D->get_country(a_nation,"name")+
			"�������޽����ص�"+AREA_D->get_area(def_area,"name")+"��";
	CHANNEL_D->deliver_tell("rumor","system",p_dis);
	HIS(p_dis);

	p_dis=CHAR_D->get_char(a_nation,"name")+"ƥ������ҳǳأ��������Ĳ�������";
	CHANNEL_D->deliver_tell("gossip",CHAR_D->get_char(d_nation,"name"),p_dis);

    if(stringp(d_name))
		p_dis=CHAR_D->get_char(d_nation,"name")+"����������֪���ҵ�������"+
			"Ϊ��������ս��֮�࣬�㻹������齵�ɡ�������������";
	else
		p_dis="˭���㲻�ɽ����أ�֪���ҵ������˰ɡ�������������";
	CHANNEL_D->deliver_tell("gossip",CHAR_D->get_char(a_nation,"name"),p_dis);

	return;
}

void army_res_change(int p_id) {
	int *ts;
	string def_area=TASK_D->get_task(p_id,"def_area");
	ts=TASK_D->get_task(p_id,"att_army");
	if(sizeof(ts)) {
		foreach(int t in ts) {
			TROOP_D->set_troops(t,"source_area",def_area);
		}
	}
}
void random_position(string p_id,string area) {
	CHAR_D->set_char(p_id,"area",area);
	CHAR_D->set_char(p_id,"ranklocal",R_SG);
	return; 
	
}
void war_punish_defence1(string def_area,string att_leader) {
	string d_nation,a_nation;
	int val;
	mixed tmp;
	string *tmp2;

	d_nation=AREA_D->get_area(def_area,"nation");
	a_nation=CHAR_D->get_char(att_leader,"nation");

//    1 �˿��½�һ�롣
	tmp=AREA_D->get_area(def_area,"population");
	tmp/=2;
	AREA_D->set_area(def_area,"population",tmp);
//    2 ��ȫ�½�һ���������30���ٽ���30�� safe=(400-safe)/10
	tmp=AREA_D->get_area(def_area,"safe");
	tmp=(400-tmp)/10;
	AREA_D->set_area(def_area,"safe",tmp);
//    3 ��Ǯ������ٵ�30%��
	AREA_D->set_area(def_area,"gold",
		AREA_D->get_area(def_area,"gold")*3/10);

	AREA_D->set_area(def_area,"nation",a_nation);

//    4 ԭ���ı����㣬���е����ʼ���80%��
	AREA_D->set_area(def_area,"troop",([])); // remove all old troop
	tmp=AREA_D->get_area(def_area,"st");
	if(sizeof(tmp)) {
		tmp2=keys(tmp);
		foreach(string st in tmp2) {
			val=tmp[st]["num"];
			val=val*2/10;
			//tmp[st]["num"]=val;
			if(val==0)
				map_delete(tmp,st);
			else
				tmp[st]["num"]=val;
		}

		AREA_D->set_area(def_area,"st",tmp);

	}

}
void war_punish_defence(string def_area,string att_leader,string d_nation) {
	string a_nation;
	string *d_officers;
	string *d_otherareas;

	tell_user("huaer","����war_punish_defence()��\n");
	a_nation=CHAR_D->get_char(att_leader,"nation");

//    5 ���й�Ա(�������NPC�������)��ʧ5%��������
	d_officers=CHAR_D->check_char("nation",d_nation);
	if(sizeof(d_officers)) {
		foreach(string off in d_officers) {
			int rep,repm;
			rep=CHAR_D->get_char(off,"reputation");
			repm=rep/20; if(repm>1000) repm=1000;
			CHAR_D->set_char(off,"reputation",rep-repm);
		}
	}

	
//  c ��ռ�����Ĺ�Ա��
	d_officers=CHAR_D->check_char_area("nation",d_nation,def_area);
	d_otherareas=AREA_D->check_area("nation",d_nation);
	d_otherareas-=({def_area});
	if(!sizeof(d_otherareas)) // �����ˡ�
	{
		mixed wear;
		COUNTRY_D->remove_country(d_nation);
		CHAR_D->set_char(d_nation,"gold",CHAR_D->get_char(d_nation,"gold")/10);
		CHAR_D->set_char(d_nation,"reputation",CHAR_D->get_char(d_nation,"reputation")/5);
		CHAR_D->set_char(d_nation,"h",0);
		wear=CHAR_D->set_char(d_nation,"wear");
		if(mapp(wear)) {
			map_delete(wear,"torso");
			map_delete(wear,"armors");
			CHAR_D->set_char(d_nation,"wear",wear);

		}
		HIS(COUNTRY_D->get_country(d_nation, "name")+"�����ˣ�������"+CHAR_D->get_char(d_nation, "name")+"���������ˡ�");
		return;
	}
//    1 ��Աת������
// if a npc char and has vancy, will give a position
// if a play char will give no position
	if(sizeof(d_officers)) {
		string t_area;
			t_area=d_otherareas[random(sizeof(d_otherareas))];
		foreach(string of in d_officers) {
			random_position(of,t_area);
		}
	}
//    4 ����й��ҹ�Ա�����׶����ɴ���ԭ��10%�Ľ��������ʡ�
// consider later
	tell_user("huaer","war_punish_defence()ִ������\n");

}

void war_award_attack1(string att_leader,string *att_party,string def_area) {

	tell_user("huaer","����war_award_attack1()\n");
	CHAR_D->set_char(att_leader,"area",def_area);
	CHAR_D->set_char(att_leader,"npcarmy",AREA_D->get_area_soldier(def_area,"footman"));//2001.4.19

	(EV_POSITION)->give_position(att_leader,
		OFFICER_D->query_area_officer_title (
		AREA_D->get_area(def_area,"level"),0,0)[0],def_area);

	att_party-=({att_leader});

	tell_user("huaer",sprintf("att_party = %O\n",att_party));

	while(sizeof(att_party)) {

		(EV_POSITION)->give_position(att_party[0],
			R_SG,def_area);
		att_party-=({att_party[0]});
	}
	tell_user("huaer","war_award_attack1()ִ������\n");
	//return;
}
	

//void war_award_attack(mixed par)
void war_award_attack(string def_area, string att_area, string att_leader, string *att_party)
{
	//string def_area;
	//string att_leader,p_room;
	string p_room;
	mixed chars,rep,obs;
	string a_nation;
	object o,o_room;
	int i;

	tell_user("huaer","����war_award_attack()��\n");

	//def_area=par[0];
	//att_leader=par[2];
	chars=att_party;
	
	a_nation=CHAR_D->get_char(att_leader,"nation");

	p_room=AREA_D->get_area(def_area,"path")+
		AREA_D->get_area(def_area,"meeting");
	if(!sizeof(chars)) chars=({});
	chars-=({att_leader});
	chars+=({att_leader});
	foreach(string d in chars)
		CHAR_D->put_char(d,p_room);
	o=CHAR_D->find_char(att_leader);

	if(objectp(o))
		o->simple_action("$N�������մ�ܵо�����ϲ�ɺأ���λ���н��͡�\n");

	DELAY_D->delay_simple_action(o,"%^H_GREEN%^���ӵ�ʿ�������ˡ�%^RESET%^\n\n",1);
	DELAY_D->delay_simple_action(o,"%^H_WHITE%^$N�ľ��飬���������ˡ�%^RESET%^\n\n",2);
	DELAY_D->delay_simple_action(o,"%^H_BLUE%^���в�ս��ҵľ��飬���������ˡ�%^RESET%^\n\n",3);
	DELAY_D->delay_simple_action(o,"%^H_GREEN%^����"+CHAR_D->get_char(a_nation,"name")
		+"�����������ˡ�%^RESET%^\n\n",4);
	DELAY_D->delay_simple_action(o,"$N����������óԺúȵģ���λ������ðɡ�\n\n",5);
	DELAY_D->delay_simple_action(o,"%^H_BLUE%^���˶����˵�����������%^RESET%^\n\n",6);

	
//    1 ������˧��Ϊռ����̫�ء�
// already
//   2 ������˧������1000��
	CHAR_D->set_char(att_leader,"reputation",
		CHAR_D->get_char(att_leader,"reputation")+1000);
//    3 ������˧���������ȼ���һ������Ϊ����1000
	if(objectp(o))
		if(o->query_link())
//			o->increase_level();
			o->award_exp(1000);

//    4 ���н���(����)������200��
//    5 ��������������500��
	chars-=({att_leader }) ;
	if(sizeof(chars)){
		foreach(string d in chars) {
			o=find_body(d);
			if(!objectp(o)) continue;
			o->award_exp(500);

			rep=CHAR_D->get_char(d,"reputation");
			rep+=200;
			CHAR_D->set_char(d,"reputation",rep);
		}
	}
//    6 ���п�������Щ�������
//    7 ����������������1000��
	CHAR_D->set_char(a_nation,"reputation",
		CHAR_D->get_char(a_nation,"reputation")+1000);
//    8 ����ʿ��ʿ������20�����鲻��
	AREA_D->set_area(def_area,"morale",
		AREA_D->get_area(def_area,"morale")+20);
//	AREA_D->set_area(def_area,"train",
//		AREA_D->get_area(def_area,"train")+20);
// update the room so the board can updated
        AREA_D->set_area(def_area,"nation",a_nation);
        "/sgdomain/menu/buzzer"->room_update(p_room);
        "/sgdomain/menu/buzzer"->room_update(
          AREA_D->get_area(def_area,"path")+
          AREA_D->get_area(def_area,"go"));

	o_room=load_object(p_room);
	if(!objectp(o_room)) return;
	obs=OBJ_D->check_obj("type","food");
	for(i=0;i<2;++i) { // less drink and food
		o=OBJ_D->clone_obj(obs[random(sizeof(obs))]);
		if(!objectp(o)) continue;
		o->move(o_room);
	}
	obs=OBJ_D->check_obj("type","drink");
	for(i=0;i<2;++i) {
		o=OBJ_D->clone_obj(obs[random(sizeof(obs))]);
		if(!objectp(o)) continue;
		o->move(o_room);
	}
}

string war_fresh_body(string *ids) {
	if(sizeof(ids)) {
		foreach(string id in ids)
			CHAR_D->refresh_body(id);
	}

}

void npc_army_back_to_captital(int p_id)//2001.4.13 
{
int sum;
string dis;
string  def_area=TASK_D->get_task(p_id,"def_area");
string  p_nation=AREA_D->get_area(def_area,"nation");
string  captital=CHAR_D->get_char(p_nation,"area");
mapping def_troop_left = TASK_D->get_task(p_id,"def_troop_left");


if (!sizeof(def_troop_left)) return;

foreach (string t in keys(def_troop_left))
  {
   if (t=="commando") continue;
   AREA_D->add_soldier(captital,t,def_troop_left[t],180,180);
   sum +=def_troop_left[t];
  }
if (sum>0)
  {
  dis = COUNTRY_D->get_country(p_nation,"name")+AREA_D->get_area(def_area,"name")+chinese_number(sum)
        +"�б��ܽ��ӻ��׶�"+AREA_D->get_area(captital,"name");
  CHANNEL_D->deliver_tell("rumor","system",dis);
  }

}


void war_att_win(int p_id) {
	string def_area=TASK_D->get_task(p_id,"def_area");
	string att_leader=TASK_D->get_task(p_id,"att_leader");
	string att_area=TASK_D->get_task(p_id,"att_area");
	string def_leader=TASK_D->get_task(p_id,"def_leader");
	string *att_party=TASK_D->get_task(p_id,"att_party");
	string *def_party=TASK_D->get_task(p_id,"def_party");
	string def_nation=AREA_D->get_area(def_area,"nation");
	army_res_change(p_id);
	//2001.4.13
	if (CHAR_D->get_char(def_nation,"type")==TYPE_NPC) //NPC����,δ���������ս���ı��������׶�����
	   if (CHAR_D->get_char(def_nation,"area")!=def_area)  //���Ҳ���NPC�����׶�����ռ
	       npc_army_back_to_captital(p_id);
	//
	war_punish_defence1(def_area, att_leader); // clear def_area first
	release_army(p_id);
	war_log(p_id,1);
       TASK_D->remove_task(p_id);
	("/sgdomain/event/ev_kwar.c")->job_done(att_leader, def_area);

	call_out("announce_att_win",1,def_leader,att_leader,def_area);
	tell_user("huaer","call_out announce_att_win ����\n");

	call_out("war_punish_defence",2,def_area,att_leader,def_nation);
	tell_user("huaer","call_out war_punish_defence ����\n");

	call_out("war_award_attack1",3,att_leader,att_party,def_area);
	tell_user("huaer","call_out war_award_attack1 ����\n");

	//call_out("war_award_attack",6,def_area,att_area,att_leader,att_party); //ԭ�����ӳ�4��
	//tell_user("huaer","call_out war_award_attack ����\n");

	call_out("war_fresh_body",9,att_party);	//ԭ�����ӳ�7��
	call_out("war_fresh_body",10,def_party);	//ԭ�����ӳ�8��
	// for han di's job
	
}

void announce_def_win(string def_leader,string att_leader,string def_area) {
	string p_dis;
	string d_name,a_name;
	d_name=CHAR_D->get_char(def_leader,"name");
	a_name=CHAR_D->get_char(att_leader,"name");
	p_dis=d_name+"�ʾ�������ս����"+a_name+"��ö������ף��Ǳ��Ӵܡ�"
		+AREA_D->get_area(def_area,"name")+"����ϲ�칦��\n";
	HIS(p_dis);
    	CHANNEL_D->deliver_tell("rumor","system",p_dis);
	p_dis=a_name+"ƥ�����ҷ���һ���������������´Σ������������޻أ�";
	CHANNEL_D->deliver_tell("gossip",d_name,p_dis);
	p_dis=d_name+"��������Ҫ��˲����Ҷ�������������ߣ�";
	CHANNEL_D->deliver_tell("gossip",a_name,p_dis);
	return;
}
void war_punish_attack(string *att_party,string a_area){

	string *chars;
	string a_nation;	
	int rep;
// ���в�ս��Ա�����½�10%(��󲻳���1000)��
	if(sizeof(att_party)) {
		foreach(string id in att_party) {
			rep=CHAR_D->get_char(id,"reputation");
			if(rep>10000) rep-=1000;
			else rep=rep*9/10;
			CHAR_D->set_char(id,"reputation",rep);
		
		}
	}
//    2 ����ԭ�ع�Ա�����½�5%(��󲻳���500)��
	a_nation=AREA_D->get_area(a_area,"nation");
	chars=CHAR_D->check_char_area("nation",a_nation,a_area);
	chars-=att_party;
	if(sizeof(chars)) {
		foreach(string id in chars) {
			rep=CHAR_D->get_char(id,"reputation");
			if(rep>10000) rep-=500;
			else rep=rep*95/100;
			CHAR_D->set_char(id,"reputation",rep);
		}
	}

//    3 ����������������5%(��󲻳���1000)��
	rep=CHAR_D->get_char(a_nation,"reputation");
	if(rep>20000) rep-=1000;
	else rep=rep*95/100;
	CHAR_D->set_char(a_nation,"reputation",rep);

//    4 ��ʧ���������ݡ� // this will be later
//    5 �ط������½�30��
	rep=AREA_D->get_area(a_area,"safe");
	rep-=30; if(rep<=0) rep=1;
	AREA_D->set_area(a_area,"safe",rep);
//    6 ����ʿ���½�20��
	rep=AREA_D->get_area(a_area,"morale");
	rep-=20; if(rep<=0) rep=1;
	AREA_D->set_area(a_area,"morale",rep);

}

void war_award_defence(mixed par)
{
	string d_area=par[0];
	string p_leader=par[1];
	string p_room,p_nation;
	string *chars=par[2];
	object o,o_room;
	string *obs;
	int i;
	int rep;

	p_room=AREA_D->get_area(d_area,"path")+
		AREA_D->get_area(d_area,"meeting");
	p_nation=AREA_D->get_area(d_area,"nation");
	if(!sizeof(chars)) chars=({});
	chars-=({p_leader});
	chars+=({p_leader});
	foreach(string d in chars)
		CHAR_D->put_char(d,p_room);
	o=CHAR_D->find_char(p_leader);

	if(objectp(o))
		o->simple_action("$N�������մ�ܵо�����ϲ�ɺء���λ���н��͡�\n");

	DELAY_D->delay_simple_action(o,"%^H_GREEN%^���صİ��������ˡ�%^RESET%^\n\n",1);
	DELAY_D->delay_simple_action(o,"%^H_GREEN%^���ӵ�ʿ�����������ˡ�%^RESET%^\n\n",2);
	DELAY_D->delay_simple_action(o,"%^H_WHITE%^$N�ľ��龭�飬�������������������ˡ�%^RESET%^\n\n",3);
	DELAY_D->delay_simple_action(o,"%^H_BLUE%^���в�ս��ҵľ��飬�������������������ˡ�%^RESET%^\n\n",4);
	DELAY_D->delay_simple_action(o,"$N����������óԺúȵģ���λ������ðɡ�\n\n",5);
	DELAY_D->delay_simple_action(o,"%^H_BLUE%^���˶����˵�����������%^RESET%^\n\n",6);

//    1 �ط�������10��
	rep=AREA_D->get_area(d_area,"safe");
	rep-=10;
	AREA_D->set_area(d_area,"safe",rep);
//    2 ����ʿ����������20�� // no need the morale increase in the arrange stage
//	rep=AREA_D->get_area(d_area,"morale");
//	rep+=20;
//	AREA_D->set_area(d_area,"morale",rep);
//	rep=AREA_D->get_area(d_area,"train");
//	rep+=20;
//	AREA_D->set_area(d_area,"train",rep);

//    3 �ɵò��ֵз������ // not yet

//    4 ��˧����������������1000��
	if(objectp(o))
		if(o->query_link())
			o->award_exp(800);
//    5 ��˧������300��
	rep=CHAR_D->get_char(p_leader,"reputation");
	rep+=300;
	CHAR_D->set_char(p_leader,"reputation",rep);
//    6 ��˧����������10��
	rep=CHAR_D->get_char(p_leader,"localcontribution");
	rep+=10;
	CHAR_D->set_char(p_leader,"localcontribution",rep);

//    7 ̫�غ�������ս������ҵ�һ����˧������
	chars-=({p_leader }) ;
	if(sizeof(chars)){
		foreach(string d in chars) {
			o=find_body(d);
			if(!objectp(o)) continue;
			o->award_exp(500);

			rep=CHAR_D->get_char(d,"reputation");
			rep+=150;
			CHAR_D->set_char(d,"reputation",rep);

			rep=CHAR_D->get_char(d,"localcontribution");
			rep+=5;
			CHAR_D->set_char(d,"localcontribution",rep);
		}
	}
	o_room=load_object(p_room);
	if(!objectp(o_room)) return;
	obs=OBJ_D->check_obj("type","food");
	for(i=0;i<2;++i) {
		o=OBJ_D->clone_obj(obs[random(sizeof(obs))]);
		if(!objectp(o)) continue;
		o->move(o_room);
	}
	obs=OBJ_D->check_obj("type","drink");
	for(i=0;i<2;++i) {
		o=OBJ_D->clone_obj(obs[random(sizeof(obs))]);
		if(!objectp(o)) continue;
		o->move(o_room);
	}

}

void war_def_win(int p_id) {
	string def_area=TASK_D->get_task(p_id,"def_area");
	string def_leader=TASK_D->get_task(p_id,"def_leader");
	string att_area,*att_party,*def_party;
	string att_leader=TASK_D->get_task(p_id,"att_leader");
	att_area=TASK_D->get_task(p_id,"att_area");
	att_party=TASK_D->get_task(p_id,"att_party");
	def_party=TASK_D->get_task(p_id,"def_party");
	release_army(p_id);
	war_log(p_id,0);
	TASK_D->remove_task(p_id);

	call_out("announce_def_win",1,def_leader,att_leader,def_area);

	call_out("war_punish_attack",2,att_party,att_area);
	//call_out("war_award_defence",1,({def_area,def_leader,def_party}));
}