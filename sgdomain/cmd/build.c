// build
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

	if( (!arg)||(arg=="") ){
		write("�÷���cmd build <��������ID>\n");
		write("���ӣ�cmd build farm  ����(����)ũ��\n");
		write("��ϸ�������������� info b.\n");        
		return;
	}
	f_id=arg;
	if( !CHAR_D->get_char(p_id,"nation") ){
		write("������˸�һ�ٰ�ְ�Ժ��ٿ��ǽ����������ص�����ɡ�\n");
		return;
	}
	if((CHAR_D->get_char(p_id,"level")<2))
	{
		write("��Ĺ�ְ̫�ͣ����ܽ��齨���������ء�\n");
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

	ret=BASE_D->can_build(p_area,f_id);
	if(stringp(ret)) {
		printf("������Ч��ԭ��%s\n",ret);
		return;
	}
	if(ret==1) {
		t_string="����"+BASE_D->get_base(f_id,"name");
               (EV_LOCALMEETING)->get_suggestion(task_id,p_id,"build",f_id);
	}
	else {
		t_string="����"+BASE_D->get_base(f_id,"name");
		(EV_LOCALMEETING)->get_suggestion(task_id,p_id,"update",f_id);
	}
	p_talk=sprintf(
	"$N�����������ش��˶࣬���������Ҳ��㡣$s��Ϊ���ǵ�%s���Լ�ǿ���صľ���ʵ����\n",
	t_string);
    this_body()->simple_action(p_talk);
}


