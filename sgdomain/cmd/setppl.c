// setppl.c
// by listen on July, 2001
// this is used to set a fake ppl in a room
//this file should be in /sgdomain/cmd/setppl.c
//to Use the file, cmd setppl
void start(string arg)
{
	string p_id,p_area,p_room;
	object me=this_body();
	object ot,env;
	string target, typ;

//get the first ID of mine
	p_id=me->query_id()[0];
	p_room=CHAR_D->get_char(p_id,"room");
//env is the room that I am standing
	env=environment(me);

	target=env->get_area(); //find out the city 

	if(me->query_job("setppl","status")!="begin"){
		write("�����ڲ�û�е������ü��������\n");
		return;
	}
	if(env->is_home()||env->is_base()) {
		write("������������� \n");
		return;
	}
// need to be changed from here
//	typ="/sgdomain/event/ev_fake_guy"->get_type();
//	ot=CHAR_D->find_npc_char(target+" "+typ);
//	if(!objectp(ot)) {
	if ("/sgdomain/event/ev_guy"->create_fake_guy(target,p_room,p_id) == 0)
	{
		write(" ��ʱ�޷���������������ü�������Ժ����ԡ� \n");
		return;
	}
	//this is for temp track
	CHAR_D->set_char("listen","setppltotal",
		CHAR_D->get_char("listen","setppltotal")+1);
	//temp ends here
//	target=target+" "+typ;
//	ot=CHAR_D->find_npc_char(target);
//to here
	write("���󿴿����ҿ���������û��ע�⡣\n��Ը����������������\n");
	me->other_action(
		"$N��ͷ���Եض�����ǷԸ��˼��䡣\n$N��������漴�������ʧ�ںڰ��С�\n");

	me->set_job("setppl","done_time",time()); //in case of other function use done_time
	me->finish_job("setppl");
   	me->set_job("setppl","status","over"); //since no reward for this job, directly over
	return;

}

