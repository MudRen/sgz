// importance.c 
// by fire on August 30, 1998
// used to suggest local development importance
string get_reson(int p_inp)
{
        switch(p_inp)
        {
                case AI_BALANCE:
                        return "���ڱ�������չ��ƽ�⣬";
                case AI_AGRICULTURE:
                        return "���ڱ������������㣬";
                case AI_INDUSTRY:
                        return "���ڱ��������ʲ��㣬";
                case AI_BUSINESS:
                        return "���ڱ��������ʲ��㣬";
                case AI_SAFE:
                        return "���ڱ��������Ĳ��ȣ�";
                case AI_MILITARY:
                        return "���ڱ�������ʿս�����㣬";
        }
}
string get_obj(int p_inp)
{
        switch(p_inp)
        {
                case AI_BALANCE:
                        return "����";
                case AI_AGRICULTURE:
                        return "��ǿũҵ";
                case AI_INDUSTRY:
                        return "��ǿ��ҵ";
                case AI_BUSINESS:
                        return "��ǿ��ҵ";
                case AI_SAFE:
                        return "�ȶ�����";
                case AI_MILITARY:
                        return "��ǿ����";
        }
}
string get_talk(int p_oldinp,int p_inp)
{
        string p_ret;
        p_ret=get_reson(p_inp);
        p_ret+="$s��Ϊ��Ŀǰ��"+get_obj(p_oldinp)+"��չ�������Խ��������⣬\n"+
"�ʽ����Ϊ"+get_obj(p_inp)+"��չ���ԣ�����λ���ˡ�������˼��\n";
        return p_ret;
}
int get_importance(string p_inp)
{
        switch(p_inp)
        {
                case "balance":
                        return AI_BALANCE;
                case "agriculture":
                        return AI_AGRICULTURE;
                case "industry":
                        return AI_INDUSTRY;
                case "business":
                        return AI_BUSINESS;
                case "safe":
                        return AI_SAFE;
                case "military":
                        return AI_MILITARY;
                default:
                        return -1;
        }
}
void start(string arg)
{
        int p_inp,p_oldinp;
        string p_talk;
        int my_id,task_id;
	string p_id;
	string p_area1;
        int* my_task;
	p_id=this_body()->query_id()[0];
	p_area1=CHAR_D->get_char(p_id,"area");
        if(!arg)
                arg="";
        p_inp=get_importance(arg);
        if(p_inp==-1)
        {
                write("�÷�����");
                write("�� cmd help importance �鿴��ϸ������\n");
                return;
        }
        my_id=this_body()->query_id()[0];
        if(!CHAR_D->get_char(my_id,"nation"))
        {
                write("������˸�һ�ٰ�ְ֮���ٿ��ǵ����ص������ɡ�\n");
                return;
        }
        if(CHAR_D->get_char(my_id,"level")<2)
        {
                write("��Ĺ�ְ̫�ͣ������������Ľ��顣\n");
                return;
        }

        my_task = TASK_D->get_char_task(my_id);
        if(my_task[1]!=TT_LOCALMEETING)
        {
                write("������⻹�ǵ�����������̸�ɡ�\n");
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
                write("�����������۱�����⣬�������Ȼ����˵�ɡ�\n");
                return;
        }
        if(((TASK_D->get_task(task_id,"timaim")-
                TASK_D->get_task(task_id,"timer"))<3)&&
                (TASK_D->get_task(task_id,"stage")!=0))
        {
                write("ʱ�䲻���ˣ���ͷ����ɡ�\n");
                return;
        }
        {       
		string p_area;
                int p_safe;
                p_area=CHAR_D->get_char(my_id,"area");
                p_safe=AREA_D->get_area(p_area,"safe");
                if(p_safe<5)
                {
                        write("�����Ѿ����Ȳ������ٱ䶯���ߣ������𱩶�������\n");
                        return;
                }
        }
        p_oldinp=AREA_D->get_area(CHAR_D->get_char(my_id,
                "area"),"importance");
        if(p_oldinp==p_inp)
        {
                printf("��Ľ���û��ʲô���⣬�������˰ɡ�\n");
                return ;
        }
        p_talk=get_talk(p_oldinp,p_inp);
        this_body()->simple_action("$N����"+p_talk);
        (EV_LOCALMEETING)->get_suggestion(task_id,my_id,"importance",p_inp);
}
