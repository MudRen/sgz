// gethead.c
#define job_id "gethead"
void award(object usr)
{
          AWARD(usr,100); //original is 30, modified by row seem 300 to high, change to 100
}

// target is the npc ppl, me is the player :)
void answer_yes(object target, object me,string ans) {
	object bs;
    string p_area,f_id,p_id;
	int money;
	if(ans!="yes") {
		target->targetted_action(
		"$N�����ض�$T˵�������𶼲��ϸ���$rҲ̫С���ˡ�\n",me);
		target->simple_action("$Nת���뿪�ˡ�\n");
		destruct(target);
		return;
	}
	if(MONEY_D->sub_poket_money(me,10000)!=1) {
		me->targetted_action(
			"$Nһģ�ڴ�����һ�죬��$T������˼��˵���Բ�������û����ô��Ǯ��\n",target);
		target->responda("ack");
		target->simple_action("$Nת���뿪�ˡ�\n");
		destruct(target);
		me->simple_action("$N��һֻľ��һ������·���С�\n");
		return;
	}
	me->targetted_action(
		"$N��$Tһ�����ӡ�\n",target);
	target->responda("rich");
	target->targetted_action(
		"$N��$T˵������׼��һ�£�����ȥ��\n",me);


	p_area=me->query_job(job_id,"area");
	f_id=me->query_job(job_id,"f_id");

	bs=SGBASE(p_area,f_id);
	if(objectp(bs)) {
		bs->add_head(target);
	}
	target->simple_action("$Nת���뿪�ˡ�\n");
	destruct(target);
	ROBOT->robot_test(find_user(me->query_primary_id()),(:award:));

}

// target is the npc ppl, me is the player :)
void answer_salary(object target, object me,string ans) {
	mapping info;	
	int m_salary=to_int(ans);
	int p_salary;
	string p_id=target->get_p_id();

	target->clear_answer();
	info=target->get_info();
	p_salary=info["salary"];
	if(m_salary<p_salary) {
		target->targetted_action(
		"$N�����ض�$T˵����һ�²�"+CHINESE_D->chinese_value(m_salary*100)+
		"��$rҲ̫С���ˡ�\n",me);
		target->simple_action("$Nת���뿪�ˡ�\n");
		destruct(target);
		return;
	}
	target->set_salary(m_salary);
	target->responda("jump");
	target->targetted_action(
		"$N��$T����$R����̫���ˣ������һ���Ҫһ��������Ϊ���𣬿��Ը�����\n",me);
	tell(me,"�� answer yes to "+p_id+" ��ʾͬ�⡣\n");

	target->set_answer(me->query_primary_id(), (:answer_yes:) ); 
}


mixed basic_check(string p_area,string f_id) {
	object bs;
	bs=SGBASE(p_area,f_id);
	if(!objectp(bs)) 
		return "$N��$T�ɻ���ʣ���˵"+AREA_D->get_area(p_area,"name")+
			"��"+BASE_D->get_base(f_id,"name")+"�Ѿ������ˡ�\n";
	if(!stringp(bs->no_head_room()))
		return "$N��$T�ɻ���ʣ���˵"+AREA_D->get_area(p_area,"name")+
			"��"+BASE_D->get_base(f_id,"name")+"�Ѿ�û�п�ȱ�ˡ�\n";
	return 1;
}
void ask_gethead(object me, object target)
{
        string p_area,f_id;
		string p_id,t_id,typ;
		object bs;
		mixed ret;
		p_area=me->query_job(job_id,"area");
		f_id=me->query_job(job_id,"f_id");
		p_id=me->query_primary_id();
		t_id=target->get_p_id();
		me->clear_asklist(job_id);
		me->finish_job(job_id);
		bs=SGBASE(p_area,f_id);
        me->targetted_action(
			"$N��$TЦ��˵����"+AREA_D->get_area(p_area,"name")+
			"��"+BASE_D->get_base(f_id,"name")+"��Ҫһ���µ�"+
			BASE_D->get_base(f_id,"headname")+"��\n"+
			"$s����$R�������ɷ���$R���ʹ�ְ��\n",target);

		target->responda("consider");
		ret=basic_check(p_area,f_id);
		if(stringp(ret)) {
			target->targetted_action(ret,me);
			me->finish_job(job_id);
			return ;
		}

		target->targetted_action(
			"$N��$T����һ���µ�Ӷ���Ƕ��٣�\n",me);
		tell(me,"�� answer <����> to "+t_id+" ���ش� <����> ����ÿ�¶���������(1-100)��\n");
		target->set_answer(p_id, (:answer_salary:) );
}
