// train.c 
// by fire on Dec 12, 1998
// this is used to give train suggestion on the localmeeting.
void start(string arg)
{
        int my_id,task_id;
        int* my_task;
        int p_soldier;
	string p_id;
	string p_area1;
	p_id=this_body()->query_id()[0];
	p_area1=CHAR_D->get_char(p_id,"area");
//        write("�����޸ĳ������Ȳ�Ҫѵ����\n"); return;
        my_id=this_body()->query_id()[0];

/*if( !wizardp(this_body()) ){
        write("������ʱ��ֹ��\n");
        return;
};*/
        if(!CHAR_D->get_char(my_id,"nation"))
        {  write("������˸�һ�ٰ�ְ�Ժ�������������������ɡ�\n");
          return;
        }
        my_task = TASK_D->get_char_task(my_id);
        if(my_task[1]!=TT_LOCALMEETING)
        {  write("������⻹���ڵ���������̸�ɡ�\n");
           return;
        }
	if(((file_name(environment(this_body())))!=
((AREA_D->get_area(p_area1,"path"))+(AREA_D->get_area(p_area1,"meeting"))))||(p_area1!=
		environment(this_body())->get_area()))
	{
		write("�����������ڻ���֮�����ۡ�\n");
		return;
	}
        task_id=my_task[0];
        if(TASK_D->get_task(task_id,"suggestion"))
        {   write("���������������������⣬�������Ȼ����˵�ɡ�\n");
            return;
        }
        if(((TASK_D->get_task(task_id,"timaim")-
                TASK_D->get_task(task_id,"timer"))<3)&&
                (TASK_D->get_task(task_id,"stage")!=0))
        {
                write("ʱ�䲻���ˣ���ͷ����ɡ�\n");
                return;
        }
        p_soldier=AREA_D->get_area(CHAR_D->get_char(my_id,
             "area"),"soldier");
        if(p_soldier<50)
        {   write("һ�����Ǽ���������ʲô�����ģ���\n");
            return;
        } 
        this_body()->simple_action(
"$N�������Ե������󾫶�����࣬$sԸ���ϰ���󷨣���׳������\n");
        (EV_LOCALMEETING)->get_suggestion(task_id,
            my_id,"train");
}
