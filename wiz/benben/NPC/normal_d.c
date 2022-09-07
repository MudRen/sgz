// normal_d.c write by fire on 26 Dec. 1997
// daemons NORMAL_D
#include <sanguo.h>
inherit M_DAEMON_DATA;
int query_money_value(int number,string str)
{
	if ((number<0)||(number>1000000))
		return 0;
	switch(str)
	{
		case "coin" :
			return number;
		case "silver" :
			return number*100;
		case "gold" :
			return number*10000;
		default :
			return 0;
	}
}
string get_dis1(int p_age, int p_gender)
{
	string p_tmp;
	int pp_age;
	pp_age=p_age/10;
	switch(pp_age)
	{
		case 0:
			p_tmp="��ͯ";
			break;
		case 1:
			p_tmp="����";
			break;
		case 2:
			p_tmp="����";
			break;
		case 3: 
			p_tmp="����";
			break;
		case 4:
			p_tmp="����";
			break;
		case 5:
		case 6:
			p_tmp="׳��";
			if(p_gender==2)
				p_tmp="����";
			break;
		default :
			p_tmp="����";
	}
	switch(p_gender)
	{
		case 1:
			p_tmp=p_tmp+"����";
			break;
		case 2:
			p_tmp=p_tmp+"Ů��";
			break;
		default :
			p_tmp=p_tmp+"������";
	}
       return p_tmp;
}
string get_rongmao(int p_age,int p_rongmao, int p_gender )
{
	string p_res;
	if(p_gender==1) // a male
	{
		if(p_rongmao>20)
		{
			if(p_age>20)
                                return "������ͬ���еİ������ӡ�\n";
			else
			{
				if(random(2))
                                        return "��һ�����ε�С�к���\n";


				else
                                        return "����ȥ�ɰ��ֵ�Ƥ��\n";
			}
		}
		else
		{
			if(p_age>20)
                                return "������һ��ɱ��ġ�\n";
			else
			{
				if(random(2))
                                        return "��һ����С�ӡ�\n";
				else
                                        return "����ȥ���������ҵ�ϱ����\n";

			}
		}
	}
	else // for female
	{
		if(p_rongmao>20)
                        return "����ȥ�����Ů��\n";
                return "��һ����òƽӹ��Ů�ˡ�\n";
	}
}
