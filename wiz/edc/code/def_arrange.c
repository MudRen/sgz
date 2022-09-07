// arrange_troop
// curent troop curent item, default value wait time
// modified by suicide in 2000.11.09
// modified by edc in 08/04/2001
#define ARRANGE_TYPE(a)  "/daemons/area_d"->get_area(a,"arrange_type")
#define IS_OPEN          1
string auto_start_point(string p_area,string p_side);
void man_input(string p_id,int t_id,string p_side);

int pre_def_troop_num(int g_num,int arrange_type)
{int tmp=0;
 if (!arrange_type) return 0;  //arrange_type invalid 
 switch(g_num)
 {
 case 1    :    tmp =1;break;
 case 2..4 :    tmp =2;break;
 case 5..6 :    tmp =3;break;
 case 7..9 :    tmp =4;break;
 default   :    tmp = (g_num-1)/3+1;
 }
 //if ((tmp>1)&&(arrange_type ==1)) //���ٽ�������
 //   tmp --;
 return tmp;
          
}

int pre_def_generals_per_troop(int g_num,int t_num)
{  if (t_num<=0) return 1;  //��Ҵ����Ĳ��ӱ�Ԥ��Ĳ��Ӷ�ʱ,t_num<=0
   if (g_num == t_num) return 1;
   else if ((g_num/t_num)<=2)    return 2;
   else return 3; 
}

int get_arrange_type(int task_id)
{int max_soldier,max_commando,capatity;
 max_soldier = TASK_D->get_task(task_id,"max_soldier");
 max_commando= TASK_D->get_task(task_id,"max_commando");
 capatity = WARAI_D->get_max_soldier(TASK_D->get_task(task_id,"def_general_left"))+
            WARAI_D->get_max_soldier(TASK_D->get_task(task_id,"def_leader"));
 TASK_D->set_task(task_id,"capatity",capatity);
 if (max_commando==0) return 1;  //ѵ��ʱû�����.ֱ�ӷ���1
 if (max_soldier==0) return 1;   //û��footman�����,ֱ�ӷ���1
 if (capatity >= (max_soldier + max_commando))
    return 1;  // means ���ٽ��� ,��������ʱ����������.
 else   //���ཫ�ٵ����, ÿ�����ӵ�������±�������׼Ϊ1:4
 if ((capatity/max_commando)>5)
    return 2;  //��������ٲ���1/5��ˮƽ,ƽ���������������,Ȼ��ʣ��ȫ�����±�.
 else
 if ((max_soldier*5/capatity)<4)
    return 3;  //���������1/5��ˮƽ,�±���������4/5,��ʱ�ȷ����������±�,�ٷ������.
 else
    return 4;  //���������1/5ˮƽ,�±�Ҳ��4/5,�������¸���1/5,4/5�ı�������.   
}




void def_arrange_left(int task_id)
{
   	string p_area, p_leader;
   	object o_leader;
	mapping troop;

	p_area = TASK_D->get_task(task_id,"def_area");
   	p_leader = TASK_D->get_task(task_id,"def_leader");
   	o_leader = CHAR_D->find_char(p_leader);

   	if( objectp(o_leader) ){
		o_leader->simple_action("$N�ȵ���ȫ�彫ʿ��Ҫ����ɱ�У�$s�������ͣ�\n");
       		o_leader->simple_action("$N�콫ʿ����ս����\n");
   	}
	TASK_D->set_task(task_id,"start_war","yes");

	TASK_D->set_task(task_id,"def_stage","enter_warfield");
	troop = TASK_D->get_task(task_id, "def_troop_left");
	foreach(string tt in keys(troop)){
                if( troop[tt] == 0 )map_delete(troop, tt);
		if( tt == "commando") {
			AREA_D->set_area(p_area,"population",
				AREA_D->get_area(p_area,"population")+troop[tt]); 
                                // commado is people
			map_delete(troop, tt);
		}
        };
	AREA_D->set_area(p_area, "troop", troop);

	TASK_D->set_task(task_id,"msg_total_def_soldiers",
		"���ط���˧��"+CHAR_D->get_char(p_leader,"name")+
		"�����ط��ܱ�����"+chinese_number(TASK_D->get_task(task_id,"def_total_number")));

}
void put_def_troop(int task_id)
{
   	string p_area, p_room, p_nation, p_leader, p_general;
   	object o_troop, o_leader,o_general;
   	int total_soldier, t_id, p_m, p_t, *def_army,capatity;
   	mixed tmp, pre_troop;
	mapping troop;
	array msg_def_party;
	mapping msgs;
	int def_total_number;

   	p_area    = TASK_D->get_task(task_id,"def_area");
   	pre_troop = TASK_D->get_task(task_id,"def_curent_arrange_troop");
   	p_leader  = TASK_D->get_task(task_id,"def_leader");
   	p_general = pre_troop["general"][0];
   	o_leader  = CHAR_D->find_char(p_leader);
   	o_general = CHAR_D->find_char(p_general);
	troop	  = pre_troop["troop"];

	foreach( string tt in keys(troop) )total_soldier+=troop[tt];
	if( !total_soldier )return;

// edc  08/04/2001
	// Add one property for task_d, to check whether it is leaded by online ppl
	// If no, we need add �Զ������ for defending, otherwise the attack bowman is too powerful	

//	remove at 08/05/2001
//	if (CHAR_D->get_char(p_leader,"status") == STATUS_ONLINE )
//		TASK_D->set_task(task_id, "who_defend", "PPL" );
//	else
//		TASK_D->set_task(task_id, "who_defend", "NPC" );

////
		
   	if( (objectp(o_leader))&&(objectp(o_general)) ){
		if( p_leader == p_general )
			o_leader->simple_action("$N�ȵ���$s���Դ�"+CHINESE_D->chinese_number(total_soldier)+"�����ս��\n");
		else {
       			o_leader->targetted_action("$N�ȵ���$T���ڣ�\n",o_general);
       			o_general->simple_action("$N�����$s�ڣ�\n");
       			o_leader->targetted_action("$N��$T�����ٵ�"+
       				CHINESE_D->chinese_number(total_soldier)+"���������\n",o_general);
       			o_general->simple_action("$N��������\n");
       			o_general->simple_action("$N��������ˡ�\n");
		}
   	}

   	p_room = AREA_D->get_area(p_area,"path")+"warroom/"+pre_troop["position"];
   	p_nation = AREA_D->get_area(p_area,"nation");
   	o_troop = TROOP_D->new_troop(p_nation,pre_troop["general"],0,p_room);
   	t_id = o_troop->get_id();



   	if( TASK_D->get_task(task_id,"type") == TT_WAR || 
		TASK_D->get_task(task_id,"type") == TT_TRAIN )
	   	TROOP_D->set_troops(t_id,"source_area",p_area);
   	TROOP_D->set_troops(t_id,"task_id",task_id);
   	TROOP_D->set_troops(t_id,"side","d");

   	def_army = TASK_D->get_task(task_id,"def_army");
   	if( !sizeof(def_army) ) def_army=({});
   	def_army+=({t_id});
   	TASK_D->set_task(task_id,"def_army",def_army);

   	p_m = AREA_D->get_area(p_area,"morale");

	if(TASK_D->get_task(task_id,"type")==TT_WAR)
	   	p_m +=20;

   	p_t = AREA_D->get_area(p_area,"train");

        tmp = TASK_D->get_task(task_id,"def_troop_left");



	msg_def_party=TASK_D->get_task(task_id,"msg_def_party");
	if(!arrayp(msg_def_party)) msg_def_party=({});
	msgs=([]);
	msgs["generals"]=pre_troop["general"];
	msgs["troops"]=troop;
	msg_def_party+=({msgs});
	TASK_D->set_task(task_id,"msg_def_party",msg_def_party);


	def_total_number=TASK_D->get_task(task_id,"def_total_number");
 	foreach(string tt in keys(troop) ){
                tmp[tt] -= troop[tt];
		def_total_number+=troop[tt];
		if(!tmp[tt])
			map_delete(tmp,tt);		

		if(tt=="commando") // commando got 100 train and 200 morale
                        TROOP_D->add_soldier(t_id,tt,troop[tt],200,100,30);
		else
                        TROOP_D->add_soldier(t_id,tt,troop[tt],p_m,p_t,30);
        }; 

	TASK_D->set_task(task_id,"def_total_number",def_total_number);
        TASK_D->set_task(task_id,"def_troop_left",tmp);

  	tmp = TASK_D->get_task(task_id,"def_general_left");
  	tmp-=pre_troop["general"];
  	//added by suicide in 2000.11.08 to update max capatity now before
  	//new troop
  	capatity = WARAI_D->get_max_soldier(tmp);
  	TASK_D->set_task(task_id,"capatity",capatity);
  	//added end
  	TASK_D->set_task(task_id,"def_general_left",tmp);
}
mixed get_def_val(int task_id)
{
   	int p_troop,n_tmp,g_num,t_num,tg_num,i,arrange_type,capatity,p_capatity;
   	string p_stage, p_area,result;
   	mixed tmp, tmp2;
	int tempNumber, troop_idx;  // added by edc

   	p_troop = TASK_D->get_task(task_id,"def_arrange_troop");
   	p_stage = TASK_D->get_task(task_id,"def_arrange_step");
   	p_area  = TASK_D->get_task(task_id,"def_area");

   	switch(p_stage){
      		case "general":
        		tmp = TASK_D->get_task(task_id,"def_general_left");
        		if(!sizeof(tmp)) return "";
        		if (!ARRANGE_TYPE(p_area)&&!IS_OPEN){ //old arrangement style
        		    return tmp[0];
        		                 }
        		else{
        		//added by suicide for deciding how much generals should be 
        		//in the same troop in 2000.11.08
        		g_num = sizeof(tmp);
        		if (!TASK_D->get_task(task_id, "leader_out"))
        		{  //leader troop
        		t_num = pre_def_troop_num(g_num,TASK_D->get_task(task_id,"arrange_type"));
        		if (!t_num) 
        		   {SGSYS("�Զ��ֱ����߾�������!");
        		    t_num = 1;}
			TASK_D->set_task(task_id,"pre_def_troop_num",t_num);
		        }
		        t_num = TASK_D->get_task(task_id,"pre_def_troop_num");
			tg_num = pre_def_generals_per_troop(g_num,t_num-p_troop);
        		//SGSYS(sprintf("generals = %d troops = %d tg_num = %d",
        		//              g_num,t_num,tg_num)); 
        		result = tmp[0];
        		for (i=1;i<tg_num;i++)	
        		    if (sizeof(tmp)>=(i*(t_num-p_troop)+1))
        		     result = result + "," + tmp[i*(t_num-p_troop)];
        		return result;}
        		//added end   
      		case "position":
        		tmp = auto_start_point(p_area,"d");
        		return tmp;
      		case "newtroop":
        		tmp = TASK_D->get_task(task_id,"def_general_left");
        		if(!sizeof(tmp)) return -1;
			tmp = TASK_D->get_task(task_id, "def_troop_left");
			if(!sizeof(tmp)) return -1;

        		else return 1;
// edc  08/01/2001
		case "troopIdx":
//			return 0;  // distribute the first troop forever
			
			tmp = TASK_D->get_task(task_id, "def_troop_left");
			

			// npc auto arrange... check out which troop should be arranged
			// say, always picks the biggest troop type  08/03/2001
			// maybe need check whether it is auto npc def or ppl def here!
			for( i=0; i<sizeof(tmp); i++)
			{
				if (tempNumber > values(tmp)[i])
					continue;
				tempNumber = values(tmp)[i];
				troop_idx = i;
			}
	
			return troop_idx;
////		
		default:
		        if (!ARRANGE_TYPE(p_area)&&!IS_OPEN){ //old arrangement style
			tmp = TASK_D->get_task(task_id,"def_troop_left");
			if(!tmp[p_stage]) return -1;
			tmp2=TASK_D->get_task(task_id,"def_general_left");
			n_tmp=bmin(sizeof(tmp2),7-p_troop);
			n_tmp=bmax(1,n_tmp);
			n_tmp=tmp[p_stage]/n_tmp;
			tmp=TASK_D->get_task(task_id,"def_curent_arrange_troop");
			n_tmp=bmin(n_tmp,tmp["max_av_soldier"]);
			return n_tmp;
			                 }
		        else    //new arrangement style
		        {
// edc  08/01/2001   cancel suicide's auto-arrangment, which is ����ֻ��
				tmp2 = TASK_D->get_task(task_id, "def_troop_left");
				if (!tmp2[p_stage] ) return -1;
				tmp=TASK_D->get_task(task_id,"def_curent_arrange_troop");			
				p_capatity = WARAI_D->get_max_soldier(tmp["general"]);

//EDCBUG(sprintf("TASK_D->DEF_CURENT_ARRANGE_TROOP: %O \n TASK_D->DEF_TROOP_LEFT: %O", tmp, tmp2));
//EDCBUG(sprintf("N_TMP: %d        P_CAPATITY: %d      CAPATITY: %d\n", n_tmp, p_capatity, capatity));
				// to get the most availble soidier      08/03/2001
				// p_capatity: ���ӽ�����������,  tmp2[p_stage]: ������ʣ����� 
				/*return bmin(n_tmp,tmp["max_av_soldier"]);*/
				return bmin(p_capatity, tmp2[p_stage]);


/*
		        tmp2 = TASK_D->get_task(task_id,"def_troop_left");
			if (!tmp2[p_stage] ) return -1;
			t_num = TASK_D->get_task(task_id,"pre_def_troop_num");
			tmp=TASK_D->get_task(task_id,"def_curent_arrange_troop");
			arrange_type = TASK_D->get_task(task_id,"arrange_type");
			capatity   = TASK_D->get_task(task_id,"capatity");
			p_capatity = WARAI_D->get_max_soldier(tmp["general"]);
			n_tmp=tmp2[p_stage]*p_capatity/capatity;

		        //if(!p_stage) return -1;
		        if(!tmp2[p_stage]) return -1;
		        foreach(string tt in keys(tmp2))
		        {
                          if( tmp2[tt] == 0 ) map_delete(tmp2,tt);
                        };
			t_num = TASK_D->get_task(task_id,"pre_def_troop_num");
			tmp=TASK_D->get_task(task_id,"def_curent_arrange_troop");
			arrange_type = TASK_D->get_task(task_id,"arrange_type");
			capatity   = TASK_D->get_task(task_id,"capatity");
			p_capatity = WARAI_D->get_max_soldier(tmp["general"]);
			n_tmp=tmp2[p_stage]*p_capatity/capatity;
			//SGSYS(sprintf("sold=%d p_cap=%d cap=%d n_tmp=%d stage=%s",tmp2[p_stage],
			//      p_capatity,capatity,n_tmp,p_stage));
//  if commando ,arrange to per troop in average.
			if (p_stage == "commando")  
			   switch (arrange_type)
			    {
 			     case 1..2 : return bmin(n_tmp,tmp["max_av_soldier"]);
 			     case 4    : return p_capatity/5;
 			     case 3    : 
 			        i=0;
			        if (sizeof(keys(tmp2))>1)
			        foreach(string tt in keys(tmp2))
			        {
                                 if ( tt != "commando" ) 
                                    i+=tmp2[tt]*p_capatity/capatity;
                                }   
                                return p_capatity-i;
 			    }
			else
			  return bmin(n_tmp,tmp["max_av_soldier"]);
*/
////   
   	                }
   	      }//end switch
}
void def_pre_arrange(int task_id,string def_area)
{
	int p_soldier, p_safe, p_people;
        mapping troop;
	string def_n=AREA_D->get_area(def_area,"nation");
        //2001.4.19   NPC���⹥��ʿ��ʿ����ѵ���Ⱥ㶨��180
	if (CHAR_D->get_char(def_n,"type")==TYPE_NPC)
	  {
	   AREA_D->set_area(def_area,"train",200);
	   AREA_D->set_area(def_area,"morale",200);
	  }
	
   	p_soldier=AREA_D->get_area(def_area,"soldier");
	troop = AREA_D->get_area(def_area, "troop");
	if(!mapp(troop)) troop=([]);
	if(TASK_D->get_task(task_id,"type")==TT_WAR) {
// if train no commando
		p_people = AREA_D->get_area(def_area, "population");
		p_people /=10;
		p_safe=AREA_D->get_area(def_area,"safe");
		//2001.4.19   NPC���⹥�������㶨Ϊ200
		if (CHAR_D->get_char(def_n,"type")==TYPE_NPC)
		  {
		   p_safe=200;
		  }
		//end end 
		p_people *=(p_safe+50);
		p_people /=200;
		
		if(sizeof(AREA_D->check_area("nation",def_n))==1) {
			p_people *=3;
		}
		p_people=bmin(p_people,20000);
		p_people=bmax(100,p_people);  
               	troop["commando"] = p_people;
		AREA_D->set_area(def_area, "population", 
			AREA_D->get_area(def_area, "population")-p_people);
	}
	foreach(string tt in keys(troop)){
                if( troop[tt] == 0 )map_delete(troop, tt);
        };
   	TASK_D->set_task(task_id,"max_soldier",p_soldier);
   	TASK_D->set_task(task_id,"def_arrange_troop",0);
  	TASK_D->set_task(task_id,"def_arrange_step","general");
	TASK_D->set_task(task_id,"def_curent_arrange_troop",([]));
	TASK_D->set_task(task_id,"def_troop_left", troop);
	//SGSYS(sprintf("%O",troop));
	//added by suicide in 2000.11.09
	TASK_D->set_task(task_id,"max_commando",p_people);
	TASK_D->set_task(task_id,"arrange_type",get_arrange_type(task_id));
	//added end
   	return;
}
void def_arrange(int task_id)
{
   	string def_leader, def_area, p_leader, p_flyroom, p_short;
   	string *def_party, *def_general_left;
   	object o_char;
	mixed tmp, def_curent_arrange_troop;

   	def_leader = TASK_D->get_task(task_id,"def_leader");
   	o_char = CHAR_D->find_char(def_leader);
   	def_area = TASK_D->get_task(task_id,"def_area");
   	p_leader = AREA_D->get_area(def_area,"leader");
   	p_flyroom = AREA_D->get_area(def_area,"path")+AREA_D->get_area(def_area,"fly");
   	p_short = load_object(p_flyroom)->short();

   	if( objectp(o_char )){ 
		o_char->simple_action("$N������λ���������ˣ��ٵ�"+p_short+"�㽫������Υ���ߣ�ն����\n");
      		o_char->simple_action("$N�Ҵ��뿪�ˡ�\n");
      		CHAR_D->put_char(def_leader,p_flyroom);
    		o_char->simple_action("$N������"+p_short+"��\n");
   	}
   	CHAR_D->put_char(def_leader,p_flyroom);

   	def_party = TASK_D->get_task(task_id,"def_party");
   	def_general_left = ({ });
        //2001.4.19 NPC��,���������ս��
	if (CHAR_D->get_char(AREA_D->get_area(def_area,"nation"),"type")==TYPE_NPC)  //NPC����
	   {
	       def_party = filter_array(def_party,(: CHAR_D->get_char($1,"type")==TYPE_NPC :));
           }
        //
   	foreach(string p_id in def_party){
      		if( (p_id!=def_leader)&&(p_id!=p_leader) ){
         		o_char = CHAR_D->find_char(p_id);
         		if(objectp(o_char)){
           			o_char->simple_action("$N�Ҵ��뿪�ˡ�\n");
           			CHAR_D->put_char(p_id,p_flyroom);
           			o_char->simple_action("$N������"+p_short+"��\n");
         				   }
                      	CHAR_D->put_char(p_id,p_flyroom);
         		def_general_left+=({p_id});
      			}
   	}
   	//sort by the sum of the char's wuli and zhimou
   	//added by suicide in 2000.11.08
   	//FBUG("Sort def_general_left arrays!");
   	def_general_left = sort_array(def_general_left,
   	                   (: CHAR_D->get_char($1,"skills")["sk_wuli"]
		             >CHAR_D->get_char($2,"skills")["sk_wuli"] ? -1 : 1 :));
   	//ended
   	TASK_D->set_task(task_id,"def_general_left",def_general_left);
   	def_pre_arrange(task_id,def_area);
	// Only one general 
	if( !def_general_left || !sizeof(def_general_left) ){
		tmp = TASK_D->get_task(task_id, "def_troop_left");
		TASK_D->set_task(task_id,"def_arrange_step",keys(tmp)[0]);

		def_curent_arrange_troop = ([ ]);
		def_curent_arrange_troop["general"] = ({TASK_D->get_task(task_id,"def_leader")});
		def_curent_arrange_troop["max_av_soldier"]=
			WARAI_D->get_max_soldier(def_curent_arrange_troop["general"]);
				// soldier type index begin from 0;
		def_curent_arrange_troop["sd_idx"]=0;

		TASK_D->set_task(task_id,"def_curent_arrange_troop",def_curent_arrange_troop);
	};
	new("/sgdomain/menu/warinput")->man_input(def_leader,task_id,"d");
}
