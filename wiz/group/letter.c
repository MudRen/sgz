// the job of send a letter to wise people
// by group on Mar 1999
static private string *sug=({
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
	   (:  (CHAR_D->get_char($1,"nation") ) &&
          (CHAR_D->get_char($1,"nation")!=$(m_nation)) 
	  :) );
   if(!mlist) mlist=({});
   if(!sizeof(mlist))
		return "$N��$T�������ûʲô����Ҫ���ŵ�\n";
   target=mlist[random(sizeof(mlist))];   	   
  o->set_asklist("letter","target",target);
   o->set_asklist("letter","filename",PJOB+"letter/letter");
   o->set_asklist("whisper","funname","ask_letter");
  o->add_job("letter");
  o->set_job("letter","status","begin");

o->set_job("letter","memo","����"+CHAR_D->get_char(target,"name")+"("+target+")");
   return "$N��$T�����뽫��������"+
	  COUNTRY_D->get_country(CHAR_D->get_char(target,"nation"),"name")
	  +"��"+CHAR_D->get_char(target,"name")+"\n"+
	   "���鷳$Rȥ̽��һ�£������˵ask "+target+" about letter��\n"
	   ;
}

void ask_letter(object me, object target)
{
	int loyalty,m_loyalty,t_loyalty;	
    string t_area,t_id;
    string m_title,p_id,mnation,tnation;
	p_id=me->query_id()[0];
	t_id=target->query_id()[0];
	t_area=CHAR_D->get_char(t_id,"area");
    m_title=OFFICER_D->query_rank_name(
        (OFFICER_D->query_area_officer_title(
         AREA_D->get_area(t_area,"level"),0,0))[0]);
	me->targetted_action(
      "$N��$TЦ��˵��������"+m_title+"��$s����$m$R������\n"
	  +"�����س�������һ��\n",target);
	DELAY_D->delay_targetted_action(
		target,me,"$N��$T�����ޣ�����һ��\n",1);
	me->clear_asklist("letter");
	me->set_job("letter","status","done");
	target->special_heart(600); // will now go around or do semote
	me->set_job("letter","score",20); // meet is 20 
	                                   // because in other country
	                                      // succ is 100
        mnation=CHAR_D->get_char(p_id,"nation");
        tnation=CHAR_D->get_char(t_id,"nation");
	m_loyalty=CHAR_D->get_char_loyalty(t_id,mnation);
        t_loyalty=CHAR_D->get_char_loyalty(t_id,tnation);
        loyalty= m_loyalty - t_loyalty*2/3;
        if (loyalty<0)loyalty = 0;
        switch(random(loyalty)/20)
{       case 0:
        case 1:
	DELAY_D->delay_targetted_action(
	target,me,"$N��$Tŭ�������¾�����Ϊ�������ǿ���ն��ʹ�����ն�꣡\n",1); 
        m_loyalty= m_loyalty -5;
        break;
        case 2:
        DELAY_D->delay_targetted_action(
        target,me,"$N��$T����������ˣ�ˡ�Ҳ��ܽ��ܡ�������ء�\n",1);
	m_loyalty= m_loyalty +1;
        break;
        case 3:
        DELAY_D->delay_targetted_action(
        target,me,"$N��$T����������֮����������ϸ˼��\n",1);
	m_loyalty= m_loyalty +5;
        break;
	case 4:
        case 5:
        DELAY_D->delay_targetted_action(
        target,me,"$N��$T����������֮������ظ����ˣ����Ե���ˡ�\n",1);
	m_loyalty =m_loyalty +5;
        call_out("big_success",2,({ me, target}));
	break;
}       
        CHAR_D->set_char_loyalty(t_id,mnation,m_loyalty); 
tell_user(p_id,"%^H_GREEN%^������ɲ�����ȥ̫�ش����Ͱɡ�\n%^RESET%^");
return;
}

void big_success(mixed obs)
{
    object me=obs[0],tar;
        mixed vac;
        int loyalty;
        string p_id,t_id,p_area,mnation;
        if(!objectp(me)) return;
        p_id=me->query_id()[0];
        tar=obs[1];
        if(objectp(tar)) {
                t_id=tar->query_id()[0];
                tar->responda("wave");
                tar->simple_action("$N�뿪�ˡ�\n");
                CHAR_D->remove_npc_char(t_id);
        }
        switch(random(3))
    {   case 0:
        p_area=CHAR_D->get_char(p_id,"area");
        CHAR_D->set_char(t_id,"area",p_area);
        CHANNEL_D->deliver_tell("rumor","system",
  	sprintf("%s����%sȥ�ˣ�",CHAR_D->get_char(t_id,"name"),
 		AREA_D->get_area(p_area,"name")));
	break;
	case 1:          
        (EV_LEAVE)->leave(t_id);     
        break;
        case 2:
        p_area=CHAR_D->get_char(p_id,"area");
        vac=(EV_POSITION)->get_area_vacancy(p_area);
        (EV_POSITION)->give_position(t_id,vac[random(sizeof(vac))],p_area);
        break;
        case 3:
        case 4:
        case 5:
       mnation=CHAR_D->get_char(p_id,"nation"); 
       loyalty=CHAR_D->get_char_loyalty(t_id,mnation);        
       loyalty= loyalty +5;
       CHAR_D->set_char_loyalty(t_id,mnation,loyalty);
       break;
}
me->set_job("letter","score",50);

tell_user(p_id,"%^H_BLUE%^������ȫ�ɹ�����ȥ̫�ش����Ͱɡ�\n%^RESET%^");
}
