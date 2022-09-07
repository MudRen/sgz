//*******************************************************************
// m_dangpu.c  by fire on Dec 16, 1997
// ����ģ��
// modified by fire on Sep 16,1998
#include <mudlib.h>
#include <clean_up.h>
#include <move.h>
#include <sanguo.h>

inherit ROOM;
inherit CHINESE_DA;

private mixed m_items = ([]);

//! ���һ�£�������������᲻�����ֽ�̫�������
private mixed can_sell( string par_strItem, int par_nNum );

void add_object(object ob) 
{
    string item_name;
    string item_unit;
    string *object_ids;
    int object_value;
    int ob_value;            
    string f_name;
    f_name=base_name(ob);
    if(m_items[f_name])  // already has this stuff
    {
	m_items[f_name]["quantity"]++;
    }
    else
    {
	m_items[f_name]=([]);
	m_items[f_name]["quantity"]=1;
	m_items[f_name]["value"]=ob->query_absolutevalue();
	m_items[f_name]["name"]= ob->short();
	m_items[f_name]["ids"]=ob->query_id();
	m_items[f_name]["ids"]+=({ ob->short() });
        item_unit=ob->query_unit();
	m_items[f_name]["unit"]=ob->query_unit();
    }
    destruct(ob);
}
void list_item()
{
        int j,m;
        int *p_tmp;
        string * p_ttt;
        int *p_val;
        int ppp;
	string *keys;
	keys=keys(m_items);
        j = sizeof(m_items);
        if(j == 0)
        {
                write("������Ŀǰ�����κδ����\n");
                return;
        }
        else
        {
                write("�������������д����\n
-----------------------------------------------------------------\n");
printf("          ��������            �������         ����\n");
                for( m=0; m < j; m++)
                {
                        ppp=m_items[keys[m]]["value"];
                        ppp = ppp * SALERATE;
                        printf("%20s          %s    %s",m_items[keys[m]]["name"],
                                         "��ʣ"+chinese_number(m_items[keys[m]]["quantity"])+m_items[keys[m]]["unit"] ,
                         chinese_value(ppp) );
                }
                printf(
"-----------------------------------------------------------------\n������
�����ʲô��������ʲô��\n");
        }
}
void buy_sthing(string p_fullid)
{
        int i;
        string *p_tmp;
        int p_itemnum;
        int p_buyersmoney, p_itemvalue;
        object *obs,ob;
        string p_itemid;
        p_buyersmoney=this_body()->query_all_con_money();
	ob=new(p_fullid);
        p_itemvalue=ob->query_absolutevalue();
        p_itemvalue = p_itemvalue *  SALERATE;
        if (p_itemvalue > p_buyersmoney)
        {
                write("���Ǯ����û����ѽ��\n");
		destruct(ob);
                return;
	}
        if((ob->move(this_body())) == MOVE_OK)
        {               
                this_body()->simple_action("$N�ڴ���������һ"+
                ob->query_unit()+ob->short()+"��\n"); 
                this_body()->set_all_con_money(p_buyersmoney - p_itemvalue);
		m_items[p_fullid]["quantity"]--;
		if(m_items[p_fullid]["quantity"]<=0)
		     map_delete( m_items, p_fullid );
		ob->set_buyer(this_body()->query_primary_id());
                return;
        }
        else
        {
                write("�����ò����ˡ�\n");
		destruct(ob);
                return;
	}
}
void buy_sth(string item, int number)
{
    int p_items,i;
    int p_objfind=0;
    string *for_sale_ids;
    string *keys;
    string f_name;
    int j=0;
    p_items = sizeof(m_items);
    if (!number)
    {
        number = 1;
    }
    if(!p_items)
    {
        write("Ŀǰ����û�д��������\n");
        return;
    }
    keys=keys(m_items);
    
    for(i=0 ; i<p_items ; ++i)
    {
        for_sale_ids = m_items[keys[i]]["ids"];
        if(member_array(item, for_sale_ids) != -1)
        {
             j += 1;
             if (j == number)
             {
		    f_name=keys[i];
                    p_objfind=1;
                    break;
             }  
        }
    }
    if(!p_objfind)
    {
        write("��Ҫ�Ķ����������û��ѽ��\n");
        return;
    }
    buy_sthing(f_name);
    return;
}
void sell_sth( string item, int number)
{
        mixed contents;
        mixed ss;
        object ob;
        int p_itemnum;  
        int i,j;
        int p_findobj=0;
        int p_value;
        int p_buyersmoney;
        int nTotalMoney;
        
        p_buyersmoney=this_body()->query_all_con_money();
        contents = all_inventory(this_body());
        p_itemnum = sizeof(contents);
        if(!p_itemnum)
        {
                write("���ˣ������һ������ѽ��\n");
        }
        j=0;
        for(i=0;i<p_itemnum;++i)
        {
                ob=contents[i];
                ss=ob->query_id();
                if(member_array(item, ss) != -1)
                {
                        j++;
                        if(j==number)
                        {
                                p_findobj=1;
                                break;
                        }
                }
        }
        if(!p_findobj)
        {
                write("�㵽��Ҫ��ʲô��������㡣\n");
                return;
        }
        
        p_value=ob->query_absolutevalue();
        
        if(!p_value)
        // ��Ʒû�м�
        {
                write("���ֶ������̲��ա�\n");
                return;
        }
		else
		{
			string oldbuyer;
			oldbuyer=ob->get_buyer();
			
			if(oldbuyer==this_body()->query_primary_id())
			{
				p_value=ob->query_absolutevalue()*BUYSELLRATE;
			}
			else if ( sizeof(oldbuyer) > 0 )
			{
				write("������·�����������̲��ա�\n");
				return;
			}
			else
			{        
                if( (p_value<0)||(p_value>10000) )
        		{
        			write("�����޼�֮����������С�������յ���\n");
                    return;
        	    }
				
				p_value = p_value *  BUYRATE;
            }
        }
        
        // xiaobai: 25 Oct., 2001, �����궫������Ǯ���᲻�����
        nTotalMoney = MONEY_D->get_all_money(this_body()) + p_value;
        
        if ( nTotalMoney > 50000000 )
        // ��Ǯ�����ᳬ�� 5000 gold ��
        {
            write( "�����Ǹ�̰�ĵļһ��ĲƲ��Ѿ�������ǧ�����ˡ�\n" );
            write( "����һ����ʱ�����������β������������ˡ�\n" );
//            return;
        }
        
        this_body()->set_all_con_money(p_buyersmoney + p_value);
        this_body()->simple_action("$N�ڴ�������һ"+
                ob->query_unit()+ob->short()+"������"+
                chinese_value(p_value)); 
        add_object(ob) ;
        return;
}

mixed buy(string item, int number)
{
        buy_sth(item,number);
        return 1;
}       
mixed sell(string item, int number)
{
        sell_sth(item, number);
        return 1;
}
mixed list()
{
        list_item();
        return 1;
}
int clean_up(){ return NEVER_AGAIN;}
int is_dangpu() { return 1;}
