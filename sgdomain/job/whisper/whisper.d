// the job of whisper a certain wise general
// by group on Mar 1999
static private string *sug=({
"$N��$TЦ����$m$R����򲻵�֮�£���ֻ�¹���������������",
"$N��$TЦ����$m$R���ǻ����һ����ɲ⣬��ÿ����˵ز��ɾ���ѽ��",
"$N��$TЦ����$m$R�д󽫷緶��ֻ������������ò�֮���ģ�",
"$N��$TЦ����$m$R�����������������壬ֻ����Щ��������$RЦ�ɡ�",
"$N��$T����������Щ��������ֻ�����ڻ�û�С�����",
"$N��$TЦ������$m$R֮��������������ıְ�����д�ɡ�",
"$N��$T����$m$R�粻�����ͷ������ֻ�������촦ѽ��",
"$N��$TЦ�����ҹ���ǿ��׳���������㣬���ձؿ�һͳ���¡�",
"$N��$T����$m$R�ڴ˵ز������ã��β����ٳ��ߣ�����ľ���ܣ��Գɴ�ҵ��",
"$N��$Tһ���֣��������յü�$Rһ�棬��Ȼ�����鴫��ʱ�����磬$s���и�ǡ�",});
void judge_select(mixed obs);
void input_way(mixed obs,string str);
void no_answer_way(mixed obs);
void select_way(mixed obs);
void talk_over(mixed obs);
void big_success(mixed obs);
mixed job(string m_id,string officer_id)
{
	string m_nation=CHAR_D->get_char(officer_id,"nation");
	string *mlist,target;
	object o=find_body(m_id);
	if(!objectp(o)) return 0;
//	string   
	mlist=CHAR_D->check_char("type",TYPE_NPC);
	mlist=filter_array(mlist,(: ((!CHAR_D->get_char($1,"is_tmp") )&&(CHAR_D->get_char($1,"nation") )&&(CHAR_D->get_char($1,"nation")!=$(m_nation))&&(CHAR_D->get_char($1,"nation")!="group")&&(CHAR_D->get_char($1,"ranknation")!= R_KING))  // king cant be whisperd
	:) );
	if(!mlist) mlist=({});
	if(!sizeof(mlist))
	return "$N��$T�������ûʲô�˺ò߷��ġ�\n";
	target=mlist[random(sizeof(mlist))];
	o->set_asklist("whisper","target",target);
	o->set_asklist("whisper","filename",PJOB+"whisper/whisper");
	o->set_asklist("whisper","funname","ask_whisper");
	o->add_job("whisper");
	o->set_job("whisper","status","begin");
	o->set_job("whisper","memo","�߷�"+CHAR_D->get_char(target,"name")+"("+target+")");
	return "$N��$T���������˵"+COUNTRY_D->get_country(CHAR_D->get_char(target,"nation"),"name")+"��"+
	CHAR_D->get_char(target,"name")+"�Ĵ治����\n"+
	"���鷳$Rȥ̽��һ�£������˵ask "+target+" about whisper��\n"+
	"������ܣ����ɿ�������١�\n";
}
void ask_whisper(object me, object target)
{
	string t_area,t_id;
    	string m_title,p_id;
	string nat;
	int loy;
	p_id=me->query_id()[0];
	t_id=target->query_id()[0];
	t_area=CHAR_D->get_char(t_id,"area");
	m_title=OFFICER_D->query_rank_name((OFFICER_D->query_area_officer_title(AREA_D->get_area(t_area,"level"),0,0))[0]);
	me->targetted_action(
	"$N��$TЦ��������"+m_title+"��$s����$m$R������\n"+
	"������������һ����\n",target);
	me->clear_asklist("whisper");
	me->set_job("whisper","status","done");
	target->special_heart(600);
//will now go around or do semote	
	me->set_job("whisper","topics",({}));
//haven't talk yet	
//within 10 minute	
	me->set_job("whisper","score",20);
//meet is 20 	     
//because in other country	
//succ is 100	
	if((CHAR_D->get_char(p_id,"reputation"))<10000) {
		target->targetted_action("$N��$T����һ�ۣ����Ҹ���������ûʲô��˵�ģ�$R���Ȼ�ɡ�\n",me);
		DELAY_D->delay_simple_action(
			me,"$N���ε�Ц������������....\n",1);
		DELAY_D->delay_simple_action(
			me,"$Nת��һ�룬�������Ѿ������ˣ��ɲ��ɻ�ȥ��������˵��\n",2);
		return;

	}
	
	CHANNEL_D->deliver_tell("rumor","system",	
	COUNTRY_D->get_country(CHAR_D->get_char(p_id,"nation"),"name")+	
	"��"+CHAR_D->get_char(p_id,"name")+"����"+	
	COUNTRY_D->get_country(CHAR_D->get_char(t_id,"nation"),"name")+	
	"��"+CHAR_D->get_char(t_id,"name")+"��̸��");
	DELAY_D->delay_targetted_action(
	target,me,"$N��$Tһ���֣��������Ҹ�Ϊ���������ؿ�����\n",1);

	call_out("select_way",2,({ me, target}));
	CHAR_D->set_char(p_id,"catch_time",time()+600);
	CHAR_D->set_char(p_id,"catch_file",PJOB+"whisper/whisper");
	CHAR_D->set_char(p_id,"catch_function","whisper_catch");
	CHAR_D->set_char(p_id,"catch_para",target);
	CHAR_D->set_char(p_id,"catch_area",t_area);
	nat=AREA_D->get_area(t_area,"nation");
	loy=CHAR_D->get_char_loyalty(p_id,nat);
	loy--; loy=bmax(1,loy);
	CHAR_D->set_char_loyalty(p_id,nat,loy);
	return;
}
void whisper_catch(string o_id,string p_id,object o_general)
{
	object o_o,o_p;
	if(objectp(o_general))
	{
	string pep_id;
	o_general->simple_action("$NͻȻ��ɫ���ţ�����׽��������ˣ��������ܣ�\n");
	pep_id=o_general->query_id()[0];
	CHAR_D->remove_npc_char(pep_id);
	}
	o_p=find_user(p_id);
	if(objectp(o_p))
	o_p->modal_pop();
	o_o=find_body(o_id);
	if(!objectp(o_o)) return;
	o_p=find_body(p_id);
	if(!objectp(o_p))
	{
	tell_user(o_id,"����һ����"+
	CHAR_D->get_char(o_id,"name")+"���ˡ�\n��Ĺ����ɼ��½��ˡ�\n");
	o_o->set_job("partol","score",
	o_o->query_job("partol","score")-1);
	return;
	}
	o_o->targetted_action("$N��$T���һ������$r�������ڴ�ɿ�����������£�\n",o_p);
	o_p->simple_action(
	"�ڹٱ�һӵ���ϣ���$N���ý��ʵʵ��\n");
	o_o->simple_action(
	"$Nһ���ֵ������Ҵ��ߡ�\n");
	o_p->simple_action(
	"�ڹٱ���$NѺ����ȥ��\n");
	CHANNEL_D->deliver_tell("rumor","system",
	CHAR_D->get_char(p_id,"name")+
	"��"+AREA_D->get_area(CHAR_D->get_char(o_id,"area"),"name")+
	"�߷��н���������Ѳ�ߵ�"+CHAR_D->get_char(o_id,"name")+             
	"����ץ��");
	(PCMD+"catch")->catch_award(o_id,p_id);
}
void judge_select(mixed obs)
{
	object me=obs[0],tar=obs[1];
	string p_id,t_id,marea;
	mixed gift;
	int loyalty,score,p_select,rela;
	int l_d=3,maxloyalty=102;
//if higher then 90 hard to convince
	if(!objectp(me)) return;
	if(!objectp(tar))
	{
	talk_over(obs);
	return;
	}
	p_id=me->query_id()[0];
	marea=CHAR_D->get_char(p_id,"area");
	t_id=tar->query_id()[0];
	gift=CHAR_D->get_char(t_id,"gift");
	loyalty=CHAR_D->get_char(t_id,"loyalty");
	score=me->query_job("whisper","score");
	p_select=me->query_job("whisper","select");
	switch(p_select)
	{
	case 1:
	//if((random(30)<gift["wuli"])&&(random(maxloyalty)>loyalty)) //���ҳϸ�����
	if (random(30)<gift["wuli"])
	{
	tar->simple_action("$N������������ţ��˻�����\n");
	score+=2;
	loyalty-=random(l_d);
	}
	else
	{
	tar->simple_action("$Nҡͷ������������ſڿ��ӡ�\n");
	tar->responda("heng");
	score-=1;
	}
	break;
	case 2:
	//if((random(30)<gift["zhimou"])&&(random(maxloyalty)>loyalty))
	if(random(30)<gift["zhimou"])
	{
	
	tar->simple_action("$N��ͷ����һ�������������û��\n");
	score+=2;
	loyalty-=random(l_d);
	}
	else
	{
	tar->simple_action("$N��Цһ���������\n");
	tar->responda("angry");
	score-=1;
	}
	break;
	case 3:
	//if((random(30)<gift["meili"])&&(random(maxloyalty)>loyalty))
	if(random(30)<gift["meili"])
	{
	tar->simple_action("$N�������°ͣ��ԣ�$s��Ϳ������ˡ�\n");
	score+=2;
	loyalty-=random(l_d);
	}
	else
	{
	tar->simple_action("$Nһ���֣������ݵú��ԣ�\n");
	tar->responda("puke");
	score-=1;
	}
	break;
	case 4:
	if(me->query_all_con_money()<10000)
	{
	tell_user(p_id,"������û����Ǯ��\n");
	tar->simple_action("$Nŭ�������Ǻ��֡�\n");
	tar->responda("angry");
	score-=2;
	}
	else
	{
	me->set_all_con_money( me->query_all_con_money() -10000 );
	me->targetted_action("$N����$Tһ�����ӡ�\n",tar);
	tar->simple_action("$N���ϲ�ס�ƴǣ�һ��ȴ���İѽ��Ӵ������\n");
	score+=4;
	loyalty-=random(2);
	}
	break;
	case 5:
	tar->simple_action("$N���������Ȼ��û�кã��Ǿͻ�ͷ��˵�ɡ�\n");
	break;
	case 6:
	//if(random(maxloyalty)>loyalty)
	if ((rela=RELATION_D->get_bazi_diff_level(p_id,t_id))<5)
	{
	tar->simple_action("$N��ס��ͷ���ԣ��ԣ��������һϯ̸��ʤ��ʮ���鰢��\n");
	score+=(5-rela);
	loyalty-=(5-rela);
	}
	else
	{
	tar->simple_action("$Nҡͷ��������ͬ����Ϊı���㻹����ذɣ���\n");
	score--;
	loyalty+=2;
	}
	break;
	case 7:
	if(random(maxloyalty)>loyalty)
	{
	tar->simple_action("$N������Щ���ģ��⡣��������Ǻã�\n");
	score+=2;
	loyalty-=l_d;
	}
	else {tar->simple_action("$N��Ȼ����$s����ʬ���������ѡ�\n");
	score--;
	loyalty+=2;
	}
	break;
	case 8:
	if(random(maxloyalty)>loyalty) {
	tar->simple_action("$NЦ���������ǿ��$s��Ľ�Ѿá�\n");
	score+=2;
	loyalty-=l_d;
	}	
	else
	{	
	tar->simple_action("$N��Ц����������ˣ�Ҳδ���ܳɰ�ҵ��\n");
	score--;
	loyalty+=2;
	}		   
	break;
	case 9:		   
	if(random(maxloyalty/2)>loyalty)
	{
	tar->simple_action("$N��������������ˣ�˵�հ���˼����\n");
	big_success(obs);
	return;
	}
	else
	tar->targetted_action("$N��ɫ���������Ѿ���$R����¡�\n",me);
	break;
	case 10:
	tar->simple_action("$Nһ���֣�����ˡ��Զ�ͣ���ǡ�\n");
	talk_over(obs);
	default:
	return;
	}
	CHAR_D->set_char(t_id,"loyalty",loyalty);
	me->set_job("whisper","score",score);
	call_out("select_way",1,obs);
	}
	void input_way(mixed obs,string str)
	{
	int p_select;
	object me=obs[0],usr,tar;
	string p_id;
	int *topics;
	p_select=to_int(str);
	if((p_select<1)||(p_select>10))
	return;
	remove_call_out("no_answer_way");
	if(!objectp(me))
	return;
	p_id=me->query_id()[0];
	usr=find_user(p_id);
	if(!objectp(usr))
	return;
 	topics=me->query_job("whisper","topics");
 	if(member_array(p_select,topics)!=-1)
	{
	tell_user(p_id,"��������Ѿ�̸���ˣ��û�һ�����⡣\n");
	call_out("no_answer_way",30,obs);
	return;
	}
	usr->modal_pop();
	tar=obs[1];
	if(!objectp(tar))
	{
	talk_over(obs);
	return;
	}
	me->targetted_action(sug[p_select-1]+"\n",tar);
	me->set_job("whisper","select",p_select);
	topics+=({p_select});
	me->set_job("whisper","topics",topics);
	call_out("judge_select",1,obs );
}
void no_answer_way(mixed obs)
{
	input_way(obs,"10");
}
void select_way(mixed obs)
{
	object me=obs[0],usr;
	string p_id;
	if(!objectp(me)) return;
	p_id=me->query_id()[0];
	usr=find_user(p_id);
	if(!objectp(usr)) return;
	tell_user(p_id,"���Ŀ�ľ��Ǿ�������������\n"+"������������������������������������������������������������\n"+" 1 ��ά����  2 ��ά�ǻ�  3 ��ά����  4 ��������  5 ���ͱ��� \n"+" 6 ��ϥ̸��  7 ������в  8 �Կ����  9 ������Ȱ 10 ���     \n"+"����������
��������������������������������������������������\n"+"��������Ļ���(1--10)��\n");
	call_out("no_answer_way",30,obs);
	usr->modal_push((: input_way,obs:),"��������Ļ���(1--10)��");
}
void big_success(mixed obs)
{
	object me=obs[0],tar;
	string p_id,t_id;
	if(!objectp(me)) return;
	p_id=me->query_id()[0];
	tar=obs[1];
	if(objectp(tar))
	{
	t_id=tar->query_id()[0];
	tar->responda("wave");
	tar->simple_action("$N�뿪�ˡ�\n");
	CHAR_D->remove_npc_char(t_id);
	}
	(EV_LEAVE)->leave(t_id);
	me->set_job("whisper","score",50);
	tell_user(p_id,"%^H_BLUE%^������ȫ�ɹ�����ȥ̫�ش����Ͱɡ�\n%^RESET%^");
}
void talk_over(mixed obs)
{
	object me=obs[0],tar;
	string p_id,t_id;
	if(!objectp(me)) return;
	p_id=me->query_id()[0];
	tar=obs[1];
	if(objectp(tar))
	{
	t_id=tar->query_id()[0];
	tar->responda("wave");
	tar->simple_action("$N�뿪�ˡ�\n");
	CHAR_D->remove_npc_char(t_id);
	}
	CHAR_D->set_char(p_id,"catch_time",0);
	CHAR_D->set_char(p_id,"catch_file",0);
	CHAR_D->set_char(p_id,"catch_function",0);
	CHAR_D->set_char(p_id,"catch_para",0);
	tell_user(p_id,"%^H_GREEN%^������ɲ�����ȥ̫�ش����Ͱɡ�\n%^RESET%^");
}