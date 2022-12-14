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
		"进攻"
		+AREA_D->get_area(TASK_D->get_task(p_id,"def_area"),"name");
	aut="战犯："
		+CHAR_D->get_char(TASK_D->get_task(p_id,"att_leader"),"name")+
		"("+TASK_D->get_task(p_id,"att_leader")+")";

	if(r==0) 
		TASK_D->set_task(p_id,"msg_result","结果：防守方胜利。");
	else
		TASK_D->set_task(p_id,"msg_result","结果：进攻方胜利。");
	msg=TASK_D->get_task(p_id,"msg_title");
	msg+="\n进攻方：\n";
	a_tmp=TASK_D->get_task(p_id,"msg_att_party");
	if(sizeof(a_tmp)) {
		for(i=0;i<sizeof(a_tmp);++i) {
			msg+="    第"+chinese_number(i+1)+"军团：\n      将军：";
			m_trp=a_tmp[i];
			a_gen=m_trp["generals"];
			foreach(string s in a_gen) {
				msg+=CHAR_D->get_char(s,"name")+" ";
			}
			a_trp=m_trp["troops"]; 
			if(sizeof(a_trp))
			foreach(string t,int n in a_trp) {
				msg+="\n     "+WARAI_D->get_soldier(t,"name")+"："+
					chinese_number(n);
			}
			msg+="\n";
		
		}
	}
	msg+=TASK_D->get_task(p_id,"msg_total_att_soldiers");


	msg+="\n防守方：\n";
	a_tmp=TASK_D->get_task(p_id,"msg_def_party");
	if(sizeof(a_tmp)) {
		for(i=0;i<sizeof(a_tmp);++i) {
			msg+="    第"+chinese_number(i+1)+"军团：\n      将军：";
			m_trp=a_tmp[i];
			a_gen=m_trp["generals"];
			foreach(string s in a_gen) {
				msg+=CHAR_D->get_char(s,"name")+" ";
			}
			a_trp=m_trp["troops"]; 
			if(sizeof(a_trp))
			foreach(string t,int n in a_trp) {
				msg+="\n     "+WARAI_D->get_soldier(t,"name")+"："+
					chinese_number(n);
			}
			msg+="\n";
		}
	}
	msg+=TASK_D->get_task(p_id,"msg_total_def_soldiers");

	msg+="\n战争结束：\n";
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
 "率军奋勇征战，终于打退了"+att_name+"的进攻，"+AREA_D->get_area(def_area,"name")+
"军民欢喜庆功！\n";
        CHANNEL_D->deliver_tell("rumor","system",p_dis);
       	release_army(p_id);
        TASK_D->remove_task(p_id);
	HIS(CHAR_D->get_char(def_leader,"name")+"率军奋勇征战，终于打退了"+att_name+"的进攻，保卫了"+AREA_D->get_area(def_area,"name")+"。");
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
 "指挥不力，兵败如山倒，"+CHAR_D->get_char(att_leader,"name")+
"领兵血洗"+AREA_D->get_area(def_area,"name")+"！\n";
        CHANNEL_D->deliver_tell("rumor","system",p_dis);
       	release_army(p_id);
        TASK_D->remove_task(p_id);
	HIS(CHAR_D->get_char(def_leader,"name")+"指挥不力，兵败如山倒，"+CHAR_D->get_char(att_leader,"name")+"领兵血洗"+AREA_D->get_area(def_area,"name")+"！");
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
		p_dis=a_name+"率军奋勇征战，把"+d_name+"的军队一举歼灭。为"+
			COUNTRY_D->get_country(a_nation,"name")+
			"夺下了"+AREA_D->get_area(def_area,"name")+"。";
	else
		p_dis=a_name+"突发奇兵，为"+
			COUNTRY_D->get_country(a_nation,"name")+
			"拿下了无将防守的"+AREA_D->get_area(def_area,"name")+"。";
	CHANNEL_D->deliver_tell("rumor","system",p_dis);
	HIS(p_dis);

	p_dis=CHAR_D->get_char(a_nation,"name")+"匹夫，你夺我城池，我与你誓不两立！";
	CHANNEL_D->deliver_tell("gossip",CHAR_D->get_char(d_nation,"name"),p_dis);

    if(stringp(d_name))
		p_dis=CHAR_D->get_char(d_nation,"name")+"臭贼，叫你知道我的厉害，"+
			"为百姓免受战火之苦，你还是早早归降吧。「哈哈」！！";
	else
		p_dis="谁叫你不派将防守，知道我的厉害了吧。「哈哈」！！";
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

//    1 人口下降一半。
	tmp=AREA_D->get_area(def_area,"population");
	tmp/=2;
	AREA_D->set_area(def_area,"population",tmp);
//    2 安全下降一半如果大于30，再降到30。 safe=(400-safe)/10
	tmp=AREA_D->get_area(def_area,"safe");
	tmp=(400-tmp)/10;
	AREA_D->set_area(def_area,"safe",tmp);
//    3 金，钱，物减少到30%。
	AREA_D->set_area(def_area,"gold",
		AREA_D->get_area(def_area,"gold")*3/10);

	AREA_D->set_area(def_area,"nation",a_nation);

//    4 原来的兵清零，所有的物资减少80%。
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

	tell_user("huaer","进了war_punish_defence()了\n");
	a_nation=CHAR_D->get_char(att_leader,"nation");

//    5 所有官员(无论玩家NPC在线与否)损失5%的声望。
	d_officers=CHAR_D->check_char("nation",d_nation);
	if(sizeof(d_officers)) {
		foreach(string off in d_officers) {
			int rep,repm;
			rep=CHAR_D->get_char(off,"reputation");
			repm=rep/20; if(repm>1000) repm=1000;
			CHAR_D->set_char(off,"reputation",rep-repm);
		}
	}

	
//  c 被占领区的官员：
	d_officers=CHAR_D->check_char_area("nation",d_nation,def_area);
	d_otherareas=AREA_D->check_area("nation",d_nation);
	d_otherareas-=({def_area});
	if(!sizeof(d_otherareas)) // 亡国了。
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
		HIS(COUNTRY_D->get_country(d_nation, "name")+"亡国了，但君主"+CHAR_D->get_char(d_nation, "name")+"侥幸逃脱了。");
		return;
	}
//    1 官员转道它地
// if a npc char and has vancy, will give a position
// if a play char will give no position
	if(sizeof(d_officers)) {
		string t_area;
			t_area=d_otherareas[random(sizeof(d_otherareas))];
		foreach(string of in d_officers) {
			random_position(of,t_area);
		}
	}
//    4 如果有国家官员逃向首都，可带会原地10%的金，粮和物资。
// consider later
	tell_user("huaer","war_punish_defence()执行完了\n");

}

void war_award_attack1(string att_leader,string *att_party,string def_area) {

	tell_user("huaer","进了war_award_attack1()\n");
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
	tell_user("huaer","war_award_attack1()执行完了\n");
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

	tell_user("huaer","进了war_award_attack()了\n");

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
		o->simple_action("$N道：今日大败敌军，可喜可贺，诸位皆有奖赏。\n");

	DELAY_D->delay_simple_action(o,"%^H_GREEN%^部队的士气上升了。%^RESET%^\n\n",1);
	DELAY_D->delay_simple_action(o,"%^H_WHITE%^$N的经验，声望上升了。%^RESET%^\n\n",2);
	DELAY_D->delay_simple_action(o,"%^H_BLUE%^所有参战玩家的经验，声望上升了。%^RESET%^\n\n",3);
	DELAY_D->delay_simple_action(o,"%^H_GREEN%^主公"+CHAR_D->get_char(a_nation,"name")
		+"的声望上升了。%^RESET%^\n\n",4);
	DELAY_D->delay_simple_action(o,"$N道：这许多好吃好喝的，诸位就随便用吧。\n\n",5);
	DELAY_D->delay_simple_action(o,"%^H_BLUE%^众人都高兴地跳了起来。%^RESET%^\n\n",6);

	
//    1 攻方主帅成为占领区太守。
// already
//   2 攻方主帅声望涨1000。
	CHAR_D->set_char(att_leader,"reputation",
		CHAR_D->get_char(att_leader,"reputation")+1000);
//    3 攻方主帅基本修养等级涨一级。该为经验1000
	if(objectp(o))
		if(o->query_link())
//			o->increase_level();
			o->award_exp(1000);

//    4 随行将领(在线)声望涨200。
//    5 基本修养经验涨500。
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
//    6 还有可能抢到些金银财物。
//    7 进攻方国王声望升1000。
	CHAR_D->set_char(a_nation,"reputation",
		CHAR_D->get_char(a_nation,"reputation")+1000);
//    8 部队士气士气上升20。经验不变
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
        +"残兵败将逃回首都"+AREA_D->get_area(captital,"name");
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
	if (CHAR_D->get_char(def_nation,"type")==TYPE_NPC) //NPC国王,未分配完毕上战场的兵力返回首都布防
	   if (CHAR_D->get_char(def_nation,"area")!=def_area)  //而且不是NPC国的首都被攻占
	       npc_army_back_to_captital(p_id);
	//
	war_punish_defence1(def_area, att_leader); // clear def_area first
	release_army(p_id);
	war_log(p_id,1);
       TASK_D->remove_task(p_id);
	("/sgdomain/event/ev_kwar.c")->job_done(att_leader, def_area);

	call_out("announce_att_win",1,def_leader,att_leader,def_area);
	tell_user("huaer","call_out announce_att_win 完了\n");

	call_out("war_punish_defence",2,def_area,att_leader,def_nation);
	tell_user("huaer","call_out war_punish_defence 完了\n");

	call_out("war_award_attack1",3,att_leader,att_party,def_area);
	tell_user("huaer","call_out war_award_attack1 完了\n");

	//call_out("war_award_attack",6,def_area,att_area,att_leader,att_party); //原来是延迟4秒
	//tell_user("huaer","call_out war_award_attack 完了\n");

	call_out("war_fresh_body",9,att_party);	//原来是延迟7秒
	call_out("war_fresh_body",10,def_party);	//原来是延迟8秒
	// for han di's job
	
}

void announce_def_win(string def_leader,string att_leader,string def_area) {
	string p_dis;
	string d_name,a_name;
	d_name=CHAR_D->get_char(def_leader,"name");
	a_name=CHAR_D->get_char(att_leader,"name");
	p_dis=d_name+"率军奋勇征战，把"+a_name+"打得丢盔弃甲，狼狈逃窜。"
		+AREA_D->get_area(def_area,"name")+"军民欢喜庆功！\n";
	HIS(p_dis);
    	CHANNEL_D->deliver_tell("rumor","system",p_dis);
	p_dis=a_name+"匹夫，暂且放你一条狗命，若还有下次，定叫你有来无回！";
	CHANNEL_D->deliver_tell("gossip",d_name,p_dis);
	p_dis=d_name+"臭贼，休要如此猖狂，我定会卷土重来！哼！";
	CHANNEL_D->deliver_tell("gossip",a_name,p_dis);
	return;
}
void war_punish_attack(string *att_party,string a_area){

	string *chars;
	string a_nation;	
	int rep;
// 所有参战官员声望下降10%(最大不朝过1000)。
	if(sizeof(att_party)) {
		foreach(string id in att_party) {
			rep=CHAR_D->get_char(id,"reputation");
			if(rep>10000) rep-=1000;
			else rep=rep*9/10;
			CHAR_D->set_char(id,"reputation",rep);
		
		}
	}
//    2 所有原地官员声望下降5%(最大不超过500)。
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

//    3 进攻方国王声望降5%(最大不超过1000)。
	rep=CHAR_D->get_char(a_nation,"reputation");
	if(rep>20000) rep-=1000;
	else rep=rep*95/100;
	CHAR_D->set_char(a_nation,"reputation",rep);

//    4 损失金物资粮草。 // this will be later
//    5 地方安定下降30。
	rep=AREA_D->get_area(a_area,"safe");
	rep-=30; if(rep<=0) rep=1;
	AREA_D->set_area(a_area,"safe",rep);
//    6 军队士气下降20。
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
		o->simple_action("$N道：今日大败敌军，可喜可贺。诸位皆有奖赏。\n");

	DELAY_D->delay_simple_action(o,"%^H_GREEN%^当地的安定上升了。%^RESET%^\n\n",1);
	DELAY_D->delay_simple_action(o,"%^H_GREEN%^部队的士气经验上升了。%^RESET%^\n\n",2);
	DELAY_D->delay_simple_action(o,"%^H_WHITE%^$N的经验经验，声望，地区贡献上升了。%^RESET%^\n\n",3);
	DELAY_D->delay_simple_action(o,"%^H_BLUE%^所有参战玩家的经验，声望，地区贡献上升了。%^RESET%^\n\n",4);
	DELAY_D->delay_simple_action(o,"$N道：这许多好吃好喝的，诸位就随便用吧。\n\n",5);
	DELAY_D->delay_simple_action(o,"%^H_BLUE%^众人都高兴地跳了起来。%^RESET%^\n\n",6);

//    1 地方安定降10。
	rep=AREA_D->get_area(d_area,"safe");
	rep-=10;
	AREA_D->set_area(d_area,"safe",rep);
//    2 军队士气经验上升20。 // no need the morale increase in the arrange stage
//	rep=AREA_D->get_area(d_area,"morale");
//	rep+=20;
//	AREA_D->set_area(d_area,"morale",rep);
//	rep=AREA_D->get_area(d_area,"train");
//	rep+=20;
//	AREA_D->set_area(d_area,"train",rep);

//    3 可得部分敌方金粮物。 // not yet

//    4 主帅基本修养经验上升1000。
	if(objectp(o))
		if(o->query_link())
			o->award_exp(800);
//    5 主帅声望升300。
	rep=CHAR_D->get_char(p_leader,"reputation");
	rep+=300;
	CHAR_D->set_char(p_leader,"reputation",rep);
//    6 主帅地区贡献涨10。
	rep=CHAR_D->get_char(p_leader,"localcontribution");
	rep+=10;
	CHAR_D->set_char(p_leader,"localcontribution",rep);

//    7 太守和其他参战在线玩家得一半主帅奖励。
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
