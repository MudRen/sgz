// by fire on Dec 12, 1997 deposit.c
#include <sanguo.h>
inherit VERB_OB;
void do_deposit_str(string str)
{
    string *sentence;
    int i;
    int number;
    mixed ss;
    sentence = explode(str, " ");
    i = sizeof(sentence);
    if( i == 1 )
		ss=environment(this_body())->deposit(sentence[0],1);
    else
    {
        if ( i == 2 )
        {
            if( sscanf(sentence[0], "%d", number) == 1)
            {
                if ((number>200000)||(number<0))
				{
					write("������û����ô��Ǯ��\n");
					return;
				}
				ss=environment(this_body())->deposit(sentence[1],number);
            }
	    else
		ss=environment(this_body())->deposit("Thisisnothing",1); 
		// this will give a correct deposit format
	}
	else
		ss=environment(this_body())->deposit("Thisisnothing",1);
		// this will give a correct deposit format
    }
	if(!ss)
	write("���ǵ�Ǯׯ��Ǯ�Ƚϰ�ȫ��\n");
}
array query_verb_info() {
    return ({ ({ "STR" }) , ({ "cun"}) });
}
