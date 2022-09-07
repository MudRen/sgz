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
"$N��$T����$m$R�˵ز������ã��β����ٳ��ߣ���ľ���ܣ��Գɴ�ҵ��",
"$N��$T�������յü�$Rһ�棬��Ȼ�����鴫��ʱ�����磬$s���и�ǡ�",
});

void judge_select(mixed obs);
void input_way(mixed obs,string str);
void no_answer_way(mixed obs);
void select_way(mixed obs);
void talk_over(mixed obs);
void big_success(mixed obs);

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
          (CHAR_D->get_char($1,"nation")!=$(m_nation)) &&
		  (CHAR_D->get_char($1,"ranknation")!= R_KING))  // king cant be whisperd
	  :) );
   if(!mlist) mlist=({});
   if(!sizeof(mlist))
		return "$N��$T�������ûʲô�˺ò߷���\n";
   target=mlist[random(sizeof(mlist))];   	   
  o->set_asklist("whisper","target",target);
   o->set_asklist("whisper","filename",PJOB+"whisper/whisper");
   o->set_asklist("whisper","funname","ask_whisper");
  o->add_job("whisper");
  o->set_job("whisper","status","begin");
  o->set_job("whisper","memo","�߷�"+CHAR_D->get_char(target,"name")+"("+target+")");
   return "$N��$T���������˵"+
	  COUNTRY_D->get_country(CHAR_D->get_char(target,"nation"),"name")
	  +"��"+CHAR_D->get_char(target,"name")+"�Ĵ治����\n"+
	   "���鷳$Rȥ̽��һ�£������˵ask "+target+" about whisper��\n"+
	   "������ܣ����ɿ���������١�\n";
}

void ask_whisper(object me, object target)
{
	string t_area,t_id;
    string m_title,p_id;
	p_id=me->query_id()[0];
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
	target->set_leader(p_id);
	me->set_job("whisper","topics",({})); //haven't talk yet	                            
	                             // within 10 minute
	me->set_job("whisper","score",20); // meet is 20 
	                                   // because in other country
	                                      // succ is 100

	CHANNEL_D->deliver_tell("rumor","system",
	  COUNTRY_D->get_country(CHAR_D->get_char(p_id,"nation"),"name")+
	  "��"+CHAR_D->get_char(p_id,"name")+"����"+
	  COUNTRY_D->get_country(CHAR_D->get_char(t_id,"nation"),"name")+
	  "��"+CHAR_D->get_char(t_id,"name")+"��̸��");

	call_out("select_way",2,({ me, target}));
        CHAR_D->set_char(p_id,"catch_time",time()+600);
        CHAR_D->set_char(p_id,"catch_file","/sgdomain/job/whisper/whisper.c");
        CHAR_D->set_char(p_id,"catch_function","whisper_catch");
        CHAR_D->set_char(p_id,"catch_para",target);
CHAR_D->set_char(p_id,"catch_area",CHAR_D->get_char(t_id,"area"));	
return;
}

void whisper_catch(string o_id,string p_id,object o_general)
{
        object o_o,o_p;
        if(objectp(o_general)){
                string pep_id;
                tell_user(p_id,"׽��������ˣ��������ܣ�\n");
pep_id=o_general->query_id()[0];
                CHAR_D->remove_npc_char(pep_id);
        }
        o_p=find_user(p_id);
        if(objectp(o_p))
                o_p->modal_pop();
        o_o=find_body(o_id);
        if(!objectp(o_o)) return;
        o_p=find_body(p_id);
        if(!objectp(o_p)) {
                tell_user(o_id,"����һ����"+

CHAR_D->get_char(o_id,"name")+"���ˡ�\n��Ĺ����ɼ��½��ˡ�\n");
                o_o->set_job("partol","score",
                        o_o->query_job("partol","score")-1);
                return;
        }
        o_o->targetted_action(
                "$N��$T���һ������$r����Ȼ�ڴ�ɿ�����������¡�\n",o_p);
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
	string p_id,t_id,mnation,marea;
	mixed gift;
	int loyalty,score,p_select;
	int l_d=3,maxloyalty=90; // if higher then 90 hard to convince
	if(!objectp(me)) return;
	if(!objectp(tar)) {talk_over(obs); return;}
	p_id=me->query_id()[0];
	marea=CHAR_D->get_char(p_id,"area");
	t_id=tar->query_id()[0];
	gift=CHAR_D->get_char(t_id,"gift");
	loyalty=CHAR_D->get_char(t_id,"loyalty");
	score=me->query_job("whisper","score");
	p_select=me->query_job("whisper","select");
    switch(p_select)
    {    case 1:
         if((random(30)>gift["wuli"])&&
			 (random(maxloyalty)>loyalty))
		 {
            tar->simple_action("$N������������ſڿ���\n");
			tar->responda("heng"); score-=1;
         }
         else { 
          tar->simple_action("$N��������������˻�������\n");
	       score+=2; 
    	   loyalty-=random(l_d);
         }
         break;
       case 2:
         if((random(30)>gift["zhimou"])&&
		 	 (random(maxloyalty)>loyalty))
		 {
            tar->simple_action("$N������������ſڿ���\n");
			tar->responda("angry"); score-=1;
         }
         else {  
			tar->simple_action("$N��������������˻�������\n");
			score+=2; loyalty-=l_d;

         }
         break;
       case 3:
         if((random(30)>gift["meili"])&&
		 	 (random(maxloyalty)>loyalty))  {
            tar->simple_action("$N������������ſڿ���\n");
			tar->responda("puke"); score-=1;
         }
         else {
	tar->simple_action("$N��������������˻�������\n");
			score+=2; loyalty-=l_d;
         }
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
			score+=4; loyalty-=random(2);
         }
         break;
	   case 5:
		    tar->simple_action("$N���������Ȼ��û�кã��Ǿͻ�ͷ��˵�ɡ�\n");
		 break;
	   case 6:
		   if(random(maxloyalty)>loyalty) {
			tar->simple_action("$N��������������˻�������\n");
			   score+=2;loyalty-=l_d;
		   }
		   else {
			tar->simple_action("$N����$sƽ����ϲ������ֻΪ��֪��֮����\n");
			   score--;loyalty+=2;
		   }
		   break;
	   case 7:
		   if(random(maxloyalty)>loyalty) {
tar->simple_action("$N��������������˻�������\n");
			   score+=2;loyalty-=l_d;
		   }
		   else {
tar->simple_action("$N����$s����ʬ���������ѡ�\n");
			   score--;loyalty+=2;
		   }
		   break;
	   case 8:
		   if(random(maxloyalty)>loyalty) {
			   tar->simple_action("$N�����е����е���\n");
			   score+=2;loyalty-=l_d;

		   }
		   else {
			   tar->simple_action("$Nҡͷ���������Ѿ���������ԡ�\n");
			   score--;loyalty+=2;
		   }
		   break;
	   case 9:
		   if(random(maxloyalty/2)>loyalty) {
    tar->simple_action("$N����������ˣ�˵�հ���˼��\n");
		   big_success(obs);
		   return; 
		
		   }
		   else
			tar->targetted_action("$N���������Ѿ���$R����¡�\n",me);
		   break;
	   case 10:
		   tar->simple_action("$N����ˡ��Զ�ͣ���ǡ�\n");
		   talk_over(obs);
	   default:
			return;
    }      
	CHAR_D->set_char(t_id,"loyalty",loyalty);
	me->set_job("whisper","score",score);
	call_out("select_way",1,obs);
}
void input_way(mixed obs,string str)
{	int p_select;
    object me=obs[0],usr,tar;
	string p_id;
	int *topics;

	p_select=to_int(str);
    if((p_select<1)||(p_select>10)) return;
    remove_call_out("no_answer_way");

	if(!objectp(me)) return;
	p_id=me->query_id()[0];
	usr=find_user(p_id);
    if(!objectp(usr)) return;
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
	me->set_job("whisper","topics",topics);
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
   tell_user(p_id,"���Ŀ�ľ��Ǿ�������������\n"+
"������������������������������������������������������������\n"+
" 1 ��ά����  2 ��ά�ǻ�  3 ��ά����  4 ��������  5 ���ͱ��� \n"+
" 6 �߹��ջ�  7 ������в  8 �Կ����  9 ������Ȱ 10 ���     \n"+
"������������������������������������������������������������\n"+
"��������Ļ���(1--10)��\n");
   call_out("no_answer_way",30,obs);
   usr->modal_push((: input_way,obs:),
        "��������Ļ���(1--10)��");
}

void big_success(mixed obs)
{
    object me=obs[0],tar;
	string p_id,t_id,p_area;
	if(!objectp(me)) return;
	p_id=me->query_id()[0];
	tar=obs[1];
	if(objectp(tar)) {
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
	if(objectp(tar)) {
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

