// judge.c
// by fire on Aug 07, 1998
void suggestion_pass(int task_id);
void dis_over(int task_id);
string get_problem(int task_id);
int query_group_value(string *g)
{
        int i,sum;
        string p_id;
        int p_l1,p_l2;
        int p_ret=0;    
        sum=sizeof(g);
        for(i=0;i<sum;++i)
        {
                p_id=g[i];
                p_l1=OFFICER_D->query_level(CHAR_D->get_char(p_id,"ranklocal"));
		p_l2=OFFICER_D->query_level(CHAR_D->get_char(p_id,"ranknation"));
		if(p_l2>p_l1)
        		p_l1=p_l2;
	        p_ret+=(p_l1+2)/3;
        }
        return p_ret;
}
int* get_score(int task_id)
{
        string *ag,*dg,*ng,*chars;
        int i,sum;
        int n_all,n_agree,n_disagree,n_nutual;
        chars=keys(TASK_D->get_task(task_id,"chars"));
        ag=TASK_D->get_task(task_id,"supportgrp");
        dg=TASK_D->get_task(task_id,"againstgrp");
        ng=TASK_D->get_task(task_id,"neutalgrp");
        n_all=query_group_value(chars);
        n_agree=query_group_value(ag);
        n_disagree=query_group_value(dg);
        n_nutual=query_group_value(ng);
        return ({n_all,n_agree,n_disagree,n_nutual});
}
void begin_judge(int task_id)
{
        string p_suggestion;
        string p_leader;
        object o_leader;
        string p_disp;
        int *p_score;
        p_suggestion=TASK_D->get_task(task_id,"suggestion");
        p_score=get_score(task_id);
        p_leader=AREA_D->get_area(
                TASK_D->get_task(task_id,"area"),"leader");
        if(p_score[0]>(p_score[1]+p_score[2]+p_score[3]))
                p_disp=sprintf
("$N����������%d��֧�֣�%d�㷴�ԣ�%d�����������⻹��%d��û�б�̬��",
p_score[1],p_score[2],p_score[3],p_score[0]-(p_score[1]+p_score[2]+p_score
[3]));
        else
                p_disp=sprintf
("$N����������%d��֧�֣�%d�㷴�ԣ�%d��������",p_score[1],p_score[2],p_score[3]);
        o_leader=CHAR_D->find_char(p_leader);
        if(objectp(o_leader))
                o_leader->simple_action(p_disp);
        
	if((p_score[1]*2+p_score[3])>p_score[0]) // over half
	{
		suggestion_pass(task_id);
		return ;
	}
	if((p_score[1]*2+p_score[3]+2*(p_score[0]-p_score[1]
		-p_score[2]-p_score[3]))<=p_score[0]) // can't pass half
	{
              if(objectp(p_leader))
              o_leader->simple_action
("$N��������"+get_problem(task_id)+"�����⣬���쿴���޷�����ͨ�������Ǹ�����̸��\n");
		{
			string my_id;
			object my_ob;
			int my_reputation,my_loyalty;
			my_id=TASK_D->get_task(task_id,"suggestionppl");
			my_reputation=CHAR_D->get_char(my_id,"reputation");
			my_loyalty=CHAR_D->get_char(my_id,"loyalty");
			if(my_reputation>50000) my_reputation -= 1000;
			else 

			my_reputation=my_reputation*49/50;
			my_loyalty-=3;
			if(my_loyalty<0)
				my_loyalty=0;
			CHAR_D->set_char(my_id,"reputation",my_reputation);
			CHAR_D->set_char(my_id,"loyalty",my_loyalty);
			my_ob=CHAR_D->find_char(my_id);
			if(objectp(my_ob))
				my_ob->simple_action
("$N�Ľ���û�б�ͨ����$N���������ҳ��½��ˡ�\n");
	
		}
                dis_over(task_id);
	}
}
