// resign.c 
// by row on May 29, 1999
// used for player char to risign a job
#include <ansi.h>
string job_id;
string job_memo1;
void confirm_resign(mixed p_input)
{
	string p_id;
	int rep,cut_rep;
	p_id=this_object()->query_id()[0];
	cut_rep=random(50);
	if(p_input=="yes")
	{
	if( !COUNTRY_D->nation_exist(CHAR_D->get_char(p_id,"nation")) )
	{
	this_user()->finish_job(job_id);
	write("���������""HIY"+job_memo1+"�Ĺ�����\n");
	return;
	}
	rep=CHAR_D->get_char(p_id,"reputation");
	
if ((rep-cut_rep)<10)
	{
	write("���������""HIY"+job_memo1+"�Ĺ�����\n");
	return;
	}
	rep=rep-cut_rep;
	write("���������""HIY"+job_memo1+"�Ĺ�����\n");
	write("��������½���"+chinese_number(rep)+"�㡣\n");
	return;
	}
	else
	write("�����ǲ�����������ѽ��\n");
	this_user()->modal_pop();
	return; 
}
void start(string arg)
{
	string job_id,job_memo;
	int beg_time,time;
	time=time();
	if((!arg)||(arg==""))
	{
	write("�÷�: cmd resign <job_id>\n");
	write("���ӣ�cmd resign whisper (�����߷��н��Ĺ���)\n");
	return;
	}
	beg_time=this_user()->query_job(arg,"beg_time");
	if (beg_time=0)
	{
	write("�㲢û������������\n");
	return;
	}
	job_memo=this_user()->query_job(arg,"memo");
	job_memo1=job_memo;
	job_id=arg;
	if ((time-beg_time)/60<5)
	{
	write("��ողŽ��ܹ����������������ٿ��Ƿ����ɡ�\n");
	return;
	}
	else
	{
	write("�������Ҫ����""HIY"+job_memo+"NOR""������𣿣�������һ����ʧ��\nȷ��������yes��������س����˳���\n");
	this_user()->modal_push((: confirm_resign :),"",0,0);
	}
}
