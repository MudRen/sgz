void start()
{
	int troop, task, *ts;
	string who, side, area, *chars;
	object env;
	mixed target;

	who = this_body()->query_id()[0];
	env = environment(this_body());
	if( !env->is_troop() ){
           	write("ֻ�����ھ��в���ָ�ӳ��ˡ�\n");
           	return ;
	}
	troop = env->get_id();
	task = TROOP_D->get_troops(troop, "task_id");
	side = TROOP_D->get_troops(troop, "side");
	if( (side=="a"&&who!=TASK_D->get_task(task, "att_leader")) || 
	    (side=="d"&&who!=TASK_D->get_task(task, "def_leader")) ){
		write("ֻ�������ſ����´ﳷ�˵����\n");
		return;
	}
	if( TASK_D->get_task(task, "def_stage") != "enter_warfield" ){
		write("��û��ս��Ҫ���ܰ���\n");
		return;
	}
	if( TASK_D->get_task(task, "type") == 3 ){
		write("����ѵ��������Ҳ�����ܣ�\n");
		return;
	}
	if( side == "a" ){
		area = TROOP_D->get_troops(troop, "source_area");
		if( AREA_D->get_area(area, "nation") != CHAR_D->get_char(who, "nation") ){
			write(AREA_D->get_area(area,"name")+"��������֣����޳ǿ��ˡ�\n");
			return;
		}
		WARAI_D->war_inf(task, CHAR_D->get_char(who, "name")+"��е��������������ձ��ɡ�\n", "");
		CHANNEL_D->deliver_tell("gossip",CHAR_D->get_char(who,"name"),"�����ҷŹ����ǣ��´ζ�ҪѪϴ"+AREA_D->get_area(TROOP_D->get_troops(troop, "area"), "name")+"��");
		CHANNEL_D->deliver_tell("rumor","system",CHAR_D->get_char(who,"name")+"���ж��ˣ�����"+AREA_D->get_area(area, "name")+"�ˣ�");
		(EV_WAR)->war_def_win(task);
	} else {
		area = TROOP_D->get_troops(troop, "def_area");
		target = AREA_D->get_area(area, "neighbor");
		if( !arrayp(target) ){
			write("�����޴����ˣ����Ǿ�һ��ս�ɡ�\n");
			return;
		}
		foreach(string tt in target){
			if( AREA_D->get_area(tt, "nation") == CHAR_D->get_char(who, "nation") ){
				ts = TASK_D->get_task(task,"def_army");
				foreach(int t in ts)TROOP_D->set_troops(t,"source_area",tt);
				chars = TASK_D->get_task(task,"def_party");
				foreach(string cc in chars){
					CHAR_D->set_char(cc, "area", tt);
					CHAR_D->set_char(cc,"ranklocal",R_SG);
				};
				WARAI_D->war_inf(task, CHAR_D->get_char(who, "name")+"��е�����������������"+AREA_D->get_area(tt, "name")+"�ɡ�", "");
				CHANNEL_D->deliver_tell("gossip",CHAR_D->get_char(who,"name"),"������������ն�Ҫ����ױ��ո�ʧ�أ�\n");
				CHANNEL_D->deliver_tell("rumor", "system",CHAR_D->get_char(who, "name")+"��ս���ˣ�����"+AREA_D->get_area(tt, "name")+"�ˣ�");
				(EV_WAR)->war_att_win(task);
				return;
			}
		}
		write("�����޴����ˣ����Ǿ�һ��ս�ɡ�\n");
	};

	return;
}
