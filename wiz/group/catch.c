// catch.c
// by fire on March 11, 1999
// this is used to spy in a room
void start(string arg)
{
	string p_id,p_area;
	object me=this_body(),env;
	object tar;
	int n_time=time(),p_time;
	p_id=me->query_id()[0];
	if((!me->query_job("patrol","beg_time"))||
	(me->query_job("patrol","status")=="done")){
		write("�����ڲ�δ����Ѳ�����񣬻����ٹ�����Ϊ�\n");
		return;
	}
	
	if(!arg){
		write("�÷������� help catch �鿴������\n");
		return;
	}
	tar=present(arg,environment(this_body()));
	if(!objectp(tar)){
		write("��Ҫץ˭��\n");
		return;
	}

	if(tar->can_catch()){
		tar->be_catch(p_id); // this is catch thief
		return;
	}
	
	p_time=CHAR_D->get_char(arg,"catch_time");
	if(p_time>n_time)
	{
		if(CHAR_D->get_char(arg,"catch_area")
			== me->query_job("patrol","area"))
		{
			string filename,funname;
			mixed para;
			filename=CHAR_D->get_char(arg,"catch_file");
			funname=CHAR_D->get_char(arg,"catch_function");
			para=CHAR_D->get_char(arg,"catch_para");
			call_other(load_object(filename),funname,p_id,arg,para);
			return;			
		}
	}
	else
	{
		if(p_time) // out of data;
		{
			CHAR_D->set_char(tar,"catch_time",0);
			CHAR_D->set_char(tar,"catch_file",0);
			CHAR_D->set_char(tar,"catch_function",0);
			CHAR_D->set_char(tar,"catch_para",0);
			CHAR_D->set_char(tar,"catch_area",0);
		}
	}
	write("���û�����ɣ��Ͳ������ץ�ˡ�\n");
	return ;
	
}
mixed catch_award(string o_id,string p_id)
{
	int rep,repred,repinc;
	object o_o,o_p;
	string mess;
	rep=CHAR_D->get_char(p_id,"reputation");
	repred=rep/20;
	if (repred>15000)repred=15000;
	repinc=rep/20;
	if (repinc>15000)repred=15000;
	if(repinc)
		mess=CHAR_D->get_char(o_id,"name")+"�ܻ���"+
		CHAR_D->get_char(p_id,"name")+"��"+CHAR_D->get_char(o_id,"name")+
		"�����������"+
		chinese_number(repinc)+"�㡣";
	else
		mess=CHAR_D->get_char(o_id,"name")+"�ܻ���"+
		CHAR_D->get_char(p_id,"name")+"��";
	
	CHANNEL_D->deliver_tell("rumor","system",mess);

	CHAR_D->set_char(p_id,"reputation",rep-repred);
	CHAR_D->set_char(o_id,"reputation",
		CHAR_D->get_char(o_id,"reputation")+repinc);

	CHAR_D->appear(p_id,CHAR_D->get_char(p_id,"area"),
		"meeting","$N����֮�󣬱��ܿ��ѣ����������ؼ������ˡ�\n");

}
