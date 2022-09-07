// buildbase.c

void commonaward(object usr,int num) {
    int isrobot;
	int n;
	string p_id;
	if(!objectp(usr)) return;
	usr=usr->query_body();
	if(!objectp(usr)) return;
	p_id=usr->query_primary_id();
    isrobot=usr->query_robot();
    if(isrobot)
    {   
		tell_user(p_id,"%^H_RED%^��æ��һ����ʲôҲû�̵���%^RESET%^\n");
		usr->responda("poor "+p_id);
		return;
    }
	n=num+random(num/2);
	CHAR_D->add_honor_point(p_id,n);
	tell_user(p_id,"%^H_GREEN%^�ɵò����õ���"+chinese_number(n)+
	   "�㽱�㡣%^RESET%^\n");
	usr->responda("jump");

}

void award(object usr)
{
	commonaward(usr,5);
}

void common_robot(object usr, int num) {
	ROBOT->robot_test(usr,(:commonaward:),num);
}
void ask_buildbase(object me, object target)
{
        string p_area,f_id;
		string p_id,t_id;
		object bs;
		mixed ret;
		p_area=me->query_job("buildbase","area");
		f_id=me->query_job("buildbase","f_id");
		p_id=me->query_primary_id();
		t_id=target->query_primary_id();
		me->clear_asklist("buildbase");
		me->finish_job("buildbase");
		bs=SGBASE(p_area,f_id);
        me->targetted_action(
			"$N��$TЦ��˵�������������費�㣬$s��ΪӦ����"+
			BASE_D->get_base(f_id,"name")+"���ٽ���һ��"+
			BASE_D->get_base(f_id,"roomname")+"����֪$R������Σ�\n",target);
		if(!bs) {
			target->responda("sorry "+p_id);
			DELAY_D->delay_targetted_action(target,me,
				"$N��������"+BASE_D->get_base(f_id,"name")+
				"�Ѿ��������ˡ�\n",1);
			return;
		}
		if(bs->get_leader()!=t_id) {
			target->responda("sorry "+p_id);
			DELAY_D->delay_targetted_action(target,me,
				"$N����$s�Ѿ�����"+BASE_D->get_base(f_id,"name")+
				"���ܼ��ˡ�\n",1);
			return;
		}
		ret=bs->can_hame_more_room();
		if(stringp(ret)) {
			target->responda("sorry "+p_id);
			DELAY_D->delay_targetted_action(target,me,
				"$N����"+ret+"\n",1);
			return;
		}
		bs->add_new_room();
		target->responda("great "+p_id);
		target->targetted_action("$N���������⣬$s����ȥ�졣\n",me);
		ROBOT->robot_test(find_user(p_id),(:award:));
		if(!CHAR_D->get_char(t_id,"task")) {
			CHAR_D->remove_npc_char(t_id);
		}
}