//**********************************************************************
// m_bank.c  by fire on Dec 14 1997  
#include <mudlib.h>
#include <move.h>
inherit INDOOR_ROOM;
#define MAXBANKMONEY 30000000
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
    if((n_bank+p_itemvalue)>MAXBANKMONEY)
    {
        write("ĿǰǮׯ���ֻ�ܴ�"+chinese_value(MAXBANKMONEY));
        return;
    }
    n_bank=n_bank+p_itemvalue;
    this_body()->set_all_con_money(p_buyersmoney - p_itemvalue);
    this_body()->set_money("bank", n_bank);
    p_act=chinese_number(number)+p_act;
    this_body()->simple_action("$N�ó�"+p_act+"����Ǯׯ��\n");
    return;
}
void withdraw_salary()
{
   string p_id;
   int p_salary,p_with;
   int p_bank;
   p_id=(this_body()->query_id())[0];
   p_salary=CHAR_D->get_char(p_id,"gold");
   if(!p_salary)
   {  write("��Ŀǰû�п��ٺ����\n");
      return;
   }
   p_with=1;
   if(p_salary>20) p_with=10;
   if(p_salary>200) p_with=100;
   p_bank=this_body()->query_amt_money("bank");
   if((p_bank+p_with*10000)>MAXBANKMONEY)
   {
      write("ĿǰǮׯ���ֻ�ܴ�"+chinese_value(MAXBANKMONEY));
      return;
   }
   p_bank+=(p_with*10000*0.9);
   write("��Ŀ��ٺ���е�"+chinese_number(p_with)+"���ƽ���ת�����˽���˻���\n"
   +"�����ѣ�"+CHINESE_D->chinese_value(p_with*1000)+"��\n");
   this_body()->set_money("bank", p_bank);
   CHAR_D->set_char(p_id,"gold",p_salary-p_with);
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
        case "salary":
                withdraw_salary();
                return;
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
int is_bank() { return 1;}
