// localmeeting.c 
// by fire on August 4, 1998
#include <localmeeting.h>
void start(string arg)
{
	string p_id,p_leader;
	string p_area;
//	string p_room;
	mixed p_auth;
	int p_res;
	int m_auth=1;
	p_id=this_body()->query_id()[0];
	p_area=CHAR_D->get_char(p_id,"area");
	p_leader=AREA_D->get_area(p_area,"leader");
	if(p_id!=p_leader)  // not the leader
	{
		p_auth=CHAR_D->get_char(p_id,"auth");
		if(!p_auth)
			m_auth=0;
		else
		{
			if(!p_auth["localmeeting"])
				m_auth=0;
			else
			{
				if((p_auth["localmeeting"]["leader"]!=p_leader)||
				   (p_auth["localmeeting"]["area"]!=p_area))
					m_auth=0;
			}
		}
	}
	if(!m_auth)
	{
		write("ֻ�еط�����ͱ���Ȩ�ĵط��ٲ����´�����\n");
		write("��Ҳ������ask <�ط�����> about localmeeting �ķ�ʽ�����ٿ��������顣\n");
		return;
	}
		if(((file_name(environment(this_body())))!=
((AREA_D->get_area(p_area,"path"))+(AREA_D->get_area(p_area,"meeting"))))||(p_area!=
		environment(this_body())->get_area()))
	{
		write("�˴��ǻ���֮����\n");
		return;
	}
	p_res=(EV_LOCALMEETING)->can_lmeeting(p_area);
	switch(p_res)
	{
        case LM_OK:
            (EV_LOCALMEETING)->local_meeting(p_area);
            return;
        case LM_OTHERTASK:
	    write("̫��������æ���أ��ֲ�����\n");
         return;
        case LM_ALREADYLOCALMEETING:
	    write("��������æ��Ϳ�ˣ��ⲻ���������鱾����������\n");
         return;
        case LM_NOENOUTHCHAR :
	    write("�ܹ�û���ˣ���ʲô��ѽ����\n");
         return;
        case LM_TOOMANYABSENT:
          write("��Ҷ�̫æ����������ֻ�ø����ˡ�\n");
         return;
        }
}
