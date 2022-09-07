// ev_sleep.c
// by emperor on 2000.2.28
// this is used to handle player makelove
void the_end1(string id);
void the_end2(string id);
void conform_sleep(object who,object parter);
void sleep(object who,object parter,string ans);
void run_sleep(object who, object parter);

void ask_sleep(object who, object parter)
{
	int w_gender, p_gender;
	string w_id, p_id;
	int w_hp, p_hp;
	int w_food,w_drink,p_food,p_drink;
	object env;
	w_id=who->query_primary_id();
	p_id=parter->query_primary_id();
	w_gender=who->query_gender();
	p_gender=parter->query_gender();
	if(CHAR_D->get_char(p_id,"mar")==w_id) {
		if(who->query_gravidity()){
			parter->targetted_action("$N��$t˵������$c�������У������з�����\n",who);
			return;
		}
		if(parter->query_gravidity()){
			parter->targetted_action("$N��$t˵������$c, ����������У������з�����\n",who);
			return;
		}
		env=environment(parter);
/*
		if(env->query_bedroom_master()!=w_id||env->query_bedroom_master()!=p_id){
			parter->targetted_action("$N��$t˵������$c, ��˯������˵�ɡ���\n",who);
			return;
		}
*/
		w_food=who->query_sg_food();
		w_drink=who->query_sg_drink();
		p_food=parter->query_sg_food();
		p_drink=parter->query_sg_drink();
		if(!w_food){
			parter->targetted_action("$N��$t˵������$c, �����ںܶ������ȳ�Щ�����ɡ���\n",who);
			return;
		}
		if(!w_drink){
			parter->targetted_action("$N��$t˵������$c, �����ںܿʣ����Ⱥ�Щ�����ɡ���\n",who);
			return;
		}
		if(!p_food){
			parter->targetted_action("$N��$t˵������$c, �����ںܶ������ҳ�Щ������˵�ɡ���\n",who);
			return;
		}
		if(!p_drink){
			parter->targetted_action("$N��$t˵������$c, �����ںܿʣ����Һ�Щ������˵�ɡ���\n",who);
			return;
		}

		w_hp=who->query_cur_hp();
		p_hp=parter->query_cur_hp();
		if((w_hp*100<who->query_cur_max_hp()*90)
			||(who->query_cur_mp()*100<who->query_cur_max_mp()*90)){
			parter->targetted_action("$N��$t˵������$c, ���������������棬����Ϣһ�°ɡ���\n",who);
			return;
		}
		if((p_hp*100<parter->query_cur_max_hp()*90)
			||(parter->query_cur_mp()*100<parter->query_cur_max_mp()*90)){
			parter->targetted_action("$N��$t˵������$c, ���������������棬�Ȼ����˵�ɡ���\n",who);
			return;
		}
		conform_sleep(who,parter);
	}else	if(w_gender==p_gender)
		parter->targetted_action("$N��$t�ȵ���$r,�������в�����\n",who);
	else if (w_gender==1)
		parter->targetted_action("$Nɫ���Եض�$tЦ�����Һ����㣡\n",who);
	else parter->targetted_action("$N������$t�ȵ�����å������Զ�㣡\n",who);
	return;
}

void conform_sleep(object who,object parter){
	string w_id,p_id;
	w_id=who->query_primary_id();
	p_id=parter->query_primary_id();
	who->set_answer(p_id,  (:sleep:) );
	tell_user(p_id,"��Ը��������� answer yes to "+w_id+"��\n");
}

void sleep(object parter,object who,string ans){
	switch(ans)
	{
		case "yes":
		case "y":
//			who->targetted_action("$N����ض�$T����$c,�ðɡ�\n",parter);
			run_sleep(who,parter);
			who->clear_answer();
			return;
		default:
//			who->targetted_action("$N�ź��ض�$T����$c�����ڲ��С�\n",parter);
			who->clear_answer();
		return;
	}
}

void run_sleep(object who, object parter){
	string w_id, p_id;
	int w_gender, p_gender;
	int sleeptime;
	sleeptime=30+random(20);
	w_id=who->query_primary_id();
	p_id=parter->query_primary_id();
	w_gender=who->query_gender();
	p_gender=parter->query_gender();
	who->responda("drop all");
	parter->responda("drop all");
	who->responda("sit on bed");
	parter->responda("sit on bed");
	if(p_gender==1) { // male
		parter->targetted_action("$N�Ȳ������ر�ס$t����������塣����\n",who);
	}else{
		who->targetted_action("$N�Ȳ������ر�ס$t����������塣����\n",parter);
	}
	parter->start_busy(sleeptime, "�������з��С�\n");
	who->start_busy(sleeptime, "�������з��С�\n");
	parter->set_cur_hp(0);
	who->set_cur_hp(0);
	parter->set_cur_mp(0);
	who->set_cur_mp(0);
	call_out("the_end1",sleeptime+1,p_id);
	call_out("the_end2",sleeptime+1,w_id);
}

void the_end1(string id){
	object o=find_body(id);
	if(!objectp(o))
		return;
	o->simple_action("$N�۵�һ�㾢��û�ˡ�\n");
	if(o->query_gender()!=1)
		if(random(40)==1) o->set_gravidity();
	return;
}

void the_end2(string id){
	object o=find_body(id);
	if(!objectp(o))
		return;
	o->simple_action("$N�۵�һ�㾢��û�ˡ�\n");
	if(o->query_gender()!=1)
		if(random(40)==1) o->set_gravidity();
	return;
}



