// donatete.c
// by fire on August 14, 1998
string s_ret;
string p_where;
int i_amt;
void confirm_donate(mixed p_input)
{
        string my_id;
        my_id=this_body()->query_id()[0];
        if(p_input=="yes")
                (EV_DONATE)->donate(my_id,p_where,i_amt);
        else
                write("�����µ����ؿ��ǿ��ǡ�\n");
        this_user()->modal_pop();
}
void start(string arg)
{
        int my_id,task_id;
        int* my_task;
	string p_amt;
	int n_bank,n_salary;
        my_id=this_body()->query_id()[0];
        if(!CHAR_D->get_char(my_id,"nation"))
        {
                write("������˸�һ�ٰ�ְ֮���ٿ��Ǿ����������ɡ�\n");
                return;
        }
if(CHAR_D->get_char(my_id,"ranknation")==R_KING) {
    write ("��Ϊһ��֮����ô�����Լ���Ǯ�أ����Ƕ࿼�ǿ��ǰ��հɡ�\n");

    return;
}
	if(!arg)
		arg="";
	if(sscanf(arg,"%s %s",p_where,p_amt)!=2)
	{
		p_amt=arg;
		p_where="here";
	}
	i_amt=to_int(p_amt);
	if((i_amt<5)||((p_where!="here")&&(p_where!="nation")))
	{
                write("�÷�����");
                write("�� cmd help donate �鿴��ϸ������\n");
                return;
        }
	n_bank=this_body()->query_amt_money("bank")/10000;
	n_salary=CHAR_D->get_char(my_id,"gold");
	if(i_amt>(n_bank+n_salary))
	{
		write("���ʻ���û����ô�����Ծ���������money���ʡ�\n");
                return;
	}
        write("�������Ҫ���������������������yes��\n");
        this_user()->modal_push((: confirm_donate :),
                               "",0,0);
}
