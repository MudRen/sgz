#include <localtime.h>
// wartime.c
// by listen on Jan 1, 2002


void start(string arg)
{
	int today, tomorrow,war_status;
	int t_time1,t_time2,m_time1,m_time2;
	int next, temp, n_hour, n_min; 
	int *now;
	int shift;
	
	today = localtime(time())[LT_WDAY];
	tomorrow = localtime(time()+24*3600)[LT_WDAY];

	
	if (!DAY_D->get_can_war())
        {
		write("%^H_RED%^&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%^RESET%^\n");
    		write("\n%^H_YELLOW%^���׵�%^H_CYAN%^گ�ͣ�\n\n    �޹�֮��������ս��
    			���������������к���֮�£���˳Ӧ\n��ʱ�������¸�·���%^H_MAGENTA%^"+
 			CHINESE_D->chinese_period(DAY_D->get_change_time())+
 			 "%^H_CYAN%^�ڲ�����ս��\n\n                                                   �մ�%^RESET%^\n\n");
		write("%^H_RED%^&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%^RESET%^\n");
	}
//	else
//		write("����ս����������.\n");

        if((!arg)||(arg==""))
        {

                write("���� cmd wartime <nation_id> ����ѯ������ҵ�ս������ʱ�䡣\n");
                write("���ӣ�cmd wartime liu bei ��ѯ��������ս������ʱ�䡣\n");
                //write("�� help wartime �鿴��ϸ������\n");
                return;
        }
        
        if ( !COUNTRY_D->nation_exist(arg))
        {
        	write("û��" + arg + "������ң�����info n ����ѯ�����б�\n");
        	return;
        }
        war_status = DAY_D->war_status(arg);
	t_time1 = COUNTRY_D->get_wartime(arg,today*2);
	t_time2 = COUNTRY_D->get_wartime(arg,today*2+1);
	m_time1 = COUNTRY_D->get_wartime(arg,tomorrow*2);
	m_time2 = COUNTRY_D->get_wartime(arg,tomorrow*2+1);
        write ("ϵͳ��ǰʱ��Ϊ " + DAY_D->English_time(time()) + "��\n");
        now = localtime(time());
        n_hour = now[LT_HOUR];
        n_min = now[LT_MIN];
        shift = now[LT_GMTOFF]/3600;
        write (COUNTRY_D->get_country_name(arg) + "ս������ʱ������:\n");
        write ("����: " + t_time1 + ":00-" + t_time1 +":59 �Լ� " + t_time2 + ":00-" + t_time2 + ":59��\n");
        write ("����: " + m_time1 + ":00-" + m_time1 +":59 �Լ� " + m_time2 + ":00-" + m_time2 + ":59��\n");
        write ("����ʱ��Ϊ24Сʱ��ϵͳ����ʱ��(GMT -" + shift + ")��\n");
        if (war_status == 2)
        {
        	write ("��ǰ״̬: %^H_YELLOW%^���׵۽�ֹ���е�ս��%^RESET%^\n");
        	return;
        }
        else if (war_status == 1)
        {
        	write ("��ǰ״̬����" + COUNTRY_D->get_country_name(arg)
        		+ "��ս��%^H_CYAN%^�ر�%^RESET%^�С�\n");
        	//�ҳ���ӽ���war time ʱ��
        	//�Ȳ鿴����
        	if (t_time1 > t_time2)
        	{
        		temp = t_time1;
        		t_time1 = t_time2;
        		t_time2 = temp;
        	}
        	if ( n_hour < t_time1 )
        		next = t_time1*3600 - n_hour*3600 - n_min*60;
        	else if (n_hour < t_time2)
        		next = t_time2*3600 - n_hour*3600 - n_min*60;
        	//�ٲ鿴����
        	else
        	{
        		if (m_time1 < m_time2 )
        			next = (24 + m_time1)*3600 - n_hour*3600 - n_min*60;
        		else
        			next = (24 + m_time2)*3600 - n_hour*3600 - n_min*60;
        	}
        	write ("���������" + COUNTRY_D->get_country_name(arg) + "ս������ʱ�仹��: %^H_YELLOW%^"
        		+ CHINESE_D->chinese_period(next) + "%^RESET%^\n");
        }
        else if (war_status == 0)
        {
        	temp = DAY_D->get_temp_wartime (arg);
        	
        	write ("��ǰ״̬: ��" + COUNTRY_D->get_country_name(arg)
        			+ "��ս��%^H_RED%^����%^RESET%^�С�\n");
        	if ( temp > 0)
        		write ("ս������ʱ�仹��: %^H_YELLOW%^" + CHINESE_D->chinese_period(temp)
        			+ "%^RESET%^\n");
        	else if ( t_time1 == (n_hour+1) || t_time2 == (n_hour+1)) //�������wartime ʱ����������
        		write ("ս������ʱ�仹��: %^H_YELLOW%^" + CHINESE_D->chinese_period((120-n_min)*60)
        			+ "%^RESET%^\n");
        	else
        		write ("ս�����ų���ʱ�仹��: %^H_YELLOW%^" + CHINESE_D->chinese_period((60-n_min)*60)
        			+ "%^RESET%^\n");
        }
        else
        	write ("�뱨����ʦ,wartime.c �� BUG!\n");
}