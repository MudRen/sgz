// the job of fan  people
// by fire on March 1999

static private string *sug=({
"$Nͬ��ض���$T���������������������͵��ˣ���ȴ�Բ���������ů��",
"$N�п��ض���$T�������Ƕ�̫�Һ��ˣ����Ծ��ܵ����ǵ���ѹ��",
"$N̾�˿���������$T�������ǵĴ�������Զ��������ֻ��û������������ϧѽ��ϧ��",
"$N�󷽵ض���$T����ս��ʱ�ڣ��������ƶ�࣬��ЩǮ����ȥ�����԰ɡ�",
"$N�󷽵ض���$T����$s��֪�����࣬�Ҵ��Լ�������Щ��ʳ����ҷ��˰ɡ�",
"$N���ĵض���$T����������������ô����һ���ܿ�ɣ�",
"$N�ѹ��ض���$T��������������ô���ѣ����ػ�����ô�ص�˰���治֪����������ô�����ӵġ�",
"$N�޷޲�ƽ�ض���$T������������������һ���Ƿǲ����Ĵ�����",
"$Nҡҡͷ������$T��������̫���б�˽�ң��ϰ��յ����ӵ������Ѱ�ѽ��",
"$N����$Tһ���֣�����Ѳ�ߵĿ�����ˣ��ҵ����ˣ���ǡ�",
});

static private string *good_answer=({
"��$N������̾���������ɲ�����",
"һ��$N�޷޵ص����׻�˵�ĺã����Ʊ�������Ʊ����ۣ�\n��$N�����ϵ���û�����Ǿ���̫��ʵ�ˡ�",
"��$N��ҡҡͷ��ʧ���ص����ڲ�����ѽ������",

"$T��$N��һ�����ӡ�\n��$N�����˵�����������\n��$N�׷׵������صĹٶ���û��ô�ƴ������ǡ�",
"$T֪ͨ�Ҷ�Ϊ$N��ȡһ����ʳ��\n��$N�����˵�����������\n$N�׷׵������صĹٴ�û��ô�ƴ������ǡ�",
"��$N���޺޵ص����������Խ��Խ��⣬�Ͳ�û�������ˡ�",
"һ��$Nҧ���гݵ������ٵ�ֻ֪�������ǵ�Ƥ���Լ�ȴ��ٺ»���֣�\n��$N�����ϵ������ǣ��⻹�ò����˻��ˣ���",
"һ��$N�̲�ס��������Ҫ���Ǽ���������С������ͷ��ˣ�\n��һ��$N�Ͻ��������죺С���㣬���������������ˡ�",
"��$N�����εص���������֪ǰ������ʲô����̯����ô������",
"��$N�׷׵�ͷ�������л$R�Ĺػ����ɱ�������ץס�ˡ�",
});

static private string *bad_answer=({
"һ��$N�����˭˵�ģ����������ӹ�����������\n��$N�׷׵�ͷ��û��",
"һ��$N�����˭�۸��������ţ��ҹ���Ա�Ƕ���Ŭ���������ҡ�\n��$N�׷׵�ͷ���ԣ�һ�µ����������ԡ�",
"һ��$NЦ�������ǹ������ģ�һ����֪���㲻�����⡣\n��$N��������Ц������",
"$T����������ڴ���ͻȻ��������������˼������û��Ǯ��\n��$N��������Ц��������˭ѽ�����ٵ����ϻ�ûǮ��",
"$T����˰��죬ͻȻ��������������˼������Ҳû������ʳ�ˡ�\n��$N������Ц������Ц�������ٵļ����û���ԣ�",
"һ��$Nҡҡͷ�����������˵����Ҷ�������ʳ��\n��$N���׷׵�ͷ���ɲ�����",
"һ��$N���ߡ���һ�������������ģ�Ŀǰ˰�ʺܹ�ƽ��",
"һ��$N��Ц���������ҿ����������ǿ��\n��$N����Ц������",
"һ��$N���ٺ١�Ц�������ֲ��Ǳ����ˣ���ô֪�����ҿ������̰�������İɣ�\n��$N����Ц������",
"��$N�׷״��������ɣ��ٲ��߾Ͱ���ץ������",
});


void judge_select(mixed obs);
void input_way(mixed obs,string str);
void no_answer_way(mixed obs);
void select_way(mixed obs);
void talk_over(mixed obs);

mixed job(string m_id,string officer_id)
{
   //string m_area=CHAR_D->get_char(officer_id,"area");
   string target,mnation;
   string *alst,*alst2;
   array typ;
   object *mlist,ot;
   object o=find_body(m_id);
   
   tell_user("huaer",sprintf("m_id = %s, officer_id = %s\n",m_id,officer_id));
   if(!objectp(o)) return 0; // string

   mnation=CHAR_D->get_char(m_id,"nation");

   alst=AREA_D->list_areas();
   alst2=AREA_D->check_area("nation",mnation);
   tell_user("huaer",sprintf("alst2 = %O\n",alst2));
   alst-=alst2;

	if(!sizeof(alst)){
		o->add_job("fanpeople");
		o->finish_job("fanpeople");
	 	return "$N��$T�����ѵ�ͳһ����\n";  
	}
//Modified BY listen to make an additional check for fake guy exist
	do
	{
		target=alst[random(sizeof(alst))];
		alst-=({target});
		typ="/sgdomain/event/ev_guy"->get_array_type();
		tell_user("huaer",sprintf("typ = %O\n",typ));
		for(int i=0;i<3;i++)
		{
			ot=CHAR_D->find_npc_char(target+" "+typ[i]);
			if(!objectp(ot) || !ot->query("is_fake")) 
			{
				if (!objectp(ot))
					"/sgdomain/event/ev_guy"->create_guy(target,typ[i]);
				target=target+" "+typ[i];
				ot=CHAR_D->find_npc_char(target);

				o->set_asklist("fan","target",target);
				o->set_asklist("fan","filename",PJOB+"fanpeople/fanpeople");
				o->set_asklist("fan","funname","ask_fan");

				o->add_job("fanpeople");
				o->set_job("fanpeople","status","begin");
				if(objectp(ot))
				{
					o->set_job("fanpeople","memo","ɿ��"+ot->short());
					return "$N��$T����������Ϊ�������鷳$Rȥɿ��һ��"+
					ot->short()+"��\n�����˵ask "+target+" about fan ��\n";
				}
				else
				{
					LISBUG("fail to creat!\n");
					return "$N��$T��: �д��������뱨����ʦ�޸�!\n";
				}
   
			}
		}
	}while (!sizeof(alst));
	return "$N��$T������ʱ�޷������������Ժ����ԡ�\n";  
}
void ask_fan(object me, object target)
{
        string m_area,m_id;
	string m_title;
	string t_area,nat;
	int loy;
	
	if(target->query("is_fake"))
		LISBUG("fake people got faned");
	target->set("is_locked",1);
        m_id=me->query_primary_id();
        m_area=CHAR_D->get_char(m_id,"area");
    m_title=OFFICER_D->query_rank_name(
        (OFFICER_D->query_area_officer_title(
         AREA_D->get_area(m_area,"level"),0,0))[0]);
        me->targetted_action(
      "$N����$TЦ��˵����������������$s��Щ�������ǽ���\n"
          ,target);
        me->clear_asklist("fan");
        me->set_job("fanpeople","status","done");

        me->set_job("fanpeople","topics",({})); //haven't talk yet                    
             
                                     // within 10 minute
        me->set_job("fanpeople","score",20); // meet is 10
                                              // succ is 50

        if(sizeof(target->query_pure_leader())) {
			target->targetted_action("$N��$T����������æ�ء�\n",me);
	       tell_user(m_id,"%^H_GREEN%^������ɵò�����ȥ̫�ش����Ͱɡ�\n%^RESET%^");
			target->check_leader();

			return;
		}
        DELAY_D->delay_targetted_action(
                target,me,"һ��$N����������ü���۵ģ���������ˡ�\n"+
                "��һ��$N��������˭�ģ�����������\n",1);

        target->set_leader(m_id); // target will not do nonsence

		call_out("select_way",2,({ me, target}));

	t_area=target->query_room()->get_area();

        CHAR_D->set_char(m_id,"catch_time",time()+600);
        CHAR_D->set_char(m_id,"catch_file",PJOB+"fanpeople/fanpeople");
        CHAR_D->set_char(m_id,"catch_function","fan_catch");
        CHAR_D->set_char(m_id,"catch_para",target);
        CHAR_D->set_char(m_id,"catch_area",t_area);

	nat=AREA_D->get_area(t_area,"nation");
	loy=CHAR_D->get_char_loyalty(m_id,nat);
	loy--; loy=bmax(1,loy);
	CHAR_D->set_char_loyalty(m_id,nat,loy);

        return;
}

void recruit_catch(string o_id,string p_id,object o_people)
{
        object o_o,o_p;
        if(objectp(o_people)){
                string pep_id;
                o_people->simple_action(
                        "һ��$N�󺰣���������������ץ��������\n��$Nһ���ɢ��\n");
		o_people->do_my_dispear();
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
                "$N��$T���һ������$r����Ȼ�ڴ��������������£�\n",o_p);
        o_p->simple_action(
                "�ڹٱ�һӵ���ϣ���$N���ý��ʵʵ��\n");
        o_o->simple_action(
                "$Nһ���ֵ������ߡ�\n");
        o_p->simple_action(
                "�ڹٱ���$NѺ����ȥ��\n");

        CHANNEL_D->deliver_tell("rumor","system",
                CHAR_D->get_char(p_id,"name")+
                "��"+AREA_D->get_area(CHAR_D->get_char(o_id,"area"),"name")+
                "������������Ѳ�ߵ�"+CHAR_D->get_char(o_id,"name")+
                "����ץ��");
        (PCMD+"catch")->catch_award(o_id,p_id);

}

void fan_catch(string o_id,string p_id,object o_people)
{
        object o_o,o_p;
        if(objectp(o_people)){
                string pep_id;
                o_people->simple_action(
                        "һ$N�󺰣���������������ץ��������\n��$Nһ���ɢ��\n");
		o_people->do_my_dispare();
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
                "$N��$T���һ������$r����Ȼ�ڴ�ɿ���������£��������£�\n",o_p);
        o_p->simple_action(
                "�ڹٱ�һӵ���ϣ���$N���ý��ʵʵ��\n");
        o_o->simple_action(
                "$Nһ���ֵ������ߡ�\n");
        o_p->simple_action(
                "�ڹٱ���$NѺ����ȥ��\n");

        CHANNEL_D->deliver_tell("rumor","system",
                CHAR_D->get_char(p_id,"name")+
                "��"+AREA_D->get_area(CHAR_D->get_char(o_id,"area"),"name")+
                "ɿ���������£�������Ѳ�ߵ�"+CHAR_D->get_char(o_id,"name")+
                "����ץ��");
        
        (PCMD+"catch")->catch_award(o_id,p_id);

}
void judge_select(mixed obs)
{
    object me=obs[0],tar=obs[1];
        string p_id,t_id,mnation,marea;
        mixed gift;
        int ans=0;
        int safe,score,p_select,meili;

        if(!objectp(me)) return;
        if(!objectp(tar)) { return;}

		me->start_busy(5,"������ɿ�������ء�\n");
        p_id=me->query_id()[0];
        t_id=tar->query_id()[0];

        marea=tar->query_room()->get_area();

        
        gift=CHAR_D->get_char(p_id,"gift");
        meili=gift["meili"];

        mnation=CHAR_D->get_char(p_id,"nation");
        safe=AREA_D->get_area(marea,"safe");

        score=me->query_job("fanpeople","score");

        p_select=me->query_job("fanpeople","select");

    switch(p_select)
    {
        case 1:
        case 2:
        case 3:
        case 8:
        case 9:
         if((random(30)>meili)||(random(100)<safe)) 
                         ans=-1;
                 else
                         ans=1;
                 break;
        case 7:
                {
                        int tax=AREA_D->get_area(marea,"taxlocal")+
                                AREA_D->get_area(marea,"taxnation");
                        if(random(20)+20<tax)
                                ans=1;
                        else
                                ans=-1;
                }
                break;

        case 6:
                if(random(100)<safe)
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
                if(score>20)
                        ans=1;
                break;
        default:

                ans=1;
        }
        if(ans==1)
        {
                safe-=2;
                score+=2;
                tar->targetted_action(good_answer[p_select-1]+"\n",me);
        }
        else
        {
                safe++;
                score-=1;
                tar->targetted_action(bad_answer[p_select-1]+"\n",me);
        }
        AREA_D->set_area(marea,"safe",safe);
        me->set_job("fanpeople","score",score);
        if(p_select==10) // leave;
        {
                call_out("talk_over",1, obs);
                return;
        }
        call_out("select_way",1,obs);
}
void input_way(mixed obs,string str)
{   int p_select;
    object me=obs[0],usr,tar;
    string p_id;
    int *topics;
    remove_call_out("no_answer_way");


	tar=obs[1];
	if(!objectp(tar)) {talk_over(obs); return;}
	if(!tar->check_leader()) {talk_over(obs); return;}


	p_select=to_int(str); // must have me since after the check_leader

    if((p_select<1)||(p_select>10)) return;
        topics=me->query_job("fanpeople","topics");

	if(member_array(p_select,topics)!=-1)
    {  tell(me,"��������Ѿ�̸���ˣ��û�һ����\n");
       call_out("no_answer_way",30,obs);
       return;
    }
    p_id=me->query_primary_id();
    usr=find_user(p_id);
    if(objectp(usr)) usr->modal_pop();


    me->targetted_action(sug[p_select-1]+"\n",tar);
        me->set_job("fanpeople","select",p_select);
        topics+=({p_select});
        me->set_job("fanpeople","topics",topics);

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
   tell_user(p_id,"��Ĺ������������ǲ�����\n"+
"������������������������������������������������������������\n"+
" 1 ��������  2 �����Һ�  3 �����ܸ�  4 ���ͻƽ�  5 ������ʳ \n"+
" 6 �������  7 ��Թ˰��  8 ڮ�ٹ���  9 ڮ��̫�� 10 ���     \n"+
"������������������������������������������������������������\n"+
"��������Ļ���(1--10)��\n");
   call_out("no_answer_way",30,obs);
   usr->modal_push((: input_way,obs:),
        "��������Ļ���(1--10)��");

}
void talk_over(mixed obs)
{
    object me=obs[0],tar;
    string area,p_id;
    area=me->query_room()->get_area();
    area=AREA_D->get_area(area,"name");

    if(!objectp(me)) return;
    p_id=me->query_id()[0];
    tar=obs[1];
    if(objectp(tar)) {
 
		CHANNEL_D->deliver_tell("rumor","system",
        CHAR_D->get_char(p_id,"name")+
        "��"+area+"ɿ�����ղ������������ذ������½��ˡ�");
		tar->do_my_dispear();
    }
    tell_user(p_id,"%^H_GREEN%^������ɵò�����ȥ̫�ش����Ͱɡ�\n%^RESET%^");
}
