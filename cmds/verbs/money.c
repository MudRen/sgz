// by fire on Dec 13 1997
// Updated by tset 7-26-98
#include <mudlib.h>
#include <sanguo.h>
inherit VERB_OB;
inherit CHINESE_DA;
mixed can_money_liv(object liv)
{
        return 1;
}
private void money_print(object who)
{
    int amount;
    string currency;
    string retmsg;
    string *types;
    int n_coin,n_silver,n_gold,n_bank;
    int n_withbody;
    int n_sum;
    int n_sal;
    string p_id;
    string p_tmp;
    who->put_m_all_money();
    n_coin=who->query_con_money("coin");
    n_silver=who->query_con_money("silver");
    n_gold=who->query_con_money("gold");
    n_bank=who->query_amt_money("bank");
    n_withbody=10000*n_gold+100*n_silver+n_coin;
    p_id=(who->query_id())[0];
    n_sal=CHAR_D->get_char(p_id,"gold");
    n_sal=n_sal*10000;
    n_sum=n_withbody+n_bank+n_sal;
    if(!n_sum)
    {
        printf("������������磬һ�����У��ߣ��ߣ�\n"); 
    }
    else
    {
        if(n_withbody=0)
        {
                printf("������û��װǮ��\n");
        }
        else
        {
                printf("�����ϴ��У�\n");
                if (n_gold)
                {
                        p_tmp=chinese_number(n_gold)+"�����ӡ�";
                        printf("     %s\n",p_tmp);
                }
                if (n_silver)
                {
                        p_tmp=chinese_number(n_silver)+"�����ӡ�";
                        printf("     %s\n",p_tmp);
                }
                if (n_coin)
                {
                        p_tmp=chinese_number(n_coin)+"��Ǯ��";
                        printf("     %s\n",p_tmp);
                }
        }
        if (n_bank)
        {
                printf("����Ǯׯ���У�\n");
                p_tmp=chinese_value(n_bank);
                printf("     %s",p_tmp);
        }
        else
        {       
                printf("��û����Ǯׯ��Ǯ��\n");
        }
        if (n_sal)
        {
                printf("��Ŀ��ٺ���У�\n");
                p_tmp=chinese_value(n_sal);
                printf("     %s",p_tmp);
	}
        printf("�㹲�вƲ�:\n");
        p_tmp=chinese_value(n_sum);
        printf("     %s",p_tmp);
    }
}
void do_money()
{
        object who;
        who=this_body();
        money_print(who);
}
mixed do_money_str(string liv)
{
        object ob;
        if(!(wizardp(this_body()->query_userid())))
        {
                printf("ֻ����ʦ�ſ���͸�ӱ��˵�״��\n");
                return;
        }
        else
        {
                ob = present(liv, environment(this_body()));
                if (!ob) ob = find_body(liv);
                if (!objectp(ob)) {
                        write("��Ҫ�쿴˭��״����\n"); 
                        return;
                }
                money_print(ob);
        }
}
array query_verb_info()
{
    return ({ ({ "", "STR", }), ({  }) });
}
