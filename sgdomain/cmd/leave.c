// leave.c 
// by fire on August 29, 1998
// used for player char to risign a position
void confirm_leave(mixed p_input)
{
	string my_id;
	mixed ret;
	my_id=this_body()->query_id()[0];
	if(p_input=="yes")
		ret=(EV_LEAVE)->leave(my_id);
	else
		write("�����������Ҫ���ؿ��ǡ�\n");
	this_user()->modal_pop();
	if(stringp(ret)) write(ret);return; 
}
void start(string arg)
{
        int my_id;
        my_id=this_body()->query_id()[0];
        if(!CHAR_D->get_char(my_id,"nation"))
        {
                write("�������ںε���ְѽ����\n");
                return;
        }
	write("�������Ҫ���ٲ������𣿾����˵Ļ�������yes��\n");
	this_user()->modal_push((: confirm_leave :),
                               "",0,0);
}