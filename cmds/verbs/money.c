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
        printf("哈哈，两袖清风，一无所有，高！高！\n"); 
    }
    else
    {
        if(n_withbody=0)
        {
                printf("你身上没有装钱。\n");
        }
        else
        {
                printf("你身上带有：\n");
                if (n_gold)
                {
                        p_tmp=chinese_number(n_gold)+"两金子。";
                        printf("     %s\n",p_tmp);
                }
                if (n_silver)
                {
                        p_tmp=chinese_number(n_silver)+"两银子。";
                        printf("     %s\n",p_tmp);
                }
                if (n_coin)
                {
                        p_tmp=chinese_number(n_coin)+"文钱。";
                        printf("     %s\n",p_tmp);
                }
        }
        if (n_bank)
        {
                printf("你在钱庄存有：\n");
                p_tmp=chinese_value(n_bank);
                printf("     %s",p_tmp);
        }
        else
        {       
                printf("你没有在钱庄存钱：\n");
        }
        if (n_sal)
        {
                printf("你的库存俸银有：\n");
                p_tmp=chinese_value(n_sal);
                printf("     %s",p_tmp);
	}
        printf("你共有财产:\n");
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
                printf("只有巫师才可以透视别人的状况\n");
                return;
        }
        else
        {
                ob = present(liv, environment(this_body()));
                if (!ob) ob = find_body(liv);
                if (!objectp(ob)) {
                        write("你要察看谁的状况？\n"); 
                        return;
                }
                money_print(ob);
        }
}
array query_verb_info()
{
    return ({ ({ "", "STR", }), ({  }) });
}
