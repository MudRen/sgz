// party.c 
// by group on 25 Nov, 1998
#include <mudlib.h>
#include <party.h>

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
		write("ֻ�еط�����ͱ���Ȩ�ĵط��ٲ����´�����\n");
		return;
	}
		if(((file_name(environment(this_body())))!=
((AREA_D->get_area(p_area,"path"))+(AREA_D->get_area(p_area,"meeting"))))||(p_area!=
		environment(this_body())->get_area()))
	{
		write("�˴������֮����\n");
		return;
	}
	p_res=(EV_PARTY)->can_party(p_area);
	switch(p_res)
	{
        case PT_OK:
            (EV_PARTY)->party(p_area);
            return;
        case PT_OTHERTASK:
	    write("̫��������æ���أ��ֲ�����\n");
         return;
        case PT_ALREADYPARTY:
	    write("��������æ��Ϳ�ˣ��ⲻ�����ڿ������\n");
         return;
	case PT_NOMONEY:
	    write ("Ǯ�������ɿ�������ᡣ\n");
	 return;	
	case PT_TIME:
	    write ("ֻ��ÿ��һ�»�����һ�������ղſ��Կ���ᡣ\n");
	    return;
        case PT_NOENOUTHCHAR :
	    write("�ܹ�û���ˣ���ʲô���ѽ����\n");
         return;
        case PT_TOOMANYABSENT:
          write("��Ҷ�̫æ���������ֻ�ø����ˡ�\n");
         return;
        }
}
