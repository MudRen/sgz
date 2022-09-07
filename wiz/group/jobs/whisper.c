// the job of whisper a certain wise general
// by group on Mar 1999
static private string *sug=({
"$N��$T����$m$R��ǧ������֮�£�ֻ��ϧ����������������",
"$N��$T����$m$R���ǻ����һ����ɲ⣬�͸ÿ����˵ز��ǿɾ�֮�ء�",
"$N��$T����$m$R�д󽫷緶��ֻ�������ȴ�����ò�֮���ģ�",
"$N��$T����$m$R�����������������壬ֻ����Щ��������$RЦ�ɡ�",
"$N��$T����������Щ��������ֻ�����ڻ�û��. . . ",
"$N��$T������$m$R֮��ģ���ı������;֮·�����д�ɡ�",
"$N��$T����$m$R�粻�����ͷ������ֻ�������״�ѽ��",
"$N��$T�����ҹ���ǿ��׳���������㣬���ձؿ�һͳ���¡�",
"$N��$T����С�ع����$m$R�����Ѿã��β�������ľ���ܣ��Գɴ�ҵ��",
"$N��$T�������յü�$Rһ�棬��Ȼ�����鴫��ʱ�����磬$s���и�ǡ�",
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
   string m_nation=CHAR_D->get_char(officer_id,"nation");	
   string *mlist,target;
   object o=find_body(m_id);
   if(!objectp(o)) return 0; // string

   mlist=CHAR_D->check_char("type",TYPE_NPC);
   mlist=filter_array(mlist,
	   (: ((!CHAR_D->get_char($1,"is_tmp") ) &&
	      (CHAR_D->get_char($1,"nation") ) &&
(CHAR_D->get_char($1,"nation")!=$(m_nation))) :) );
   if(!mlist) mlist=({});
   if(!sizeof(mlist))
		return "$N��$T�������ûʲô�˺ò߷���\n";
  
   target=mlist[random(sizeof(mlist))];   	   
o->set_asklist("whisper","target",target);
   o->set_asklist("whisper","filename",PJOB+"whisper/whisper");
   o->set_asklist("whisper","funname","ask_whisper");

  o->add_job("whisper");
  o->set_job("whisper","status","begin");

o->set_job("whisper","memo","�߷�"+CHAR_D->get_char(target,"area")+CHAR_D->get_char(target,"name")+"("+target+")");
   
   return "$N��$T���������˵"+CHAR_D->get_char(target,"area")+"��һ������Ի"+CHAR_D->get_char(target,"name")+"("+target+")��\n"+
	   "���鷳$Rȥ̽��һ�£������˵ask "+target+" about whisper��\n"+
	   "������ܣ�������������١�\n";
}

void ask_whisper(object me, object target)
{
	string t_area,t_id;
    string m_title;
	t_id=target->query_id()[0];
	t_area=CHAR_D->get_char(t_id,"area");
    m_title=OFFICER_D->query_rank_name(
        (OFFICER_D->query_area_officer_title(
         AREA_D->get_area(t_area,"level"),0,0))[0]);
	me->targetted_action(
      "$N��$TЦ��˵��������"+m_title+"��$s����$m$R������\n"
	  +"������������һ����\n",target);
	DELAY_D->delay_targetted_action(
		target,me,"$N��$T�������Ҹ�Ϊ���������ؿ���\n",1);
	me->clear_asklist("whisper");
	me->set_job("whisper","status","done");
	target->special_heart(600); // will now go around or do semote
	me->set_job("whisper","topics",({})); //haven't talk yet	                            
	                             // within 10 minute
	me->set_job("whisper","score",10); // meet is 10
	                                      // succ is 50
	call_out("select_way",2,({ me, target}));
	return;
}

void judge_select(mixed obs)
{
    object me=obs[0],tar=obs[1];
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
	score=me->query_job("whisper","score");
	p_select=me->query_job("whisper","select");
    switch(p_select)
    {    case 1:
         if(random(30)>gift["wuli"])  {
            tar->simple_action("$N������������ſڿ���\n");
			tar->responda("heng"); score-=1;
         }
         else { if(random(loyalty)<30){ 
          tar->simple_action("$N��������������˻�������\n");
			score+=2; loyalty-=3;}
         }
         break;
       case 2:
         if(random(30)>gift["zhimou"])  {
            tar->simple_action("$N������������ſڿ���\n");
			tar->responda("angry"); score-=1;
         }
         else {  if(random(60)>loyalty){
	tar->simple_action("$N��������������˻�������\n");
			score+=2; loyalty-=2;
         }}
         break;
       case 3:
         if(random(30)>gift["meili"])  {
            tar->simple_action("$N������������ſڿ���\n");
			tar->responda("puke"); score-=1;
         }
         else {if(random(loyalty)<30){  
	tar->simple_action("$N��������������˻�������\n");
			score+=2; loyalty-=2;
         }}
         break;
	   case 4:
         if(me->query_all_con_money()<10000) {
			tell_user(p_id,"������û����Ǯ��\n");
			 tar->simple_action("$N�������Ǻ��֡�\n");
			tar->responda("angry"); score-=2;
         }
         else
         {  me->set_all_con_money( me->query_all_con_money() -10000 );
			me->targetted_action("$N����$Tһ�����ӡ�\n",tar);
		    tar->simple_action("$Nһ��˵����Ҫ������Ҫ��һ�����İѽ��Ӵ������\n");
			score+=4; loyalty-=1;
         }
         break;
	   case 5:
		    tar->simple_action("$N���������Ȼ��û�кã��Ǿͻ�ͷ��˵�ɡ�\n");
		 break;
	   case 6:
		   if(random(60)>loyalty) {
tar->simple_action("$N��������������˻�������\n");
			   score+=2;loyalty-=3;
		   }
		   else {
tar->simple_action("$N����$sƽ����ϲ������ֻΪ��֪��֮����\n");
			   score--;loyalty+=2;
		   }
		   break;
	   case 7:
		   if(random(60)>loyalty) {
tar->simple_action("$N��������������˻�������\n");
			   score+=2;loyalty-=2;
		   }
		   else {
tar->simple_action("$N����$s����ʬ���������ѡ�\n");
			   score--;loyalty+=2;
		   }
		   break;
	   case 8:
		   if(random(60)>loyalty) {
tar->simple_action("$Nҡͷ���������Ѿ���������ԡ�\n");
			   score--;loyalty+=2;
		   }
		   else {
			   tar->simple_action("$N�����е����е���\n");
			   score+=2;loyalty-=2;
		   }
		   break;
	   case 9:
		   if(random(50)+50>loyalty) {
tar->targetted_action("$N���������Ѿ���$R����¡�\n",me);
		   }
		   else
{tar->targetted_action("$N����������ˣ�˵�հ���˼��\n");
		score+=2; loyalty-=3;

			   }
		   
		   break;
	   case 10:
		   tar->simple_action("$N����ˡ��Զ�ͣ���ǡ�\n");
		   talk_over(obs);
	   default:
			return;
    }      

	CHAR_D->set_char_loyalty(t_id,mnation,loyalty);
	me->set_job("whisper","score",score);

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
 	topics=me->query_job("whisper","topics");
    if(member_array(p_select,topics)!=-1)
    {  tell_user(p_id,"��������Ѿ�̸���ˣ��û�һ�����⡣\n");
       call_out("no_answer_way",30,obs);
       return;
    }

    usr->modal_pop();
	tar=obs[1];
	if(!objectp(tar)) {talk_over(obs); return;}

    me->targetted_action(sug[p_select-1]+"\n",tar);
	me->set_job("whisper","select",p_select);
	topics+=({p_select});
	me->set_job("visitwise","topics",topics);
    call_out("judge_select",1,obs );
}

void no_answer_way(mixed obs)
{ input_way("10",obs);
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
" 6 �߹��ջ�  7 ������в  8 �Կ����  9 ������Ȱ 10 ���     \n"+
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
	}
	tell_user(p_id,"%^H_BLUE%^����ɹ�����ȥ̫�ش����Ͱɡ�\n%^RESET%^");
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
	tell_user(p_id,"%^H_GREEN%^������ɲ�����ȥ̫�ش����Ͱɡ�\n%^RESET%^");
}
