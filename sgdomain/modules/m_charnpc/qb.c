// qb.c the body of �ױ�
inherit PMODULES+"m_charnpc";
private my_id,my_master;
void auto_disappear();
void setup()
{
    call_out("auto_disappear",60); 
}
void extra_init()
{
	my_id=this_object()->query_id()[0];
	my_master=CHAR_D->get_char(my_id,"my_master");
}
void auto_disappear()
{
	object o=CHAR_D->find_char(my_master);
	if(objectp(o))
	{
		this_object()->targetted_action(
			"$N��$T����$RҪ��û�£�С�˾��������ˡ�\n",o);
	}
	CHAR_D->remove_char(my_id);
}
void remove()
{
	remove_call_out("auto_disappear");
	this_object()->simple_action(
		"$N�����˳��ˡ�\n");
	::remove();
}
void my_charaction(){
}
