// emperor���˶�condition�Ŀ��ơ�2000.2.20
// write by fire on Dce 30 1997
// m_age.c 
#include <ansi.h>
#include <sanguo.h>
inherit __DIR__"m_age/condition";//emperor add

private static int is_grav;//emperor add ,��ֹ����BUG
private int ag_day,ag_month;

void set_ag_day(int i)
{
	ag_day=i;
}
void set_ag_month(int i)
{
	ag_month=i;
}
int query_ag_day()
{
	return ag_day;
}
int query_ag_month()
{
	return ag_month;
}
void age_beat()
{
	int p_year,p_shouming;
	ag_day++;
	if((ag_day>30)||(ag_day<0))
	{	ag_day=1;
		ag_month++;
	}
	if((ag_month>12)||(ag_month<0))
	{
		ag_month=1;
 		p_year=this_body()->query_age();
		p_year++;
		CHAR_D->set_char(this_body()->query_id()[0],"age",p_year);


		HP_D->set_max_hp(this_object());
		HP_D->set_max_mp(this_object());

		this_object()->set_age(p_year);
		tell(this_object(),"��ϲ�㣬�ֳ���һ�ꡣ\n");

		p_shouming=this_body()->query_shouming();
		if(p_year>=p_shouming)
		{
			write(HIR+"�������Ѿ����Ͽ�׼�����°ɡ�+NOR\n");
		}
	}

/* emperor add */
/*Ŀǰֻ����Ů��ɫ���п��ƣ�����������������Ŀ���*/
	if (is_grav)
		if(this_object()->query_gravidity()){
			update_condition();
		}
	else is_grav=1;
/* emperor add */

	call_out("age_beat",320);
	if(random(2)) {	
		this_object()->put_m_all_money();  // add by fire on Dec 13, 1997
		this_object()->save_me();
		tell(this_object(),"�洢��ϡ�\n");
	}
	"/sgdomain/home/funs/funs"->main(this_body()->query_primary_id());
}
void start_age()
{
	age_beat();
}

