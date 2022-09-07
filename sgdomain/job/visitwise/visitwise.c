// the job of visit a certain wise people
// by fire on Jan 1999
static private string *sug=({
"$N��$TЦ����$m$R����򲻵�֮�£�$s����������������",
"$N��$TЦ����$m$R���ǻ����һ����ɲ⣬$s�������˵�ˡ�",
"$N��$TЦ����$m$R�д󽫷緶��ͬʱ���ι��з���$s�������Ѿá�",
"$N��$TЦ����$m$R�����������������壬ֻ����Щ��������$RЦ�ɡ�",
"$N��$TЦ����������Щ��������ֻ�����ڻ�û�С�����",
"$N��$Tһ���֣�������$m$R�߼����ɷ�ָ��$sһ����",
"$N��$TЦ������$m$R֮��������ı��;֮·�����д�ɡ�",
"$N��$TЦ�����ҹ���ǿ��׳���������㣬���ձؿ�һͳ���¡�",
"$N��$TЦ�������ع����$m$R��Ľ�Ѿã�$R�β��ڴ�ıһ��ְ���Գɴ�ҵ��",
"$N��$Tһ��ȭ���������յü�$Rһ�棬��Ȼ�����鴫��ʱ�����磬$s���и�ǡ�",
});
void judge_select(mixed obs);
void input_way(mixed obs,string str);
void no_answer_way(mixed obs);
void select_way(mixed obs);
void talk_over(mixed obs);
void big_success(mixed obs,mixed vac);

mixed job(string m_id,string officer_id)
{
   string m_area=CHAR_D->get_char(officer_id,"area");
   string *mlist,target;
   object o=find_body(m_id);
   if(!objectp(o)) return 0; // string

   mlist=CHAR_D->check_char_area("type",TYPE_NPC,m_area);
   mlist=filter_array(mlist,
	   (: ((!CHAR_D->get_char($1,"is_tmp") ) &&
	      (!CHAR_D->get_char($1,"nation") )  ) :) );
   if(!mlist) mlist=({});
   if(!sizeof(mlist)){
		o->add_job("visitwise");
		o->finish_job("visitwise");
		return "$N��$Tҡҡͷ���������������û��˵�д��ͳ��֡�\n";
	}
   target=mlist[random(sizeof(mlist))];
   o->set_asklist("visit","target",target);
   o->set_asklist("visit","filename",PJOB+"visitwise/visitwise");
   o->set_asklist("visit","funname","ask_visit");

  o->add_job("visitwise");
  o->set_job("visitwise","status","begin");
  o->set_job("visitwise","memo","�ݷ�"+CHAR_D->get_char(target,"name")+"("+target+")");
   
   return "$N��$T���������˵��������һ������Ի"+CHAR_D->get_char(target,"name")+"("+target+")��\n"+
	   "���鷳$Rȥ̽��һ�£������˵ask "+target+" about visit ��\n"+
	   "������ܣ�������������١�\n";
}
void ask_visit(object me, object target)
{
	string m_area,m_id;
    string m_title;
	m_id=me->query_id()[0];
	m_area=CHAR_D->get_char(m_id,"area");
    m_title=OFFICER_D->query_rank_name(
        (OFFICER_D->query_area_officer_title(
         AREA_D->get_area(m_area,"level"),0,0))[0]);
	me->targetted_action(
      "$N��$TЦ��˵��������"+m_title+"��$s����$m$R������\n"
	  +"������������һ����\n",target);
	DELAY_D->delay_targetted_action(
		target,me,"$N��$TЦ����������$m$R�αع�ǫ��\n",1);
	me->clear_asklist("visit");
	me->set_job("visitwise","status","done");
	target->special_heart(600); // will now go around or do semote
	me->set_job("visitwise","topics",({})); //haven't talk yet	                            
	                             // within 10 minute
	me->set_job("visitwise","score",10); // meet is 10
	                                      // succ is 50
	call_out("select_way",2,({ me, target}));
	return;
}

void judge_select(mixed obs)
{
    object me=obs[0],tar=obs[1];
	int ladd=3,lsub=2;
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
	score=me->query_job("visitwise","score");
	p_select=me->query_job("visitwise","select");
    switch(p_select)
    {    case 1:
         if(random(30)>gift["wuli"])  {
            tar->simple_action("$Nһ���ۣ������㲻���ڷ���Ұɣ�\n");
			tar->responda("heng"); score-=1;loyalty-=lsub;
         }
         else {  tar->simple_action("$N������Ц����������������\n");
			score+=2; loyalty+=ladd;
         }
         break;
       case 2:
         if(random(30)>gift["zhimou"])  {
            tar->simple_action("$N��Цһ����������л��$s������֪֮����\n");
			tar->responda("angry"); score-=1;loyalty-=lsub;
         }
         else {  tar->simple_action("$N������Ц����������������\n");
			score+=2; loyalty+=ladd;
         }
         break;
       case 3:
         if(random(30)>gift["meili"])  {
            tar->simple_action("$N���ߡ���һ����������ɵ��棿\n");
			tar->responda("puke"); score-=1;loyalty-=lsub;
         }
         else {  tar->simple_action("$N������Ц����������������\n");
			score+=2; loyalty+=ladd;
         }
         break;
	   case 4:
         if(me->query_all_con_money()<10000) {
			tell_user(p_id,"������û����Ǯ��\n");
			 tar->simple_action("$Nҡͷ�������Ǻ��֡�\n");
			tar->responda("angry"); score-=2;loyalty-=lsub;
         }
         else
         {  me->set_all_con_money( me->query_all_con_money() -10000 );
			me->targetted_action("$N����$Tһ�����ӡ�\n",tar);
		    tar->simple_action("$N���ϲ�ס�ƴǣ�һ��ȴ���İѽ��Ӵ������\n");
			score+=4; loyalty+=ladd;
         }
         break;
	   case 5:
		    tar->simple_action("$NЦ���������Ȼ��û�кã��Ǿͻ�ͷ��˵�ɡ�\n");
		 break;
	   case 6:
		   if(random(60)>loyalty) {
			   tar->simple_action("$N��������һ����������������ʲô�߼���Ц����\n");
			   score--;loyalty-=lsub;
		   }
		   else {
			   tar->simple_action("$Nҡͷ����һ����������$s֮��������ɳ�Ӣ���ߣ��ˡ�����\n");
			   score+=2;loyalty+=ladd;
		   }
		   break;
	   case 7:
		   if(random(60)>loyalty) {
			   tar->simple_action("$Nһ���֣�����$s�εº��ܣ����Ҵӹ٣�\n");
			   score--;loyalty-=lsub;
		   }
		   else {
			   tar->simple_action("$Nһ���֣�������������һ�գ������Ϲ����ᡣ����\n");
			   score+=2;loyalty+=ladd;
		   }
		   break;
	   case 8:
		   if(random(60)>loyalty) {
			   tar->simple_action("$N���ٺٺ١���Ц������������ˣ�\n");
			   score--;loyalty-=lsub;
		   }
		   else {
			   tar->simple_action("$N��ס��ͷ���е����е���\n");
			   score+=2;loyalty+=ladd;
		   }
		   break;
	   case 9:
		   if(random(50)+50>loyalty) {
			   tar->targetted_action("$NЦ����$s�������������˾��ѣ�$R����¡�\n",me);
		   }
		   else {
				int* vac;
			   vac=(EV_POSITION)->get_area_vacancy(marea);
			   if(sizeof(vac)){
				if((stringp(CHAR_D->get_char(t_id,"nation")))||(CHAR_D->get_char(t_id,"retire")>time()))
				{
					tar->simple_action("$N̾����$s�������ʵ�������ɼ�ѽ��\n");
					break;
				}
				else
				{
					CHAR_D->set_char(t_id,"retire",0);
				   tar->targetted_action("$N��$Tһ����$R֪��֮����$sû�ݲ�����$m$R������һ���������͵���\n",me);
				   big_success(obs,vac);
					return;
				}

				   
			   }
			   else {
					tar->simple_action("$N�������ع�ְ����û�п�ȱ�����ҿ�ʲô��ѽ��\n");
					score--;loyalty-=lsub;
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
	me->set_job("visitwise","score",score);

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
 	topics=me->query_job("visitwise","topics");
    if(member_array(p_select,topics)!=-1)
    {  tell_user(p_id,"��������Ѿ�̸���ˣ��û�һ����\n");
       call_out("no_answer_way",30,obs);
       return;
    }

    usr->modal_pop();
	tar=obs[1];
	if(!objectp(tar)) {talk_over(obs); return;}

    me->targetted_action(sug[p_select-1]+"\n",tar);
	me->set_job("visitwise","select",p_select);
	topics+=({p_select});
	me->set_job("visitwise","topics",topics);
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
" 6 ����Ҹ�  7 �߹��ջ�  8 �Կ����  9 �������� 10 ���     \n"+
"������������������������������������������������������������\n"+
"��������Ļ���(1--10)��\n");
   call_out("no_answer_way",30,obs);
   usr->modal_push((: input_way,obs:),
        "��������Ļ���(1--10)��");

}
void big_success(mixed obs,mixed vac)
{
    object me=obs[0],tar;
	string p_id,t_id,p_area;
	if(!objectp(me)) return;
	p_id=me->query_id()[0];
	tar=obs[1];
	p_area=CHAR_D->get_char(p_id,"area");
	if(objectp(tar)) {
		t_id=tar->query_id()[0];
		tar->responda("wave");
		tar->simple_action("$N�뿪�ˡ�\n");
		CHAR_D->remove_npc_char(t_id);
        (EV_POSITION)->give_position(t_id,vac[random(sizeof(vac))],p_area);
	}
	me->set_job("visitwise","score",50);
	tell_user(p_id,"%^H_BLUE%^������ȫ�ɹ�����ȥ̫�ش����Ͱɡ�\n%^RESET%^");
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