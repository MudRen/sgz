// the job of visit a certain officer to increase his loyalty
// by row on Dec 1999
static private string *sug=({
"$N��$TЦ����$m$R����򲻵�֮�£�$s����������������",
"$N��$TЦ����$m$R���ǻ����һ����ɲ⣬�ܺ�$Rͬ��Ϊ�٣�����$s�����ˡ�",
"$N��$TЦ����$m$R�д󽫷緶��ͬʱ���ι��з�����ʱ��ָ��$sһ����",
"$N��$TЦ����$m$Rƽ�ص����������������壬ֻ����Щ������$s��һ��С��˼������$RЦ�ɡ�",
"$N��$TЦ����$s������Щ��������$R���ͣ�ֻ����������̫æ������",
"$N��$Tһ���֣�������$m$R�߼����������£��ɳɴ�ҵ��Ϊ˭��",
"$N��$TЦ������$m$R֮���������ҹ�Ϊ�٣�����ƽ�����ơ�",
"$N��$TЦ�����ҹ���ǿ��׳���������㣬���ձؿ�һͳ���¡�",
"$N��$TЦ����$m$R�߷����ڣ����ع��񰮴����ӣ�$sҲ���岻�ѡ�",
"$N��$Tһ��ȭ��������������$Rһ��ʵ����ƽ���¡�ֻ��ʱ�����磬$s���и�ǡ�",
});
void judge_select(mixed obs);
void input_way(mixed obs,string str);
void no_answer_way(mixed obs);
void select_way(mixed obs);
void talk_over(mixed obs);

mixed job(string m_id,string officer_id)
{
   string m_area=CHAR_D->get_char(officer_id,"area");
   string *mlist,target,m_nation;
   object o=find_body(m_id);
	m_nation=AREA_D->get_area(m_area,"nation");
   if(!objectp(o)) return 0; // string

   mlist=CHAR_D->check_char_area("type",TYPE_NPC,m_area);
   mlist=filter_array(mlist,
           (: ((CHAR_D->get_char($1,"loyalty")!=100 ) &&
              (CHAR_D->get_char($1,"nation")==$(m_nation ))  ) :) );
   if(!mlist) mlist=({});
//	tell_user("row","it is "+m_nation+".\n");
   if(!sizeof(mlist)){
		o->add_job("visitofficer");
		o->finish_job("visitofficer");
		return "$N��$Tҡҡͷ��������ȥ������û��ʲô��Ա��Ҫ̽�á�\n";
	}
   target=mlist[random(sizeof(mlist))];
   o->set_asklist("talk","target",target);
   o->set_asklist("talk","filename","/sgdomain/job/visitofficer/visitofficer");
   o->set_asklist("talk","funname","ask_talk");

  o->add_job("visitofficer");
  o->set_job("visitofficer","status","begin");
  o->set_job("visitofficer","memo","����"+CHAR_D->get_char(target,"name")+"("+target+")");
   
   return "$N��$T���������˵"+CHAR_D->get_char(target,"name")+"("+target+")"+
	   "�Ļ��������鷳$Rȥ����һ�¡�\n�����˵ask "+target+" about talk ��\n";
}
void ask_talk(object me, object target)
{
	string m_area,m_id;
    string m_title;
	m_id=me->query_id()[0];
	m_area=CHAR_D->get_char(m_id,"area");
    m_title=OFFICER_D->query_rank_name(
        (OFFICER_D->query_area_officer_title(
         AREA_D->get_area(m_area,"level"),0,0))[0]);
	me->targetted_action(
      "$N��$TЦ��������"+m_title+"����$s����$m$R��������������һ����\n",target);
	DELAY_D->delay_targetted_action(
		target,me,"$N��$TЦ��������������ͬ��Ϊ�٣��αع�ǫ��\n",1);
	me->clear_asklist("talk");
	me->set_job("visitofficer","status","done");
	target->special_heart(600); // will now go around or do semote
	me->set_job("visitofficer","topics",({})); //haven't talk yet	                            
	                             // within 10 minute
	me->set_job("visitofficer","score",10); // meet is 10
	                                      // succ is 50
	call_out("select_way",2,({ me, target}));
	return;
}

void judge_select(mixed obs)
{
    object me=obs[0],tar=obs[1];
	int ladd=1,lsub=1;
	string p_id,t_id,mnation,marea;
	mixed gift;
	int loyalty,score,p_select;
	if(!objectp(me)) return;
	if(!objectp(tar)) {talk_over(obs); return;}
	p_id=me->query_id()[0];
	marea=CHAR_D->get_char(p_id,"area");
	t_id=tar->query_id()[0];
	gift=CHAR_D->get_char(t_id,"gift");
	mnation=CHAR_D->get_char(p_id,"nation");
	loyalty=CHAR_D->get_char_loyalty(t_id,mnation);
	score=me->query_job("visitofficer","score");
	p_select=me->query_job("visitofficer","select");
	switch(p_select)
	{
	case 1:
	if(random(30)>gift["wuli"])
	{
	if(random(3)>1)
	{
	tar->simple_action("$N�������ĵص�������\n");
	me->simple_action("$N��֪���Լ�������˵���ˣ�����˵���ˣ�������ĥ������\n");
	}
	else
	{
	tar->simple_action("$Nһ���ۣ������㲻���ڷ���Ұɣ�\n");
	tar->responda("heng"); score-=1;loyalty-=lsub;
	}
	}
	else
	{
	tar->targetted_action("$N������Ц����$m$R�����ˡ�\n",me);
	score+=2; loyalty+=ladd+random(1);
      }
	break;
	case 2:
	if(random(30)>gift["zhimou"])
	{
	if(random(3)>1)
	{
	tar->simple_action("$N����û˯�ѵ����ӣ�Ŷ��������Ǹ�������\n");
	me->simple_action("$Nֻ������������Ҫ��Ҫ�Ҹ�����һ�£������������ѣ�\n");
	}
	else
	{
	tar->simple_action("$N��Цһ����������л��$s������֪֮����\n");
	tar->responda("angry"); score-=1;loyalty-=lsub;
	}
      }
	else
	{
	tar->targetted_action("$N΢΢һЦ������������$m$R̫��̧���ˡ�\n",me);
	score+=2; loyalty+=ladd+random(1);
	}
	break;
	case 3:
	if(random(30)>gift["meili"])
	{
     	if(random(3)>1)
	{
	tar->simple_action("$N��ϸ�����ŵ��ϵ����ϣ�ͷҲ��̧�ص������ǣ����ǡ�����\n");
	me->simple_action("$NҲ��ͷ��ȥ�������б��𣿰����ǻƻƵ�һ����ʲ�ﶫ������\n");
	}
	else
	{
      tar->simple_action("$N���ߡ���һ�����������𣿣��ҿ��������˰ɡ�\n");
	tar->responda("puke"); score-=1;loyalty-=lsub;
	}
      }
	else {  tar->targetted_action("$NЦ���������ֵ���$s����Щ���£���ֵ$Rһ�ᣬ���ǹ�ͬ̽�֣���ͬ̽�֡�\n",me);
	score+=2; loyalty+=ladd+random(1);
	}
	break;
	case 4:
	if(me->query_all_con_money()<20000) {
	tell_user(p_id,"������û����Ǯ��\n");
	tar->simple_action("$Nҡͷ������ʲô���ã���\n");
	tar->responda("angry"); score-=2;loyalty-=lsub;
	}
	else
	{
	if(random(3)>1)
	{
	tar->simple_action("$N����û���������ӣ�����Ŷ���������ӵ���\n");
	me->simple_action("$Nһ�֣����ĵذ�Ǯ���˻�ȥ�����㣬�һ������أ�\n");
	}
	else
	{
	me->set_all_con_money( me->query_all_con_money() -20000 );
	me->targetted_action("$N����$T�������ӡ�\n",tar);
	tar->targetted_action("$NЦ�Ǻǵص�����Ȼ��$m$Rһ�����⣬$s�Ͳ��ƴ��ˡ�\n",me);
	score+=2; loyalty+=ladd+random(1);
	}
	}
	break;
	case 5:
	tar->simple_action("$NЦ���������Ȼ��û�кã��Ǿͻ�ͷ��˵�ɡ�\n");
	break;
	case 6:
	if(random(80)>loyalty)
	{
	tar->simple_action("$N��������һ����������������ʲô�߼���Ц����\n");
	score--;loyalty-=lsub;
	}
	else
	{
	if(random(3)>1)
	{
	tar->simple_action("$N������磬ֻ����������ס��ҡ����������ӡ�������î������\n");
	me->simple_action("$NҲ���������ؽ��ϣ��졢����������������\n");
	}
	else
	{
	tar->simple_action("$Nҡͷ����һ����������$s֮��������ɳ�Ӣ���ߣ��ˡ�����\n");
	score+=2;loyalty+=ladd+random(1);
	}
	}
	break;
	case 7:
	if(random(80)>loyalty)
	{
	tar->simple_action("$Nһ��ü���ߣ�$s�εº��ܣ���Ҳûָ���߹ٺ�»��\n");
	score--;loyalty-=lsub;
	}
	else
	{
	if(random(3)>1)
	{
	tar->simple_action("$N����������ղ���˭���ҵ��������ţ�\n");
	me->simple_action("$N���û�ι�ȥ����һﵽ����û������˵������\n");
	}
	else
	{
	tar->simple_action("$Nһ���֣�����$s���Ϲ����ᣬ��Ч������\n");
	score+=2;loyalty+=ladd+random(1);
	}
	}
	break;
	case 8:
	if(random(80)>loyalty)
	{
	tar->simple_action("$N���ٺٺ١���Ц������������ˣ�\n");
	score--;loyalty-=lsub;
	}
	else
	{
	if(random(3)>1)
	{
	tar->simple_action("$N�������ش���һ�����ã���ѽ���ղų�̫���ˡ�\n");
	me->simple_action("$N������һ���������������Ҳ���ȥ��̫�ؿ����нˮ���ԣ��Կ���ȥ���㣡\n");
	}
	else
	{
	tar->simple_action("$N���鼤����������Ȼ��$sԸ��һ��֮���������������Գɴ�ҵ��\n");
	score+=2;loyalty+=ladd+random(1);
	}
	}
	break;
	case 9:
	if(random(80)>loyalty)
	{
	tar->targetted_action("$N��Ц���������ҿ������ǰͲ�������̨������\n",me);
	}
	else
	{
	if(random(3)>1)
	{
	tar->simple_action("$NͻȻһ���Դ�����ѽ�������˭˭Լ�ҿ�Ϸȥ���š�����\n");
	me->simple_action("$N��ɫһ���һ��ף��üһˣ���ģ������\n");
	}
	else
	{
	tar->targetted_action("$N��$TЦ��������������ƽʱ�����İ�����$m$R�Ĺػ���$s���н��죿\n",me);
	score+=2;loyalty+=ladd+random(1);
	}
	}
	break;
	case 10:
	tar->simple_action("$Nһ���֣�����ˡ��Զ�ͣ���ǡ�\n");
	talk_over(obs);
	default:
	return;
	}      
	CHAR_D->set_char_loyalty(t_id,mnation,loyalty);
	me->set_job("visitofficer","score",score);
	call_out("select_way",1,obs);
}
void input_way(mixed obs,string str)
{	int p_select;
    object me=obs[0],usr,tar;
	string p_id;
	int *topics;
    remove_call_out("no_answer_way");
	p_select=to_int(str);
	if(!objectp(me)) return;
	p_id=me->query_id()[0];
	usr=find_user(p_id);
    if(!objectp(usr)) return;

    if((p_select<1)||(p_select>10)) return;
 	topics=me->query_job("visitofficer","topics");
    if(member_array(p_select,topics)!=-1)
    {  tell_user(p_id,"��������Ѿ�̸���ˣ��û�һ����\n");
       call_out("no_answer_way",30,obs);
       return;
    }
    usr->modal_pop();
	tar=obs[1];
	if(!objectp(tar)) {talk_over(obs); return;}
    me->targetted_action(sug[p_select-1]+"\n",tar);
	me->set_job("visitofficer","select",p_select);
	topics+=({p_select});
	me->set_job("visitofficer","topics",topics);
    call_out("judge_select",1,obs );
}

void no_answer_way(mixed obs)
{ input_way(obs,"10");
}

void select_way(mixed obs)
{
   object me=obs[0],usr;
   string p_id;
   if(!objectp(me)) return;
   p_id=me->query_id()[0];
   usr=find_user(p_id);
   if(!objectp(usr)) return;
   tell_user(p_id,"���Ŀ�ľ��Ǿ����������ˡ�\n"+
"������������������������������������������������������������\n"+
" 1 ��ά����  2 ��ά�ǻ�  3 ��ά����  4 ��������  5 ���ͱ��� \n"+
" 6 ����Ҹ�  7 �߹��ջ�  8 �Կ����  9 ���Ŀ佱 10 ���     \n"+
"������������������������������������������������������������\n"+
"��������Ļ���(1--10)��\n");
   call_out("no_answer_way",30,obs);
   usr->modal_push((: input_way,obs:),
        "��������Ļ���(1--10)��");

}
void talk_over(mixed obs)
{
    object me=obs[0],tar;
	string p_id,t_id;
	if(!objectp(me)) return;
	p_id=me->query_id()[0];
	tar=obs[1];
	if(objectp(tar)) {
		t_id=tar->query_id()[0];
		tar->responda("wave");
		tar->simple_action("$N�뿪�ˡ�\n");
		CHAR_D->remove_npc_char(t_id);
	}
	tell_user(p_id,"%^H_GREEN%^������ɵò�����ȥ̫�ش����Ͱɡ�\n%^RESET%^");
}
