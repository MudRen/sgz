// spy.c
// by fire on March 11, 1999
// this is used to spy in a room
void spy_ok(object me);
void confirm_over(mixed p_input)
{
        string my_id;
        my_id=this_body()->query_id()[0];
        if((p_input=="yes")||(p_input=="y"))
		{	this_body()->set_job("spy","status","done");
			write("��Ȼ��û�����ȫ����������񣬵�Ҳ���ջ�\n"+
				"����ȥ�����ˡ�\n");
		}
        else
               write("���²�Ӧ��;���ϣ���׼��������졣\n");
        this_user()->modal_pop();
}
void start(string arg)
{
	string p_id,p_area,p_fname;
	object me=this_body(),env;
	string *spied;
	p_id=me->query_id()[0];
	if(!me->query_job("spy","beg_time")){
		write("�����ڲ�û�е����������\n");
		return;
	}
	p_area=me->query_job("spy","area");
	spied=me->query_job("spy","spied");
	if(arg=="info") {
		printf("��������%s��\n",AREA_D->get_area(p_area,"name"));
		printf("����췿������%d��\n",me->query_job("spy","size"));
		printf("�Ѿ������ķ�������%d��\n",sizeof(spied));
		printf("Ŀǰ״̬��%s��\n",
			(me->query_job("spy","status") != "done" ? "�������":"������"));
		if((sizeof(spied)>=me->query_job("spy","size"))&&
                     (me->query_job("spy","done_time")>(time()-1800))){
			string ret;
                              ret=AREA_D->stat_me(p_area,"s",0);
			write("�������\n");
			write(ret);
		}
		return;
	}
	if((arg=="done")&&(me->query_job("spy","status")!="done")){
		if(sizeof(spied)==0){
			write("��һ���鱨��û�и㵽��������˱�ȥ���\n");
			return;
		}
		write("������������δȫ����ɣ����ڻ�ȥֻ�ܵõ�һ�뽱����
ȷ�Ͻ�������ж���(y/n)��");
		this_user()->modal_push((: confirm_over :),
                               "",0,0);
		return;

	}
	if((me->query_job("spy","status"))=="done") {
		write("���������ɣ����ȥ��������ȥ�ɡ�\n");
		return;
	}
	env=environment(me);
    if((env->get_area())!=p_area) {
		write("���������Ҫ�����ĵ���������cmd spy info �鿴���顣\n");
		return;
	}
	p_fname=file_name(env);
	if(member_array(p_fname,spied)!=-1){
		write("����ط��Ѿ������ˣ�����cmd spy info �鿴���顣\n");
		return;
	}
	if(env->is_home()||env->is_base()) {
		write("no use to spy here :) \n");
		return;
	}

	me->set_job("spy","catched",0);	
	write("���󿴿����ҿ���������û��ע�⡣\n���ͳ�һ��ֽ����ʼ��¼��\n");
	me->other_action(
		"$N��ͷ���Եض����ţ�����������һ��ֽ�ϲ�֪������Щʲô��\n");
	me->set_job("spy","spied",spied+({p_fname}));
	me->start_busy(10,"����æ������ء�\n");
	call_out("spy_ok",random(7)+3,me);
	CHAR_D->set_char(p_id,"catch_time",time()+10);

	CHAR_D->set_char(p_id,"catch_file",PCMD+"spy");
	CHAR_D->set_char(p_id,"catch_function","spy_catch");
	CHAR_D->set_char(p_id,"catch_para",0);
	CHAR_D->set_char(p_id,"catch_area",p_area);
	return;

}


void spy_catch(string o_id,string p_id,mixed none)
{
	object o_o,o_p;
	o_o=find_body(o_id);
	if(!objectp(o_o)) return;
	o_p=find_body(p_id);
	if(!objectp(o_p)) {

		tell_user(o_id,"�����Ƴ����һ�����ˣ�����һת�۵Ĺ�����������ˡ�\n");
	o_o->set_job("partol","score",
			o_o->query_job("partol","score")-1);
		return;
	}

	o_o->targetted_action(
		"$N��$T���һ������$r�������ڴ˴�̽���飬�������£�\n",o_p);
	o_p->simple_action(
		"�ڹٱ�һӵ���ϣ���$N���ý��ʵʵ��\n");
	o_o->simple_action(
		"$Nһ���֣��������ߣ�\n");
	o_p->simple_action(
		"�ڹٱ���$NѺ����ȥ��\n");

	CHANNEL_D->deliver_tell("rumor","system",
		CHAR_D->get_char(p_id,"name")+
		"��"+AREA_D->get_area(CHAR_D->get_char(o_id,"area"),"name")+
		"��飬������Ѳ�ߵ�"+CHAR_D->get_char(o_id,"name")+
		"����ץ��");
	o_p->set_job("spy","catched",1);	
	o_p->set_job("spy","status","done");	
	(PCMD+"catch")->catch_award(o_id,p_id);

}




void spy_ok(object me)
{
	string p_id;
	string spied;
	int num;
	if(!objectp(me)) return;
	p_id=me->query_id()[0];
	if(me->query_job("spy","catched"))
		return;
	tell_user(p_id,"���¼��ϣ�����ص��˵�ͷ��\n");
	me->other_action(
		"$N���ͷ�����ٺ١��ظ�Ц��������\n");
	me->stop_busy();

	CHAR_D->set_char(p_id,"catch_file",0);
	CHAR_D->set_char(p_id,"catch_function",0);
	CHAR_D->set_char(p_id,"catch_para",0);
	CHAR_D->set_char(p_id,"catch_area",0);

	spied=me->query_job("spy","spied");
	num=me->query_job("spy","size");
	if(sizeof(spied)>=num){
		tell_user(p_id,"%^H_GREEN%^������ɣ���ȥ̫�ش����Ͱɡ�\n%^RESET%^");
		me->set_job("spy","status","done");
		me->set_job("spy","done_time",time());
	}
}
