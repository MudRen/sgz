// over.c 
// by fire on April 4, 1998
// this is used terminate the meeting in localmeeting
void start(string arg)
{
        int my_id,task_id;
        int* my_task;
	string p_id;
	string p_area1;
	p_id=this_body()->query_id()[0];
	p_area1=CHAR_D->get_char(p_id,"area");
        my_id=this_body()->query_id()[0];
        if(!CHAR_D->get_char(my_id,"nation"))
        {  write("������˸�һ�ٰ�ְ�Ժ��������ǽ���ɢ��ɡ�\n");
          return;
        }
	if(((file_name(environment(this_body())))!=
((AREA_D->get_area(p_area1,"path"))+(AREA_D->get_area(p_area1,"meeting"))))||(p_area1!=
		environment(this_body())->get_area()))
	{
		write("�����������ڻ���֮�����ۡ�\n");
		return;
	}
        my_task = TASK_D->get_char_task(my_id);
        if(my_task[1]!=TT_LOCALMEETING)
        {  write("�����ڲ�û���ڿ���ѽ��\n");
           return;
        }
        task_id=my_task[0];
        if(TASK_D->get_task(task_id,"suggestion"))
        {   write("���������������⣬��ô��ɢ���أ�\n");
            return;
        }
        if(((TASK_D->get_task(task_id,"timaim")-
                TASK_D->get_task(task_id,"timer"))<3)&&
                (TASK_D->get_task(task_id,"stage")!=0))
        {
                write("ʱ�䲻���ˣ��������Ͼͽ����ˣ����ĵ�һ�Ȱɡ�\n");
                return;
        }
	if((time()-TASK_D->get_task(task_id,"start_time"))<30) {
                write("����ſ�ʼ�������ĵ�һ�Ȱɡ�\n");
                return;
	}
        this_body()->simple_action(
"$N����$s��Ϊ�������̸�Ķ�̸�ˣ��ǲ��ǿ������ɢ�᣿\n");
        (EV_LOCALMEETING)->get_suggestion(task_id,
            my_id,"over");
}
