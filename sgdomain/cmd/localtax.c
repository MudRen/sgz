// localtax.c 
// by fire on August 5, 1998
// updated on Aug 27,1998
void start(string arg)
{
        int p_tax,p_oldtax;
        string p_talk;
        int my_id,task_id;
        int* my_task;
	string p_id;
	string p_area1;
	p_id=this_body()->query_id()[0];
	p_area1=CHAR_D->get_char(p_id,"area");
        if((!arg)||(arg==""))
        {
                write("�÷���cmd localtax��˰��\n");
                write("���ӣ�cmd localtax 30\n");
                write("�� cmd help localtax�鿴��ϸ������\n");
                return;
        }
	if(((file_name(environment(this_body())))!=
((AREA_D->get_area(p_area1,"path"))+(AREA_D->get_area(p_area1,"meeting"))))||(p_area1!=
		environment(this_body())->get_area()))
	{
		write("�����������ڻ���֮�����ۡ�\n");
		return;
	}
        p_tax=to_int(arg);
        if((p_tax<10)||(p_tax>70))
        {
                write("˰�ʵ���Ч��Χ�ǣ�10 - 70\n");
                write("�� cmd help localtax �鿴��ϸ������\n");
                return;
        }
        my_id=this_body()->query_id()[0];
        if(!CHAR_D->get_char(my_id,"nation"))
        {
                write("������˸�һ�ٰ�ְ�Ժ��ٿ���˰������ɡ�\n");
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
                write("������⻹���ڵ���������̸�ɡ�\n");
                return;
        }
        task_id=my_task[0];
        if(TASK_D->get_task(task_id,"suggestion"))
        {
                write("�������������������⣬�������Ȼ����˵�ɡ�\n");
                return;
        }
        if(((TASK_D->get_task(task_id,"timaim")-
                TASK_D->get_task(task_id,"timer"))<3)&&
                (TASK_D->get_task(task_id,"stage")!=0))
        {
                write("ʱ�䲻���ˣ���ͷ����ɡ�\n");
                return;
        }
        p_oldtax=AREA_D->get_area(CHAR_D->get_char(my_id,
                "area"),"taxlocal");
        if(p_oldtax==p_tax)
        {
                printf("��ǰ˰������%d��\n",p_oldtax);
                return ;
        }
       if((p_tax-p_oldtax>20)||(p_oldtax-p_tax>20))
        {
                write("˰�ʵķ���һ�ε���̫���������նԳ��������ġ�\n");
                return;
        }
	if(p_tax>p_oldtax)
	{	string p_area;
		int p_safe;
		p_area=CHAR_D->get_char(my_id,"area");
		p_safe=AREA_D->get_area(p_area,"safe");
                if((p_safe<30)||((p_safe-(p_tax-p_oldtax)*2)<=30))
		{
			write("�����Ѿ����Ȳ����������˰�ʣ������𱩶�ѽ����\n");
			return;
		}
	}
        if(p_oldtax>p_tax)
                p_talk=sprintf
("$N������ǰ˰��%d���ߣ������ڰ��հ�����ҵ��$s��Ϊ˰����
����%d��������ڱ������ĳ��ξð���������λ���ˡ�������˼��\n",p_oldtax,p_tax);
        else
p_talk=sprintf
("$N������ǰ˰��%d���ͣ����µ����������㣬���Եֿ���ܡ�$s��Ϊ˰��������%d��
������ڱ������ĳ��ξð���������λ���ˡ�������˼��\n",p_oldtax,p_tax);
        this_body()->simple_action(p_talk);
        (EV_LOCALMEETING)->get_suggestion(task_id,my_id,"localtax",p_tax);
}
