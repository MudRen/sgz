// sendfood.c  ɢ��
// by fire on Jan 1999
void start(string arg)
{
	int p_population,p_safe;
    int p_food,p_foodout,p_send;
    int p_month=DAY_D->query_date()[2];
    string p_talk,p_area,p_id;
    int task_id;
    int* my_task;
	string p_area1;
	p_id=this_body()->query_id()[0];
	p_area1=CHAR_D->get_char(p_id,"area");
    if((!arg)||(arg==""))
    {
        write("�÷���cmd sendfood ��ʳ��\n");
        write("���ӣ�cmd sendfood 10000   ɢһ����ʳ\n");
        write("�� cmd help sendfood �鿴��ϸ������\n");
        return;
    }
    p_send=to_int(arg);
    if(!CHAR_D->get_char(p_id,"nation"))
    {
            write("������˸�һ�ٰ�ְ�Ժ��ٿ���ɢ������ɡ�\n");
            return;
    }
//        if(CHAR_D->get_char(p_id,"level")<2);
//        {
//                write("��Ĺ�ְ̫�ͣ������������Ľ��顣\n");
//                return;
//        }

    my_task = TASK_D->get_char_task(p_id);
    if(my_task[1]!=TT_LOCALMEETING)
    {
            write("������⻹���ڵ���������̸�ɡ�\n");
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
    {
            write("���������������������⣬�������Ȼ����˵�ɡ�\n");
            return;
    }
    if(((TASK_D->get_task(task_id,"timaim")-
            TASK_D->get_task(task_id,"timer"))<3)&&
            (TASK_D->get_task(task_id,"stage")!=0))
    {
            write("ʱ�䲻���ˣ���ͷ����ɡ�\n");
            return;
    }
	p_area=CHAR_D->get_char(p_id,"area");
    if(p_month>=9) p_month=17-p_month;
	else p_month=9-p_month;
	p_population=AREA_D->get_area(p_area,"population");
	p_food=AREA_D->get_area(p_area,"food");
	p_foodout=AREA_D->get_area(p_area,"foodout");
    p_safe=AREA_D->get_area(p_area,"safe");
	if((p_send*10)<p_population)
    {   write("һ��ɢ�������ǰ�����Ŀ��ʮ��֮һ��\n");
        return;
    }
	if((p_send)>(10*p_population))
    {   write("һ��ɢ�������ǰ�����Ŀ��ʮ����\n");
        return;
    }
	if((p_send)>p_food)
    {   write("������û����ô�����ʳ��\n");
        return;
    }
	if((p_send+p_month*p_foodout)>p_food)
    {
        write("ɢ��ô������ʿ������Ҫ������\n");
        return ;
    }
	if(p_safe>=70)
	{
		write("���շ�����ʳ�����ڲ���Ҫɢ�����֡�\n");
		return;
	}
    p_talk=sprintf("$N˵����������Ϊ�������°�������ƶ�࣬\n"+
		"$s��Ϊ��ɢ��%s��������\n",
		chinese_number(p_send));
    this_body()->simple_action(p_talk);
    (EV_LOCALMEETING)->get_suggestion(task_id,p_id,"sendfood",p_send);
}
