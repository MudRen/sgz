// bl.c check if you are in the blacklist
// by fire on March 22, 2000
void start(string arg)
{
	mapping bn;
	string p_id;
	if(!AREA_D->area_exist(arg)){
		write("�÷���cmd bl <a_id>, ���磺cmd bl changan"+
			"�� info a list ���ĵ����б�\n");
		return;
	}
	bn=AREA_D->get_area(arg,"bn");
//	tell_user("fire",sprintf("%O\n",bn));
	if(!mapp(bn)) bn=([]);
	p_id=this_body()->query_primary_id();
	if(!bn[p_id]) {
		write ("�㲻��"+AREA_D->get_area(arg,"name")+"�ĺ������ϡ�\n");
		return;
	}
	write (AREA_D->get_area(arg,"name")+"�ĺ���������������մ���\n");
}
