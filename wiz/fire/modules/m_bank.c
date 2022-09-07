//**********************************************************************
// m_bank.c  by fire on Dec 14 1997  
#include <mudlib.h>
#include <move.h>
#include <sanguo.h>
inherit CHINESE_DA;
void deposit_sth(string item, int number)
{
    int p_buyersmoney;
    int p_itemvalue;
    int n_bank;
    string p_act;
    if(number<1)
    {
	write("���ѣ���ɶ�أ�\n");
	return;
    }
    switch(item)
    {
	case "coin" :
		p_itemvalue=number;
                p_act="��Ǯ";
		break;
	case "silver" :
		p_itemvalue=number*100;
  		p_act="������";
		break;
	case "gold" :
		p_itemvalue=number*10000;
		p_act="������";
		break;
	default :
		write("��Ǯ��������deposit �������� �������� ���磺deposit 3 silver��\n");
		return;
    }
    p_buyersmoney=this_body()->query_all_con_money();
    if(p_buyersmoney<p_itemvalue)
    {
	write("�ڿ�������������ô��Ǯ��\n");
	return;
    }
    n_bank=this_body()->query_amt_money("bank");
    n_bank=n_bank+p_itemvalue;
    this_body()->set_all_con_money(p_buyersmoney - p_itemvalue);
    this_body()->set_money("bank", n_bank);
    p_act=chinese_number(number)+p_act;
    this_body()->simple_action("$N�ó�"+p_act+"����Ǯׯ��\n");
    return;
}
void withdraw_sth(string item, int number)
{
    int p_buyersmoney;
    int p_itemvalue;
    int n_bank;
    string p_act,p_act2;
    if(number<1)
    {
	write("���ѣ���ɶ�أ�\n");
	return;
    }
    switch(item)
    {
	case "coin" :
		p_itemvalue=number;
                p_act="��Ǯ";
		break;
	case "silver" :
		p_itemvalue=number*100;
  		p_act="������";
		break;
	case "gold" :
		p_itemvalue=number*10000;
		p_act="������";
		break;
	default :
		write("ȡǮ��������withdraw �������� �������� ���磺withdraw 3 silver��\n");
		return;
    }
    n_bank=this_body()->query_amt_money("bank");
    p_buyersmoney=this_body()->query_all_con_money();
    if(n_bank<p_itemvalue)
    {
	write("����Ǯׯû�д���ô��Ǯѽ��\n");
	return;
    }
    n_bank=n_bank-p_itemvalue;
    this_body()->set_money("bank", n_bank);
    p_act=chinese_number(number)+p_act;
    p_itemvalue=p_itemvalue*BANKINTEREST;
    p_act2=chinese_value(p_itemvalue);
    this_body()->set_all_con_money(p_buyersmoney + p_itemvalue);
    this_body()->simple_action("$N��Ǯׯȡ��"+p_act+"ʵ���õ���"+p_act2);
    return;
}
mixed deposit(string item, int number)
{
	deposit_sth(item,number);
	return 1;
}	
mixed withdraw(string item, int number)
{
	withdraw_sth(item,number);
	return 1;
}	
