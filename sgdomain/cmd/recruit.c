// recruit.c
// by fire on August 5, 1998
void start(string arg)
{
        int p_soldier;
	int p_population,p_tmp;
        string p_talk, type;
        int my_id,task_id;
        int* my_task;
	mapping troop;
	string p_id;
	string p_area1;
	p_id=this_body()->query_id()[0];
	p_area1=CHAR_D->get_char(p_id,"area");

        if( (!arg)||(arg=="") ){
                write("�÷���cmd recruit��ʿ����\n");
                write("���ӣ�cmd recruit 100   ��һ��ʿ��\n");
                write("���ӣ�cmd recruit -200 footman �ö����±�\n");
                write("�� cmd help recruit �鿴��ϸ������\n");
        	write("��ϸ����������help trooptype.\n");        
	return;
        }
	if( sscanf(arg, "%d %s", p_soldier, type) != 2 )p_soldier=to_int(arg);
        if( p_soldier<50 && p_soldier>-50){
                write("������ñ�������С��50��\n");
                write("�� cmd help recruit �鿴��ϸ������\n");
                return;
        }
        if( (stringp(type)&&p_soldier>0)||(!stringp(type)&&p_soldier<0) ){
                write("�÷���cmd recruit��ʿ����\n");
                write("���ӣ�cmd recruit 100   ��һ��ʿ��\n");
		write("���ӣ�cmd recruit -200 footman �ö����±�\n");
		return;
	}
        my_id = this_body()->query_id()[0];
        if( !CHAR_D->get_char(my_id,"nation") ){
                write("������˸�һ�ٰ�ְ�Ժ��ٿ��������ñ�������ɡ�\n");
                return;
        }

        if((CHAR_D->get_char(my_id,"level")<3)&&(p_soldier<0))
        {
                write("��Ĺ�ְ̫�ͣ����ܽ���ñ���\n");
                return;
        }

        if((CHAR_D->get_char(my_id,"level")<2)&&(p_soldier>0))
        {
                write("��Ĺ�ְ̫�ͣ����ܽ���������\n");
                return;
        }

        my_task = TASK_D->get_char_task(my_id);
        if( my_task[1] != TT_LOCALMEETING ){
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
        task_id = my_task[0];
        if( TASK_D->get_task(task_id,"suggestion") ){
                write("���������������������⣬�������Ȼ����˵�ɡ�\n");
                return;
        }
        if( ((TASK_D->get_task(task_id,"timaim")-
                TASK_D->get_task(task_id,"timer"))<3)&&
                (TASK_D->get_task(task_id,"stage")!=0)){
                write("ʱ�䲻���ˣ���ͷ����ɡ�\n");
                return;
        }
        if( (PJOB+"recruit/recruit")->get_recruit_left(my_id)>0 ){
            	int p_left = (PJOB+"recruit/recruit")->get_recruit_left(my_id);
            	printf("����������񻹲�%s��ʿ��û����ɡ�\n", chinese_number(p_left));
            	return;
        }

	if( p_soldier < 0 ){
		write("ͳһȫ���������Ҳ��㣬��ô�ܾʹ����ײñ��أ�\n");//2001.4.13
		return;

		troop = AREA_D->get_area(CHAR_D->get_char(my_id,"area"),"troop");
		if( !mapp(troop) ) troop = ([ ]);
		if( member_array(type, keys(troop)) == -1 ){
			write("û��"+type+"���־��ӡ�\n");
			return;
		}
		if( troop[type] + p_soldier < 0 ){
			write(""+type+"����û����û���ˡ�\n");
			return;
		};
	}
	p_population=AREA_D->get_area(CHAR_D->get_char(my_id,"area"),"population");
	p_tmp=bmin(p_population*4/100,500);
        if(p_soldier>p_tmp){
                printf("��ǰ�����������%d��\n",p_tmp);
                return ;
        }
	if(p_soldier>0){
		if(AREA_D->get_area(CHAR_D->get_char(my_id,"area"),"safe")<10){
			write("�����Ѿ����Ȳ������������������𱩶�������\n");
			return;
		}
	}
        if(p_soldier>0){
                p_talk=sprintf("$N�������ر�ʿ�ѷ����ѱ����հ�����ҵ��$s��Ϊ����
			����%d���Ա�֤�������ĳ��ξð���������λ���ˡ�������˼��\n",p_soldier);
		(EV_LOCALMEETING)->get_suggestion(task_id,my_id,"recruit",p_soldier);
	}
        else {
		p_talk=sprintf("$N��������%s��ʿ���㣬$s��Ϊ�˲ñ�%d���������������
			�����ڱ������ķ��ٲ�ʢ��������λ���ˡ�������˼��\n",WARAI_D->query_type(type, "name"),(-1*p_soldier));
		(EV_LOCALMEETING)->get_suggestion(task_id,my_id,"recruit",
			(["no":p_soldier, "type":type]));
	}
        this_body()->simple_action(p_talk);
}
