// def_meeting.c
// used for the defensive part to prepare the war
// modified by suicide in 2000.11.09
void def_meeting(int t_num)
{
        string *u_list;
        string s_room;
        string p_leader;
        int i;
        object ob_char;
        string att_name;
        string a_id;
        a_id=TASK_D->get_task(t_num,"def_area");
        att_name=TASK_D->get_task(t_num,"att_name");
        CHANNEL_D->deliver_tell("rumor","system",
                 sprintf("%s�ٿ������������顣",AREA_D->get_area(a_id,
"name")));
        s_room=TASK_D->get_task(t_num,"def_room");
        
	TASK_D->set_task(t_num,"def_stage","search_leader");
        u_list=TASK_D->get_task(t_num,"def_party");
//        p_leader=AREA_D->get_area(a_id,"leader");
		p_leader=TASK_D->get_task(t_num,"pre_def_leader");

        for(i=0;i<sizeof(u_list);++i)
        {
           if((CHAR_D->get_char(u_list[i],"status")==STATUS_ONLINE)
                &&(u_list[i]!=p_leader)) // a player
           {
               if(file_name(environment(CHAR_D->find_char(u_list[i])))!=s_room)
                   (EV_INFORMSB)->inform_sb(u_list[i],
                       AREA_D->get_area(a_id,"name")+"Ҫ�ٿ������������飬��$R��ȥ��");    
           }
           else
           {
                ob_char=CHAR_D->find_char(u_list[i]);
                if(CHAR_D->get_char(u_list[i],"status")==STATUS_ACTIVE) //active
                {
                    if(CHAR_D->get_char(u_list[i],"room")!=s_room)
                    {
                        (EV_INFORMSB)->inform_sb(u_list[i],
                             AREA_D->get_area(a_id,"name")+"Ҫ�ٿ������������飬��$R��ȥ��");    
                        if(objectp(ob_char))
                        {
                             ob_char->simple_action("$N���ֵ���$s��Ҫ����������ǣ��������¡�\n");
                             ob_char->simple_action("$N���Ҵҵ��뿪�ˡ�\n");
                        }
                        CHAR_D->put_char(u_list[i],s_room);
                     if(objectp(ob_char))
                        ob_char->simple_action("$N���Ҵҵ����˹�����\n");
                    }
                }
                else
                {
                    if(!objectp(ob_char)||
                          (file_name(environment(CHAR_D->find_char(u_list[i])))!=s_room))
                    {
                       CHAR_D->put_char(u_list[i],s_room);
                       ob_char=CHAR_D->find_char(u_list[i]);
                          if(objectp(ob_char))
                             ob_char->simple_action("$N���Ҵҵ����˹�����\n");
                    }
                }
            } // end of f((CHAR_D->get_char(u_list[i],"status")==STATUS_ONLINE)
        }// end of for(i=0;i<sizeof(u_list);++i)
        ob_char=CHAR_D->find_char(p_leader);
        if(objectp(ob_char))
           ob_char->simple_action("$N����������λ�԰������ǰ�����Ͼ�����֪��λ\n���ˡ�����Ը�������"+att_name+"�Ľ�����\n");
     call_out("auto_want_leader",random(4)+1,t_num);
	 call_out("final_decision",60,t_num);
}
void i_want_leader(int task_id,string my_id)
{
   object o_id;
   string* def_candidate;
   string def_area;
   string p_nation; //2001.4.13
   o_id=CHAR_D->find_char(my_id);
   def_candidate=TASK_D->get_task(task_id,"def_candidate");
   if(!def_candidate)
   def_candidate=({});
   def_area=TASK_D->get_task(task_id,"def_area");//2001.4.13
   p_nation=AREA_D->get_area(def_area,"nation");
   //NPC�׶����� 2001.4.13
   if ((CHAR_D->get_char(p_nation,"area")==def_area)&&(CHAR_D->get_char(p_nation,"type")==TYPE_NPC))
      {
       if(objectp(o_id))
         o_id->simple_action("$N�����ҿ������ɱ������Գ�����Ϊ�׵���$sԸ׷��������ң�����Ч�ҡ�\n");

       AREA_D->set_area(def_area,"train",200);  //NPC�׶��⵽����ʱ,����ʿ����ѵ���Ⱥ㶨��200
       AREA_D->set_area(def_area,"morale",200);
       TASK_D->set_task(task_id,"def_stage","arrange"); //���
       TASK_D->set_task(task_id,"def_leader",p_nation);
       call_out("def_arrange",3,task_id);
      return;
      }
   //added end

//   if(my_id==AREA_D->get_area(def_area,"leader"))
      if(my_id==TASK_D->get_task(task_id,"pre_def_leader"))

   {
	if(sizeof(def_candidate))
        {
	   if(objectp(o_id))
             o_id->simple_action("$N�����ҿ�������$s���Գ�����Ϊ�׵���\n");
	}
	else
        {
	   if(objectp(o_id))
             o_id->simple_action("$N̾��һ������������Ȼ���˸�ս��ֻ����$s���Գ�������ˡ�\n");
        }
        TASK_D->set_task(task_id,"def_stage","arrange"); //���
        TASK_D->set_task(task_id,"def_leader",my_id);
	call_out("def_arrange",3,task_id);
   }
   else
   {
	if(member_array(my_id,def_candidate)!=-1)
        {
           write("���Ѿ�Ҫ����ˡ�\n");
	   return;
        }
 	else
        {
	   if(objectp(o_id))
             o_id->simple_action(({"$Nͦ�����$s���ţ�Ը���ɱ�˵пܣ�\n",
              "$N����$sԸƴ��һս��\n","$N����$sԸ��һ������ɱ��������\n"}));
	   def_candidate-=({my_id});
	   def_candidate+=({my_id});
           TASK_D->set_task(task_id,"def_candidate",def_candidate);
        }
   }
}
// we still need one that the player leader arrange the general
// will add that later
void final_decision(int task_id)
{
   string *def_candidate;
   string *user_candidate;
   string p_leader;
   string p_area;
   string p_nation; //2001.4.13
   string p_selected;
   object o_ld,o_se;
   int sum_can,sum_plycan;
   //FBUG("In final decision depart!\n");
   if(TASK_D->get_task(task_id,"def_stage")!="search_leader")
      return;
   def_candidate=TASK_D->get_task(task_id,"def_candidate"); 
   p_area=TASK_D->get_task(task_id,"def_area");
   p_nation = AREA_D->get_area(p_area,"nation");  //2001.4.13
//   p_leader=AREA_D->get_area(p_area,"leader");
   p_leader=TASK_D->get_task(task_id,"pre_def_leader");

   o_ld=CHAR_D->find_char(p_leader);
   if(objectp(o_ld))
     o_ld->simple_action("$N������̬����������Ҫ�Ͽ������\n");
   if(!def_candidate)
      def_candidate=({});
   sum_can=sizeof(def_candidate);
   if(!sum_can)
   {  p_selected=p_leader;
   }
   else
   {
	user_candidate=filter_array(def_candidate,
(: CHAR_D->get_char(($1),"status")==STATUS_ONLINE :)); //
        if((sum_plycan=sizeof(user_candidate))>0)
        {   p_selected=user_candidate[random(sum_plycan)];
	}
	else
	{
   	//sort by the char's wxxy
   	//added by suicide in 2000.11.08
   	def_candidate = sort_array(def_candidate,
   	                   (: CHAR_D->get_char($1,"skills")["sk_wuli"] > CHAR_D->get_char($2,"skills")["sk_wuli"] ? -1 : 1 :));
   	p_selected = def_candidate[0];
   	//ended

        //   p_selected=def_candidate[random(sum_can)];
        }
   }
   //2001.4.13   NPC���Ƶĵ�����NPC̫�طֱ�
   if (CHAR_D->get_char(p_nation,"type")==TYPE_NPC)
   {  if (p_area == CHAR_D->get_char(p_nation,"area"))
          p_selected = p_nation;     //��Ϊ�׶��������������Ϊ����
      else
      if ((CHAR_D->get_char(p_leader,"type")==TYPE_NPC)&&(p_selected!=p_leader))
      {   //���Ԥ���leaderΪNPC,Ҳ����˵��NPC���Ƶ�����ѡ��NPC leaderΪ������
          p_selected=p_leader;
      }
   }
   //
   TASK_D->set_task(task_id,"def_stage","arrange"); //���
   TASK_D->set_task(task_id,"def_leader",p_selected);
   o_ld=CHAR_D->find_char(p_leader);
   o_se=CHAR_D->find_char(p_selected);
   if(p_leader==p_selected)
   {
      if(objectp(o_ld))
             o_ld->simple_action("$N̾��һ������������Ȼ���˸�ս��ֻ����$s���Գ�������ˡ�\n");
   }
   else
   {
      if((objectp(o_ld))&&(objectp(o_se)))
o_ld->targetted_action("$N��$T����$m$R����ȫ�ţ���ξ�ȫ��$n1p�˵������ˣ�\n",o_se);
   }
   call_out("def_arrange",3,task_id);
   return;
}
void auto_want_leader(int task_id)
{
   string *u_list,*def_candidate;
   string p_area;
   int sum;
   string p_id;
   if(TASK_D->get_task(task_id,"def_stage")!="search_leader")
      return;
   u_list=TASK_D->get_task(task_id,"def_party");
   if(!sizeof(u_list)) {
      TASK_D->set_task(task_id,"def_stage","no leader");
      return;
   }
   def_candidate=TASK_D->get_task(task_id,"def_candidate");
   if(!def_candidate) def_candidate=({});
   sum=sizeof(u_list);
   
   if((sizeof(def_candidate)+1)==sum)
   { 
     final_decision(task_id);
     return ;
   }
   p_area=TASK_D->get_task(task_id,"def_area");
   p_id=u_list[random(sum)];
   if((member_array(p_id,def_candidate)==-1)&&(p_id!=TASK_D->get_task(task_id,"pre_def_leader"))

      &&(CHAR_D->get_char(p_id,"status")!=STATUS_ONLINE)&&(CHAR_D->get_char(p_id,"level")>=2))
   {
      i_want_leader(task_id,p_id);
   }
   call_out("auto_want_leader",random(4)+1,task_id); 
   
}
