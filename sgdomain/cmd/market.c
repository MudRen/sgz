// market suggest to open market
// by fire on January 28, 2000
void start(string arg)
{
	string p_talk;
	int task_id;
	int* my_task;
	string p_id;
	string p_area;
	string f_id;
	string t_string;
	mixed ret;

	p_id=this_body()->query_primary_id();
	p_area=CHAR_D->get_char(p_id,"area");

	if( !CHAR_D->get_char(p_id,"nation") ){
		write("������˸�һ�ٰ�ְ�Ժ��ٿ��ǽ����������ص�����ɡ�\n");
		return;
	}
	my_task = TASK_D->get_char_task(p_id);
	if( my_task[1] != TT_LOCALMEETING ){
		write("������⻹���ڵ���������̸�ɡ�\n");
		return;
	}
	if(((file_name(environment(this_body())))!=
		((AREA_D->get_area(p_area,"path"))+
		(AREA_D->get_area(p_area,"meeting"))))||(p_area!=
		environment(this_body())->get_area()))
	{
		write("�����������ڻ���֮�����ۡ�\n");
		return;
	}
	task_id = my_task[0];
	if( TASK_D->get_task(task_id,"suggestion") ){
		write("���������������������⣬�������Ȼ����˵�ɡ�\n");
		return;
	}
	if(((TASK_D->get_task(task_id,"timaim")-TASK_D->get_task(task_id,"timer"))<3)
		&&(TASK_D->get_task(task_id,"stage")!=0))
	{
		write("ʱ�䲻���ˣ���ͷ����ɡ�\n");
                return;
        }
/*	ret=(PJOB+"build/build")->get_build_job(p_area); // the job is for the area
        if(stringp(ret) ){
            	printf("���ǵ����ĵ�%s������û������ء�\n",ret);
            	return;
        } */
	write("��������ս�ң��������У���ҵϵͳ��ʱ�ر��ˡ�\n");
        return;
        
	ret=(EV_MERCHANT)->can_have_market(p_area) ;
	if(stringp(ret)) {
		printf("������Ч��ԭ��%s\n",ret);
		return;
	}
	p_talk="$N����������Ϊ�����񲻸���ǿ��$s��Ϊ���ؿ��Կ��ż��У���λ������Ρ�\n";
    this_body()->simple_action(p_talk);
	(EV_LOCALMEETING)->get_suggestion(task_id,p_id,"market",p_area);

}


