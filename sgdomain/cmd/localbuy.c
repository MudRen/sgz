// localbuy.c by fire on Dec 1999
// this is used to give suggestion for buy sth for localarea
void start(string arg)
{
	string *list;
	mapping name=([]);
	string p_talk,ret="�÷���cmd localbuy <id>\n���Խ��鹺��Ļ����У�\n id       ����\n����������������\n";
    int my_id,task_id;
    int* my_task;
	string p_id;
	string p_area;
	p_id=this_body()->query_id()[0];
	p_area=CHAR_D->get_char(p_id,"area");

	list=(EV_MERCHANT)->query_goods("list");
	foreach(string l in list)
	{
		name[l]=(EV_MERCHANT)->query_goods(l,"name");
		ret+=sprintf("%-10s% : -20s\n",l,name[l]);
	}
    if((!arg)||(arg==""))
    {
		write(ret);
		return;
    }
	if(((file_name(environment(this_body())))!=
((AREA_D->get_area(p_area,"path"))+(AREA_D->get_area(p_area,"meeting"))))||(p_area!=
		environment(this_body())->get_area()))
	{
		write("�����������ڻ���֮�����ۡ�\n");
		return;
	}
	if(member_array(arg,list)==-1)
	{
		write("û�����ֻ��\n");
		write(ret);
		return;
	}
    my_id=this_body()->query_id()[0];
    if(!CHAR_D->get_char(my_id,"nation"))
    {
         write("������˸�һ�ٰ�ְ�Ժ��ٿ��ǹ������ʰɡ�\n");
         return;
    }
        if(CHAR_D->get_char(my_id,"level")<2)
        {
                write("��Ĺ�ְ̫�ͣ������������Ľ��顣\n");
                return;
        }

    my_task = TASK_D->get_char_task(my_id);
    if(my_task[1]!=TT_LOCALMEETING)
    {    write("������⻹���ڵ���������̸�ɡ�\n");
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
    {     write("ʱ�䲻���ˣ���ͷ����ɡ�\n");
          return;
    }
    if(stringp((PJOB+"localbuy/localbuy")->get_localbuy(my_id)))
    {	string my_buy=(PJOB+"localbuy/localbuy")->get_localbuy(my_id);
		write("��ɹ�"+name[my_buy]+"������û����ء�\n");
        return;
    }
    p_talk=sprintf("$N������������%s�������㣬�ѱ����հ�����ҵ��$s��Ϊ����"+
"����һ��%s���Ա��������ĳ����ΰ���������λ���ˡ�������˼��\n",name[arg],name[arg]);
    this_body()->simple_action(p_talk);
    (EV_LOCALMEETING)->get_suggestion(task_id,my_id,"localbuy",arg);
}