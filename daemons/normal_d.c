// normal_d.c write by fire on 26 Dec. 1997
// daemons NORMAL_D
#include <sanguo.h>
inherit M_DAEMON_DATA;
inherit CHINESE_DA;
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
mixed get_monster(object who,string m_id)
{
	object env;
        env=environment(who);
	if(!objectp(env))
{
		return 0;
}
	if (env->is_horse())
	{
		env=environment(env);
	}
        foreach (object ob2 in all_inventory(env)) 
	{
                if((ob2->attackable())&&(member_array(m_id, ob2->query_id()) !=-1))
		{
			return ob2;
		}
		if(ob2->is_horse())
                foreach(object ob3 in all_inventory(ob2)) 
                        if((ob3->attackable())&&(member_array(m_id,ob3->query_id()) != -1))
			{
				return ob3;
			}
	}
      return 0;
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
string age_desc(object ob)
{
        int p_age;
        string p_head=ob->query_objective()+"����ȥ";
        string p_tmp;
       if(ob==this_body())
           return "";
        p_age=ob->query_age();
        if (p_age<10)
                p_head=p_head+"������ʮ�ꡣ\n";
        else
        {
                p_age=p_age/10;
                p_age=p_age*10;
                p_tmp="��"+chinese_number(p_age)+"���ꡣ\n";
                p_head=p_head+p_tmp;    
        }
        return p_head;
}
void remove_item_when_quit(object ob)
{
    if(!objectp(ob)) return;
    ob->put_m_all_money();
    foreach (object ob2 in all_inventory(ob)) {
	if (!ob2->query_is_keeping()) {
	    if (ob->query_link())
                ob->simple_action(
                "$NҪ�뿪����ʱ��������$o�ƺ��޷����ߣ����ǰ������ˡ�\n", ob2);
	    destruct(ob2);
	}
    }
}
string get_rongmao(int p_age,int p_rongmao, int p_gender )
{
        string p_res;
	int p_rand;
	if(p_rongmao==-1)
		return "";
        if(p_gender==1) // a male
        {
                if(p_age<20)
                {
                        if(p_rongmao<15)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "����С�ۣ�ͷ�����ң����������һ���޾���ɵ����ӡ�\n";
				else
					return "��ͷ������˫Ŀ���񣬿���ȥ������һ��ʮ��������ꡣ\n";
			}
			else if(p_rongmao<20)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "��ٻ������������ûʲô�ر�ĵط���\n";
				else
					return "��òƽƽ��һ�ۿ�ȥ�����������ʲôӡ��\n";
			}
			else if(p_rongmao<25)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "��ֱ�ڷ�����Ȼ̸����ʮ��Ӣ������Ҳ��һλ�������ꡣ\n";
				else
					return "��ٶ���������ȳƣ���Ȼ������ò���ڣ���Ҳ�㿡�ʡ�\n";
			}
		
			else
			{
				p_rand=random(2);
				if(p_rand)
	                                return "����ݰף����ͦ�Σ���һ��Ӣ�����꣡\n";
				else
					return "��Ŀ���ʣ���ɷ��ʵ��ͬ����֮���ߡ�\n";
			}
		}  // if(p_age<20)
		else if(p_age<40)
		{
                        if(p_rongmao<15)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "�������죬С�з��ۣ�����һ����ª�����ӡ�\n";
				else
					return "�����ģ���Ŀ���������˿��˲�ϲ����\n";
			}
			else if(p_rongmao<20)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "��òƽƽ��ûʲô�ر�ĵط���\n";
				else
					return "��òƽƽ��û��ʲô�����˵ĵط���\n";
			}
			else if(p_rongmao<25)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "��ٶ������䲻��Ӣ�����ˣ���Ҳ��ò���á�\n";
				else
					return "��ò���㿡�ʣ����Ҳ���ȳƣ�����Ͷ�㣬��Ȼ�Եá�\n";
			}
		
			else
			{
				p_rand=random(2);
				if(p_rand)
	                                return "�������£�Ŀ�����ǣ�����֮�䣬��ɷ��\n";
				else
					return "Ӣ���ޱȣ���ֹ���������ΰ��������������\n";
			}
		}
		else if(p_age<60)
		{
                        if(p_rongmao<15)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "���ۻ������״��ʺ�ʵ��������ޱȡ�\n";
				else
					return "��ò��ª��������ͣ�һ��û����ɵ����ӡ�\n";
			}
			else if(p_rongmao<20)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "��òһ�㣬ʵ��ûʲô���ڲ�ͬ�ġ�\n";
				else
					return "��ٻ����������������������ʲôӡ��\n";
			}
			else if(p_rongmao<25)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "�����Ƿ�������ɫ������һ�����Ȳ������������ӡ�\n";
				else
					return "��ٶ�������ͷ�ڷ���ֻ�����޴�������Щ��ɫ������һ�����ʡ�\n";
			}
		
			else
			{
				p_rand=random(2);
				if(p_rand)
	                                return "����Ӣ�������ͦ�Σ������뵽������ʱһ���������ټ��������ӡ�\n";
				else
					return "����ʮ�ֿ��ʣ�����΢΢��������ƾ�������أ�ʵ����Ӣ�����ˡ�\n";
			}
		}
		else 
		{
                        if(p_rongmao<15)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "������Ƥ��������֦����һ�ؿ��ɵ���ľ��\n";
				else
					return "��òƽƽ��û��ʲô�ر�ĵط���\n";
			}
			else if(p_rongmao<20)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "����ȥƽ�����棬��һ��ƽ�������ˡ�\n";
				else
					return "��ٻ����������������������ʲôӡ��\n";
			}
			else if(p_rongmao<25)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "�����Ƿ�������ɫ������һ�����Ȳ����ĳ��ߡ�\n";
				else
					return "��ٶ�������ͷ����������һ�����ʡ�\n";
			}
		
			else
			{
				p_rand=random(2);
				if(p_rand)
	                                return "����Ӣ�������ͦ�Σ������뵽������ʱһ���������ټ��������ӡ�\n";
				else
					return "����ʮ�ֿ��ʣ�����΢΢��������ƾ�������أ�ʵ����Ӣ�����ˡ�\n";
			}
		}
	}  //        if(p_gender==1) // a male
	else
        {
                if(p_age<20)
                {
                        if(p_rongmao<15)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "�����С��Ƥ����ڣ�û����Ը�⿴�ڶ��ۡ�\n";
				else
					return "���Ʒ��ڣ�����ϸ�ۣ�СС��;ͳ���һ�����ࡣ\n";
			}
			else if(p_rongmao<20)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "��òƽƽ��������������ر��ӡ��\n";
				else
					return "��ٻ��������ûʲô�ͱ��Ů����ͬ��\n";
			}
			else if(p_rongmao<25)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "��ü���ۣ�Ƥ������������ȥ���ò���\n";
				else
					return "��Ȼ����ò���绨����Ҳ���м�����ɫ��\n";
			}
		
			else
			{
				p_rand=random(2);
				if(p_rand)
	                                return "������������Ŀ���飬�������ޣ����ɷ��\n";
				else
					return "��̬��ȣ��������֣�СС����Ѿ�����ó������ˣ��Ҽ�������\n";
			}
		}  // if(p_age<20)
		else if(p_age<40)
		{
                        if(p_rongmao<15)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "������б��Ƥ���ֲڣ���һ����ª��Ů�ӡ�\n";
				else
					return "������ͣ���ٲ��������������Ҳ����żҡ�\n";
			}
			else if(p_rongmao<20)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "��òһ�㣬ʵ�ڳ���ƽ�����档\n";
				else
					return "��òƽƽ��û��ʲô�ͱ��Ů�Ӳ�ͬ�ĵط���\n";
			}
			else if(p_rongmao<25)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "�������㣬��̬�󷽣����м�����ɫ��\n";
				else
					return "ü��Ŀ�㣬��ֹ�󷽣�����ȥ������ζ��\n";
			}
		
			else
			{
				p_rand=random(2);
				if(p_rand)
	                                return "�г�������֮�ݣ������߻�֮ò���������˼����ӡ�\n";
				else
					return "������ī������ʤѩ����֪�㵹�˶���Ӣ�ۺ��ܡ�\n";
			}
		}
		else if(p_age<60)
		{
                        if(p_rongmao<15)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "��̬ӷ�ף���ٲ�������һ����ª�����긾Ů��\n";
				else
					return "��ò��ª���������ᣬû����Ը��࿴һ�ۡ�\n";
			}
			else if(p_rongmao<20)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "��òƽƽ������ȥʵ���ǳ���һ�㡣\n";
				else
					return "��ٻ��������������������أ�����ȥ�Ǹ�ƽ�������긾�ˡ�\n";
			}
			else if(p_rongmao<25)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "�����������㣬Ƥ���������������ʱһ�����ò���\n";
				else
					return "��Ȼ����΢�ף���������ϣ������̴档\n";
			}
		
			else
			{
				p_rand=random(2);
				if(p_rand)
	                                return "����毺ã�����ϸ�壬������������������ʵ���䡣\n";
				else
					return "����������üĿ���飬��̬�󷽣��������֡�\n";
			}
		}
		else 
		{
                        if(p_rongmao<15)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "������Ƥ��������֦����һ�ؿ��ɵ���ľ��\n";
				else
					return "��òƽƽ��û��ʲô�ر�ĵط���\n";
			}
			else if(p_rongmao<20)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "����ȥƽ�����棬��һ��ƽ������Ů�ˡ�\n";
				else
					return "��ٻ����������������������ʲôӡ��\n";
			}
		
			else
			{
					return "�����ٺã��վ����ˣ�����\n";
			}
               }
	}  //        if(p_gender==1) // a male
	return "";
}
