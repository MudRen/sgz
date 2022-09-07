// the job of visit  people
// by fire on March 1999

static private string *sug=({
"$N�Ժ��ض���$T�������ǵ����ڣ��������������͵��ˡ�",
"$N���еض���$T����$s֪�����Ƕ����Һ���ʵ���ˣ�������һ������а����",
"$N��̾�ض���$T�������ǵĴ�������Զ��������û�����ǣ������ҹ������ǿʢ��",
"$N�ػ��ض���$T����ս��ʱ�ڣ�������ƶ����ЩǮ�������ȥ�����ɡ�",
"$N�ػ��ض���$T����$s֪������࣬�Ҽ������е���ʳ����Ҿ���ȥ�˰ɡ�",
"$N΢Ц�Ŷ���$T���������������ɺ�ѽ��",
"$N�����ض���$T����$s֪����������ѣ��´���һ������̫���⸳��˰��",
"$N�Ͽҵض���$T�����ҹ������������������յ�����ѽ��",
"$NЦ�����ض���$T��������̫������ͻ�������յ����ӵ�����Խ��Խ���ˡ�",
"$Nһ��ȭ������$T����ʱ�����磬$s����æ�����и�ǡ�",
});

static private string *good_answer=({
"��$N�׷׵�ͷ������ɲ�����",
"��$N�׷׵�ͷ�������ѽ��",
"��$N�׷׵�ͷ������ǵ�Ȼ����",
"$T��Ǯ�����ó�һ�����ӽ���$N�ǡ�\n��$N���˵�����������",
"$T֪ͨ�Ҷ�Ϊ$N��ȡһ����ʳ��\n��$N���˵�����������",
"��$NЦ�ŵ������������û�������",
"��$Næ�����ص�ͷ������̫���ˣ�",
"��$N�׷׵�ͷ�������ѽ������Ҳ����ô��ġ�",
"��$N�׷׵�ͷ������ԣ�����һ��ӵ������",
"��$N�׷׵�ͷ�����лл$R�Ĺػ���",
});

static private string *bad_answer=({
"һ��$N���Ű��ۣ���������͹�ʲô�ã������Ǹ����˰׸ɣ���",
"һ��$N���ޡ���һ���������Խ��ʵԽ���۸����ߡ�",
"һ��$N����$T��������ɻ�����ֻ�е��ٵĲ������ܣ���",
"$T���˰���ڴ���ͻȻ��������������˼������û��Ǯ��\n��$N������Ц����������˭ѽ�����ٵ����ϻ�ûǮ��",
"$T����˰��죬ͻȻ��������������˼������Ҳû�ж�����ʳ�ˡ�\n��$N������Ц������Ц�������ٵļ����û�����ԣ�",
"һ��$N��Ц�����Ͳ�û�����ˡ�",
"һ��$N��м�ص����������ġ�\n��$N�׷׸��ϵ�����ţ����ţ��",
"һ��$N�ڿ���������\n��$N�����ߺߡ���Ц������",
"һ��$N�޺޵ص������𣿿������ǵ����Ӿ�֪���ˡ�\n��$N�����ߺߡ���Ц������",
"��$N�׷״������Ͳ�������ķϻ������ߣ����ߡ�",
});


void judge_select(mixed obs);
void input_way(mixed obs,string str);
void no_answer_way(mixed obs);
void select_way(mixed obs);
void talk_over(mixed obs);
void big_success(mixed obs,mixed vac);
string m_area;

mixed job(string m_id,string officer_id)
{
	object *mlist,ot;
	string target;
	object o=find_body(m_id);
	if(!objectp(o)) return 0; // string
	m_area=CHAR_D->get_char(officer_id,"area");
	target=m_area+" guy";
	ot=CHAR_D->find_npc_char(target);

//Modified By listen to avoid visit fake people
   if(!objectp(ot) || ot->query("is_fake")) 
   {
		target=m_area+" resident";
		ot=CHAR_D->find_npc_char(target);
		if(!objectp(ot) || ot->query("is_fake"))
		{
			target=m_area+" idler";
			ot=CHAR_D->find_npc_char(target);
			if(!objectp(ot) || ot->query("is_fake")){
				o->add_job("visitpeople");	
				o->finish_job("visitpeople");
				return "$N��$Tҡҡͷ��̾�����������ң������������ն���֪������ȥ�ˡ�\n";
			}
		}
	}
/*
   mlist=children("/sgdomain/modules/m_charnpc/guy");
   if(sizeof(mlist)) {
      mlist=filter_array(mlist,(:$1->get_area()==$(m_area) :));
   }
   if(!sizeof(mlist))
	   return "$N��$Tҡҡͷ��̾�����������ң������������ն���֪������ȥ�ˡ�\n";

*/

//   ot=mlist[random(sizeof(mlist))];
//   target=ot->query_id()[0];
	ot->set("is_locked",1);
	o->set_asklist("hi","target",target);
	o->set_asklist("hi","filename",PJOB+"visitpeople/visitpeople");
	o->set_asklist("hi","funname","ask_hi");

	o->add_job("visitpeople");
	o->set_job("visitpeople","status","begin");
	o->set_job("visitpeople","memo","̽��"+ot->short());
   
   return "$N��$TЦ����������Ϊ�������鷳$Rȥ̽��һ��"+
	   ot->short()+
	   "��\n�����˵ask "+target+" about hi ��\n";
}
void ask_hi(object me, object target)
{
	mixed ret;
	string m_id;
    string m_title;
	m_id=me->query_id()[0];
	m_area=me->query_room()->get_area();
    m_title=OFFICER_D->query_rank_name(
        (OFFICER_D->query_area_officer_title(
         AREA_D->get_area(m_area,"level"),0,0))[0]);
	me->targetted_action(
      "$N����$TЦ��������������������"+m_title+"�ص���$s��̽�����ǡ�\n"
	  ,target);

//	ret=target->can_ask_for_join(m_id);
//        if(stringp(ret)) {
//		target->targetted_action(ret,me);
//		return;
//	}

	me->clear_asklist("hi");
	me->set_job("visitpeople","status","done");
	me->set_job("visitpeople","score",10); // meet is 10
	                                      // succ is 50


    if(sizeof(target->query_pure_leader())) {
		target->targetted_action("$N��$T����������æ�ء�\n",me);
	   tell_user(m_id,"%^H_GREEN%^�����Ѿ��������ˣ�Ӧ�ÿ���ȥ�����ˡ�\n%^RESET%^");
		target->check_leader();

		return;
	}
	
	DELAY_D->delay_targetted_action(
		target,me,"һ��$N����������ץ���ǰɡ�\n"+
		"��һ��$N�������ᣬ$m$R�����ǻ��ˡ�\n",1);
	
	target->set_leader(m_id); // target will not do nonsence

	me->set_job("visitpeople","topics",({})); //haven't talk yet	                            
	                             // within 10 minute
	call_out("select_way",2,({ me, target}));
	return;
}

void judge_select(mixed obs)
{
    object me=obs[0],tar=obs[1];
	string p_id,t_id,mnation,marea;
	mixed gift;
	int ans=0;
	int safe,score,p_select,meili;

	if(!objectp(me)) {talk_over(obs); return;}
	if(!objectp(tar)) {talk_over(obs); return;}

	p_id=me->query_id()[0];
	marea=me->query_room()->get_area();

	t_id=tar->query_id()[0];
	
	gift=CHAR_D->get_char(p_id,"gift");
	meili=gift["meili"];

	mnation=CHAR_D->get_char(p_id,"nation");
	safe=AREA_D->get_area(marea,"safe");

	score=me->query_job("visitpeople","score");

	p_select=me->query_job("visitpeople","select");

    switch(p_select)
    {
	case 1:
	case 2:
	case 3:
	case 7:
	case 8:
	case 9:
         if(random(30)>meili) 
			 ans=-1;
		 else
			 ans=1;
		 break;
	case 6:
		if(random(100)>safe)
			ans=-1;
		else
			ans=1;
		break;
	case 4:
         if(me->query_all_con_money()<10000) 
			 ans=-1;
		 else
		 {
			 ans=1;
			me->set_all_con_money(
				me->query_all_con_money() -10000 );
		 }
		 break;
	case 5:
		{
		   mixed my_army;
		   my_army=CHAR_D->get_char(p_id,"myarmy");
		   if(!my_army)
		   {   ans=-1;
		   }
		   else
		   {   if((!my_army["food"])||(my_army["food"]<100))
				   ans=-1;
			   else
			   {
				   ans=1;
				   my_army["food"]-=100;
				   CHAR_D->set_char(p_id,"myarmy",my_army);
			   }
		   }
		}
		break;
	case 10:
		ans=-1;
		if(score>10)
			ans=1;
		break;
	default:

		ans=1;
	}
	if(ans==1)
	{
		safe++;
		score+=2;
		tar->targetted_action(good_answer[p_select-1]+"\n",me);
	}
	else
	{
		safe--;
		score-=1;
		tar->targetted_action(bad_answer[p_select-1]+"\n",me);
	}
	AREA_D->set_area(marea,"safe",safe);
	me->set_job("visitpeople","score",score);
	if(p_select==10) // leave;
	{
		call_out("talk_over",1, obs);
		return;
	}
	call_out("select_way",1,obs);
}
void input_way(mixed obs,string str)
{	int p_select;
    object me=obs[0],usr,tar;
	string p_id;
	int *topics;
    remove_call_out("no_answer_way");


	tar=obs[1];
	if(!objectp(tar)) {talk_over(obs); return;}
	if(!tar->check_leader()) {talk_over(obs); return;}

	p_select=to_int(str);
	if(!objectp(me)) { talk_over(obs); return; }


    if((p_select<1)||(p_select>10)) return;
 	topics=me->query_job("visitpeople","topics");

    if(member_array(p_select,topics)!=-1)
    {  tell(me,"��������Ѿ�̸���ˣ��û�һ����\n");
       call_out("no_answer_way",30,obs);

       return;
    }

	p_id=me->query_primary_id();
	usr=find_user(p_id);
    if(objectp(usr)) 
	    usr->modal_pop();


    me->targetted_action(sug[p_select-1]+"\n",tar);
	me->set_job("visitpeople","select",p_select);
	topics+=({p_select});
	me->set_job("visitpeople","topics",topics);
    call_out("judge_select",1,obs );
}

void no_answer_way(mixed obs)
{ input_way(obs,"10");
}

void select_way(mixed obs)
{
   object me=obs[0],usr;
   string p_id;
   if(!objectp(me)) {talk_over(obs); return; }
   p_id=me->query_id()[0];
   usr=find_user(p_id);
   if(!objectp(usr)) return;
   tell_user(p_id,"��Ĺ������Ǻ����ǿ��ġ�\n"+
"������������������������������������������������������������\n"+
" 1 ��������  2 �����Һ�  3 �����ܸ�  4 ���ͻƽ�  5 ������ʳ \n"+
" 6 �������  7 ��Ӧ��˰  8 �佱����  9 �佱̫�� 10 ���     \n"+
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
        tar=obs[1];
        if(objectp(tar)) {
                t_id=tar->query_id()[0];
                tar->responda("wave");
                tar->simple_action("$N�뿪�ˡ�\n");
			    tar->do_my_dispear();

        }
        if(!objectp(me)) return;
        p_id=me->query_id()[0];

	tell_user(p_id,"%^H_GREEN%^������ɵò�����ȥ̫�ش����Ͱɡ�\n%^RESET%^");
}
