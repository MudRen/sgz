// zi.c 
// by fire on Sep 4, 1998
// used for player char to risign a position
void start(string arg)
{
	string p_id;
	p_id=this_body()->query_id()[0];
	if(arg=="")
	{
		this_body()->set_sg_zi(0);
		CHAR_D->set_char(p_id,"zi",0);
		write("��ȡ���ɹ���\n");
	}
	else
	{
		if(strlen(arg)!=4)
		{
			write("�ֱ���������������ɡ�\n");
			return;
		}
		else
		{
			this_body()->set_sg_zi(arg);
			CHAR_D->set_char(p_id,"zi",arg);
	                write("�����óɹ���\n");
		}
      }
}
