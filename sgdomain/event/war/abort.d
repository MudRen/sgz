void destruct_area(string area) {
        MAP_D->destruct_area(area);
}

void release_army(int p_id)
{
	int* army;
	int att_left=0,def_left=0;
	string area;
	area=TASK_D->get_task(p_id,"area");
	call_out("destruct_area",1,area);
	army=TASK_D->get_task(p_id,"att_army");
	if(sizeof(army))
		foreach(int t_id in army)
		{

			att_left+=TROOP_D->get_soldier_total_number( t_id);
			TROOP_D->remove_troop(t_id);
		}
        army=TASK_D->get_task(p_id,"def_army");
        if(sizeof(army))
                foreach(int t_id in army)
                {
			def_left+=TROOP_D->get_soldier_total_number( t_id);
                        TROOP_D->remove_troop(t_id);
                }
	TASK_D->set_task(p_id,"msg_att_left","������ʣ�������"+chinese_number(att_left));
	TASK_D->set_task(p_id,"msg_def_left","���ط�ʣ�������"+chinese_number(def_left));
}
		
void abort_war(int p_id)
{
	string att_name,def_area;
	string p_dis;
	att_name=TASK_D->get_task(p_id,"att_name");
	def_area=TASK_D->get_task(p_id,"def_area");
        p_dis=att_name+"ȡ���˽���"+AREA_D->get_area(def_area,"name")+
                "�ļƻ���";
        CHANNEL_D->deliver_tell("rumor","system",p_dis);
       release_army(p_id);
	TASK_D->remove_task(p_id);
     MAP_D->destruct_area(def_area);
}

