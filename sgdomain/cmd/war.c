// war.c 
// by fire on August 5, 1998
// updated on Aug 27,1998
// modified by listen on Jan 13, 2002 for upgrade war time system

void start(string arg)
{
        string p_talk;
        int my_id,task_id,p_safe;
        int* my_task;
        int war_status;
        string m_nation,t_nation,m_area,*neighbor;
	string p_id;
	string p_area1;
	p_id=this_body()->query_id()[0];
	p_area1=CHAR_D->get_char(p_id,"area");


        if((!arg)||(arg==""))
        {
                write("�÷���cmd war <area_id>\n");
                write("���ӣ�cmd war luoyang\n");
                // write("���ӣ�cmd war time �鿴Ŀǰ�Ƿ���Կ�ս�����״̬ʲôʱ��ı䡣\n ");
                write("�� help war �鿴��ϸ������\n");
                return;
        }

/*
        if( !wizardp(this_body()) ){

                if(DAY_D->get_can_war()==0) {
    write("%^H_RED%^&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%^RESET%^\n");
    write(
"\n%^H_YELLOW%^���׵�%^H_CYAN%^گ�ͣ�\n\n    �޹�֮��������ս�����������������к���֮�£���˳Ӧ
��ʱ�������¸�·���%^H_MAGENTA%^"+
 CHINESE_D->chinese_period(DAY_D->get_change_time())+
 "%^H_CYAN%^�ڲ�����ս��\n\n                                                   �մ�%^RESET%^\n\n");
    write("%^H_RED%^&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%^RESET%^\n");
                        return;
                }
        else{
        write("%^H_RED%^&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%^RESET%^\n");
        write("\n%^H_YELLOW%^���׵�%^H_CYAN%^گ�ͣ�\n\n    �޵����˹�����֪�����´��ң����˺��У����ذ��ղ��ð�����
����·�������������԰����ġ��޳���%^H_MAGENTA%^������󣬺�ս������%^H_CYAN%^����
������Ϊ֪���ʿɶ�ֹ��%^RESET%^\n");
        write("\n%^H_CYAN%^                                                       �մ�%^RESET%^\n\n");
        write("%^H_RED%^&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%^RESET%^\n");
//                return;
                } 
        }
        if(arg=="time"&&DAY_D->get_can_war()==0) {
                write("���´�ս������ʱ�䣺"+ 
                CHINESE_D->chinese_period(DAY_D->get_change_time())+"��\n");
                return ;
                }
        if(arg=="time"&&DAY_D->get_can_war()==1){
                write("ս�����ų���ʱ�䣺"+
                CHINESE_D->chinese_period(DAY_D->get_change_time())+"��\n");
                return;
        }
*/
//old war time system end
//Listen add for new war time system
	my_id=this_body()->query_id()[0];
	my_task = TASK_D->get_char_task(my_id);
	task_id=my_task[0];
	m_nation=CHAR_D->get_char(my_id,"nation");
        t_nation=AREA_D->get_area(arg,"nation");
        m_area=CHAR_D->get_char(my_id,"area");
        if(!CHAR_D->get_char(my_id,"nation"))
        {
               	write("������˸�һ�ٰ�ְ�Ժ��������ǳ���������ɡ�\n");
               	return;
        }
        	        
        if(my_task[1]!=TT_LOCALMEETING)
        {
               	write("������⻹�ǵ���������̸�ɡ�\n");
               	return;
        }
	if(((file_name(environment(this_body())))!=
	((AREA_D->get_area(p_area1,"path"))+(AREA_D->get_area(p_area1,"meeting"))))
	||(p_area1!= environment(this_body())->get_area()))
	{
		write("�����������ڻ���֮�����ۡ�\n");
		return;
	}
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
        if(!AREA_D->area_exist(arg)) 
        {
        	write("û�����������\n");
                return;
        }
	if( !wizardp(this_body()) )
	{
        	if((CHAR_D->get_char(my_id,"level")<3))
        	{
                	write("��Ĺ�ְ̫�ͣ����ܽ��������\n");
                	return;
        	}
         
                if (CHAR_D->get_char(m_nation,"type")==TYPE_NPC) //��ֹnpc���ҵ�����ڶ���ǰ����ս��
                {                                             //2001.4.19��ֹ��Ҷ�������NPC���ұ���
                	write("������������Χ���ǻ���֮�������׳������������Ա�Ϊ�ϣ�\n");
                 	return;
                }

                if(m_nation==t_nation) 
                {
                        write(AREA_D->get_area(arg,"name")+"�˱������������ɳ�������\n");
                        return;
                }
	
                
                if(sizeof(AREA_D->check_area("nation",t_nation))==0
			&& CHAR_D->get_char(t_nation,"type")) 
		{
                        write(AREA_D->get_area(arg,"name")+
                               "��"+COUNTRY_D->get_country(t_nation,"name")+
                               "���һ�����أ����ڲ���Ͼ�ɱ����\n");
                        return;
		}

//Listen add for new war time system
		war_status = DAY_D->war_status(t_nation);
		if ( war_status == 2 )
		{
			write("%^H_RED%^&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%^RESET%^\n");
    			write("\n%^H_YELLOW%^���׵�%^H_CYAN%^گ�ͣ�\n\n    �޹�֮��������ս��
    				���������������к���֮�£���˳Ӧ\n��ʱ�������¸�·���%^H_MAGENTA%^"+
 				CHINESE_D->chinese_period(DAY_D->get_change_time())+
 				 "%^H_CYAN%^�ڲ�����ս��\n\n                                                   �մ�%^RESET%^\n\n");
			write("%^H_RED%^&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%^RESET%^\n");
			return;
		}
		if ( war_status == 1 )
		{
			write("�з���������������ӣ�ʱ�����ԣ����˳�����\n");
			write("���� cmd wartime <�з�����ID> �鿴����ʱ��. \n");
			return;
		}
                p_safe=AREA_D->get_area(m_area,"safe");
                if(p_safe<100)
                {
                        write("�˵�����δ�ȣ���ʱ���������\n");
                        return;
                }

                p_safe=AREA_D->get_area(m_area,"morale");
                if(p_safe<100)
                {
                        write("Ŀǰ��ʿȫ�޶�־������ܳ�����\n");
                        return;
                }

                p_safe=AREA_D->get_area(m_area,"train");
                if(p_safe<100)
                {
                        write("Ŀǰ��ʿѵ�����㣬����ܳ�����\n");
                        return;
                }

                p_safe=AREA_D->get_area(m_area,"soldier");
                if(p_safe<1000*AREA_D->get_area(arg,"level"))
                {
                        write("���ر�ʿ�������㣬�Ա������ף�����ܳ�����\n");
                        return;
                }
	}
	neighbor=AREA_D->get_area(m_area,"neighbor");
        if(member_array(arg,neighbor)==-1) 
        {
        	write(AREA_D->get_area(arg,"name")+
                      "�뱾�ز������ڣ��޷�������\n");
                return;
         }

         p_talk=CHAR_D->get_char(t_nation,"name")+
                        "���в��壬������˥����$s֮���������ǳ���������Ĵ��ʱ����\n"+
                        "$s��Ϊ���������٣�����������"+
         AREA_D->get_area(arg,"name")+"���������ɹ���\n";
	
         this_body()->simple_action(p_talk);
         (EV_LOCALMEETING)->get_suggestion(task_id,my_id,"war",arg);
}

