//****************************************************************
// by fire on Dec 12, 1997 withdraw.c
#include <sanguo.h>
inherit VERB_OB;
void do_withdraw_str(string str)
{
    string *sentence;
    int i;
    int number;
    mixed ss;
    sentence = explode(str, " ");
    i = sizeof(sentence);
    if( i == 1 )
        ss=environment(this_body())->withdraw(sentence[0],1);
    else
    {
        if ( i == 2 )
        {
            if( sscanf(sentence[0], "%d", number) == 1)
            {
                if ((number>200000)||(number<0))
                {
                        write("���ڱ�ׯû�д���ô��Ǯ����\n");
                        return;
                }
                ss=environment(this_body())->withdraw(sentence[1],number);
            }
            else
                ss=environment(this_body())->withdraw("Thisisnothing",1); 
                // this will give a correct deposit format
        }
        else
	{
	if(str=="salary")
		ss=environment(this_body())->withdraw("salary",1);
	else
                ss=environment(this_body())->withdraw("Thisisnothing",1);
                // this will give a correct deposit format
	}
    }
        if(!ss)
        write("ֻ����Ǯׯ����ȡǮ��\n");
}
array query_verb_info() {
    return ({ ({ "STR" }) , ({ "qu"}) });
}
