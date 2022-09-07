/* NpcAi_d.c by Suicide on 24/07/2000
** This is used to handle the NPC country to select player taishou
*/
#include <security.h>
#define SAVE_FILE "/data/daemons/npcai_d"

inherit M_ACCESS;
private string array cities ;
private int last_ai_city_id ;

void save_data()
{  
   	unguarded(1, (: save_object, SAVE_FILE :));
}

void think_about_war()
{}
void think_about_event()
{}

int can_be_taishou(string p_area,string p_id)
{int a_lvl;
 a_lvl = AREA_D->get_area(p_area,"level");
 if(CHAR_D->get_char(p_id,"nationcontribution")<500*a_lvl) 
    return 0; // at least 500 * city level
 return 1;
}


void create_taishou(string p_area) {
	string *ids,p_id,old_leader;
	string msg,n;
	int title;
	n = AREA_D->get_area(p_area,"nation");
	ids=CHAR_D->check_char("area",p_area);
	if(!sizeof(ids)) return;
	ids=filter_array(ids,(:CHAR_D->get_char($1,"type")==TYPE_PLAYER:));
	if(!sizeof(ids)) return;
	ids=sort_array(ids,(: CHAR_D->get_char($1,"nationcontribution")
		> CHAR_D->get_char($2,"nationcontribution") ? 1 : -1 :));
	if(!sizeof(ids)) return;
		p_id=ids[sizeof(ids)-1];
	if((sizeof(ids)>2)&&(random(3)==0))
		p_id=ids[sizeof(ids)-2];
	if((sizeof(ids)>3)&&(random(6)==0))
		p_id=ids[sizeof(ids)-3];
        
        if (!can_be_taishou(p_area,p_id)) return;
	title=OFFICER_D->query_area_officer_title(AREA_D->get_area(p_area,"level"),0,0)[0];
        old_leader=AREA_D->get_area_leader(p_area);
        if(stringp(old_leader)) 
        {
	 CHAR_D->set_char(old_leader,"ranklocal",R_SG);
	 CHAR_D->set_char(old_leader,"grant",0);
	}
	CHAR_D->set_char(p_id,"ranklocal",title);
	CHAR_D->set_char(p_id,"tsx",200);   //̫��������,��ʼ200
	CHAR_D->set_char(p_id,"grant",0);	   

	msg=sprintf("%s���ڹ���׿����%s����Ϊ%s��̫�ء�",
		CHAR_D->get_char(p_id,"name"),
		CHAR_D->get_char(n,"name"),
		AREA_D->get_area(p_area,"name"));
	CHANNEL_D->deliver_tell("rumor","system",msg);
	HIS(msg);
	CHANNEL_D->deliver_tell("gossip",CHAR_D->get_char(n,"name"),
		CHAR_D->get_char(p_id,"name")+"���úøɣ�"+
		AREA_D->get_area(p_area,"name")+"�������ͼ������������ˡ�");

	CHANNEL_D->deliver_tell("gossip",CHAR_D->get_char(p_id,"name"),
		"���ε�Ϳ���ѱ����������");
	
	return ;
}

void remove_taishou(string p_area,string p_id) {
	string msg,n,g_id;
	int tmp;
	mixed grant;
	grant = CHAR_D->get_char(p_id,"grant");
	if (grant) 
	   {g_id = p_id;
	    p_id = grant["leader"];     
	   }
	if ((tmp=CHAR_D->get_char(p_id,"tsx"))>0)
	   {
	    tmp -= 20;     //һ�챻��Ѳһ��,tsx��ȥ20,�����tsx�����ӵ������
	    CHAR_D->set_char(p_id,"tsx",tmp);//ʮ���̫�ؾͻᱻ��ְ  
	    return;
	   }        
	 
	n = AREA_D->get_area(p_area,"nation");
	tmp = CHAR_D->get_char(p_id,"nationcontribution");
	tmp = tmp * 4 / 5;
	CHAR_D->set_char(p_id,"nationcontribution",tmp);
	tmp = CHAR_D->get_char(p_id,"reputation");
	tmp = tmp * 4 / 5;
	CHAR_D->set_char(p_id,"reputation",tmp);
	CHAR_D->set_char(p_id,"ranklocal",R_SG);
	CHAR_D->set_char(p_id,"grant",0);
	if (CHAR_D->char_exist(g_id)) 
	   {CHAR_D->set_char(g_id,"ranklocal",R_SG);
	    CHAR_D->set_char(g_id,"grant",0);
	   }
	msg=sprintf("%s���ڻķ����±�%s����%s̫��ְλ��",
		CHAR_D->get_char(p_id,"name"),
		CHAR_D->get_char(n,"name"),
		AREA_D->get_area(p_area,"name"));
	CHANNEL_D->deliver_tell("rumor","system",msg);
	HIS(msg);
	CHANNEL_D->deliver_tell("gossip",CHAR_D->get_char(n,"name"),
		CHAR_D->get_char(p_id,"name")+"����������ʧ����");
	AREA_D->auto_head(p_area);  //��ұ���ְ��,��ϵͳ�Զ���ѡNPCΪ̫��
	//create_taishou(p_area);
	return ;

}

void check_guoshi_vote(string nation)
{mapping vote;
 int vote_id,need_ballot=5,areas_amount;
 string p_id,msg,gs;
 array vote_info;
 if (!VOTE_D->get_special_vote(nation,"elect"))  //����û�й�ʦѡ��
      return;
 vote_id = VOTE_D->get_special_vote(nation,"elect")[0];
 vote = VOTE_D->get_vote_result(vote_id);
 areas_amount = sizeof(AREA_D->check_area("nation",nation));
 need_ballot = areas_amount * 2 / 3 ; //2/3̫��ͬ��
 if (areas_amount<4) need_ballot++;   //С��4�����е�NPC����,����̫��ͬ��ſ���
 if (sizeof(vote[1])>=need_ballot)
    { 
      p_id = VOTE_D->get_special_vote(nation,"elect")[3];
      COUNTRY_D->set_country(nation,"gs",p_id);
      COUNTRY_D->set_country(nation,"gsx",200); // not too much
      msg=sprintf("���ڵõ������̫�ص�֧�֣�%s��%s����Ϊ%s�Ĺ�ʦ��",
		CHAR_D->get_char(p_id,"name"),
		CHAR_D->get_char(nation,"name"),
		COUNTRY_D->get_country(nation,"name"));
      CHANNEL_D->deliver_tell("rumor","system",msg);
      HIS(msg);
      CHANNEL_D->deliver_tell("gossip",CHAR_D->get_char(nation,"name"),
           CHAR_D->get_char(p_id,"name")+"���úøɣ������������ͼ������������ˡ�");

      CHANNEL_D->deliver_tell("gossip",CHAR_D->get_char(p_id,"name"),
		"���ε�Ϳ���ѱ����������");
      VOTE_D->del_special_vote(nation,"elect");
      CHAR_D->set_char(p_id,"candidate",0);
    }
 else
    { vote_info = VOTE_D->get_special_vote(nation,"elect");
      vote_info[2] = vote_info[2] - 1;
      need_ballot = areas_amount - need_ballot + 1; //����Ʊ����Ʊ��
      if ((vote_info[2]>0)&&(sizeof(vote[2])<need_ballot))
          VOTE_D->modify_special_vote(nation,"elect",vote_info);
      else
      {
      p_id = VOTE_D->get_special_vote(nation,"elect")[3];
      msg=sprintf("����%s��֧�ֶȲ�����%sȡ������������Ϊ%s��ʦ���뷨��",
		CHAR_D->get_char(p_id,"name"),
		CHAR_D->get_char(nation,"name"),
		COUNTRY_D->get_country(nation,"name"));
      CHANNEL_D->deliver_tell("rumor","system",msg);
      HIS(msg);
      CHANNEL_D->deliver_tell("gossip",CHAR_D->get_char(nation,"name"),
           CHAR_D->get_char(p_id,"name")+"���䣬���ڸ���̫�ط������ڣ�������Ϊ��ʦ����ֻ���ݻ���");

      CHANNEL_D->deliver_tell("gossip",CHAR_D->get_char(p_id,"name"),
		"��֪���������ն����͸�·̫�ش��̣��õ�֧�ֺ�������¶��ᡣ");
      //����δ�ɹ��ĵĹ�ʦ�����ˣ��й�ֵ��1/10	
      CHAR_D->set_char(p_id,"reputation",CHAR_D->get_char(p_id,"reputation")*9/10);		
      CHAR_D->set_char(p_id,"localcontribution",CHAR_D->get_char(p_id,"localcontribution")*9/10);
      CHAR_D->set_char(p_id,"nationcontribution",CHAR_D->get_char(p_id,"nationcontribution")*9/10); 		

      VOTE_D->del_special_vote(nation,"elect"); 
      CHAR_D->set_char(p_id,"candidate",0);    
      }
      
    }
  return ;
}

void check_guoshi_dismiss_vote(string nation)
{mapping vote;
 int vote_id,need_ballot=5,areas_amount;
 string p_id,msg,gs,v_id;
 array vote_info;
 if (!VOTE_D->get_special_vote(nation,"dismiss"))  //����û�й�ʦѡ��
      return;
 vote_id = VOTE_D->get_special_vote(nation,"dismiss")[0];
 vote = VOTE_D->get_vote_result(vote_id);
 areas_amount = sizeof(AREA_D->check_area("nation",nation));
 need_ballot = areas_amount * 2 / 3 ; //2/3̫��ͬ�� 
 if (sizeof(vote[1])>=need_ballot)
    { 
      v_id = VOTE_D->get_special_vote(nation,"dismiss")[3]; //����������ѡ�ٵ����id
      p_id = COUNTRY_D->get_country(nation,"gs");
      COUNTRY_D->set_country(nation,"gs",0);
      msg=sprintf("�ڴ����̫�صķ������У�%s��������%s�Ĺ�ʦ��λ�ӡ�",
		CHAR_D->get_char(p_id,"name"),
		COUNTRY_D->get_country(nation,"name"));
      CHANNEL_D->deliver_tell("rumor","system",msg);
      HIS(msg);
      CHANNEL_D->deliver_tell("gossip",CHAR_D->get_char(nation,"name"),
           CHAR_D->get_char(p_id,"name")+"��ᵳӪ˽��������������̫����ʧ���ˣ�");

      CHANNEL_D->deliver_tell("gossip",CHAR_D->get_char(p_id,"name"),
		"��������������������");
      //����������̨�Ĺ�ʦ���й�ֵ��һ��		
      CHAR_D->set_char(p_id,"reputation",CHAR_D->get_char(p_id,"reputation")/2);		
      CHAR_D->set_char(p_id,"loyalty",45);
      CHAR_D->set_char(p_id,"localcontribution",CHAR_D->get_char(p_id,"localcontribution")/2);
      CHAR_D->set_char(p_id,"nationcontribution",CHAR_D->get_char(p_id,"nationcontribution")/2); 		
      //����������ͶƱ�ķ����ˣ��й�ֵ��1/10
      CHAR_D->set_char(v_id,"reputation",CHAR_D->get_char(v_id,"reputation")*11/10);		
      CHAR_D->set_char(v_id,"loyalty",CHAR_D->get_char(v_id,"loyalty")*11/10);		
      CHAR_D->set_char(v_id,"localcontribution",CHAR_D->get_char(v_id,"localcontribution")*11/10);
      CHAR_D->set_char(v_id,"nationcontribution",CHAR_D->get_char(v_id,"nationcontribution")*11/10); 		



      VOTE_D->del_special_vote(nation,"dismiss");
    }
 else
    { vote_info = VOTE_D->get_special_vote(nation,"dismiss");
      vote_info[2] = vote_info[2] - 1;
      if (vote_info[2]>0)
          VOTE_D->modify_special_vote(nation,"dismiss",vote_info);
      else
      {
      p_id = COUNTRY_D->get_country(nation,"gs");
      v_id = VOTE_D->get_special_vote(nation,"dismiss")[3];
      msg=sprintf("���ڲ�����ͶƱδ����㹻Ʊ����%s��ס��%s��ʦ�Ĺ�ְ��",
		CHAR_D->get_char(p_id,"name"),
		COUNTRY_D->get_country(nation,"name"));
      CHANNEL_D->deliver_tell("rumor","system",msg);
      HIS(msg);
      CHANNEL_D->deliver_tell("gossip",CHAR_D->get_char(nation,"name"),
           CHAR_D->get_char(p_id,"name")+"���䣬���˴�����ˣ������ڹ�ʦ֮λ���õ�Ϊ���˷��ǡ�");

      CHANNEL_D->deliver_tell("gossip",CHAR_D->get_char(p_id,"name"),
		"����л�������Σ��ص��Ϲ����ᱨЧ������");
      VOTE_D->del_special_vote(nation,"dismiss"); 
      
       //����������ͶƱ�ķ����ˣ��й�ֵ��1/10  
      CHAR_D->set_char(v_id,"reputation",CHAR_D->get_char(v_id,"reputation")*9/10);		
      CHAR_D->set_char(v_id,"localcontribution",CHAR_D->get_char(v_id,"localcontribution")*9/10);
      CHAR_D->set_char(v_id,"nationcontribution",CHAR_D->get_char(v_id,"nationcontribution")*9/10); 		
  
      }
      
    }
  return ;
}




mixed test_is_capital(string p_area)
{string p_gs,na;
 na = AREA_D->get_area(p_area,"nation");
 if (CHAR_D->get_char(na,"area")!=p_area)
   return  "���ǹ����׶���NPC����˼������!";
 if (CHAR_D->get_char(na,"type")==TYPE_PLAYER)
   return "��������Ϊ���,NPC����AI˼������!";
 p_gs=COUNTRY_D->get_country(na,"gs");
 if (!p_gs)
     check_guoshi_vote(na);//û�й�ʦ�Ļ��������ʦͶƱ
 else
     check_guoshi_dismiss_vote(na); //�й�ʦ�Ļ��������ʦ����ͶƱ
 return 1; 
}



mixed test_npc_taishou(string p_area){
	string m_id,p_gs;
	int status =0;
	
	if (CHAR_D->get_char(AREA_D->get_area(p_area,"nation"),"type")==TYPE_PLAYER)
	   return "��������Ϊ���,NPC����AI˼������!";
	   
	p_gs=COUNTRY_D->get_country(AREA_D->get_area(p_area,"nation"),"gs");
	if((CHAR_D->char_exist(p_gs))&&
	   (CHAR_D->get_char(p_gs,"nation")==AREA_D->get_area(p_area,"nation")))
	   return  "�����й�ʦ����,NPC����AI˼������!";
	m_id = AREA_D->get_area_leader(p_area);
	if (!m_id) {AREA_D->auto_head(p_area);return;}
	if ((CHAR_D->get_char(m_id,"type")==TYPE_NPC)&&
	   (CHAR_D->get_char(m_id,"grant")))
	   status = 1 ;  //�������̫��  
	if (CHAR_D->get_char(m_id,"type")==TYPE_PLAYER)
	   status = 2 ;  //���Ϊ̫��   	   
                 
        if (status == 0)
           {
            create_taishou(p_area);
            return "����û�����̫��,ϵͳ�Զ���ѡ���̫��!";
            }
        else
           {remove_taishou(p_area,m_id);
            return "�����������̫��,ϵͳ�������̫���ڷܶ�!";
           }
     
}

mixed test_is_fit_officer(string p_area)
{string *list_char;
 int tmp,i,rank,rank_type=0,a_type=0;
 string n,p_id,msg,ts_id,p_gs;
 mixed result;
 
 list_char=CHAR_D->check_char("area",p_area);
 n = AREA_D->get_area(p_area,"nation");
 ts_id = AREA_D->get_area_leader(p_area);
 p_gs=COUNTRY_D->get_country(n,"gs");
 
 if (CHAR_D->get_char(n,"type")==TYPE_PLAYER)
	   return "��������Ϊ���,NPC����AI˼������!";
 if (CHAR_D->char_exist(p_gs)&&
    (CHAR_D->get_char(p_gs,"nation")==n))
	   return  "�����й�ʦ����,NPC����AI˼������!";
 if ((CHAR_D->get_char(ts_id,"type")==TYPE_PLAYER)||
     ((CHAR_D->get_char(ts_id,"type")==TYPE_NPC)&&
       CHAR_D->get_char(ts_id,"grant")))
 	   a_type = 1;  //��NPC���������̫������,ֻ������ҹ�Ա�ڷܶ�,������ط���Ա
 
           
 
 for (i=0;i<sizeof(list_char);i++)
     {p_id = list_char[i];
      rank_type = 0;
      if (CHAR_D->get_char(p_id,"type")==TYPE_NPC)
          continue; //�����NPC��Ա
      if (ts_id==p_id)
          continue; //�����̫��
      if (CHAR_D->get_char_level(p_id)<2)
          continue; 
          
      if (!(rank=CHAR_D->get_char(p_id,"ranknation")))//�����Ҽ��ǹ��ҹ�Ա����
         if (a_type)  continue;      //a_type =1 ʱ,����Ҳ��ǹ��ҹ�Ա�Ͳ�����
         else
          {rank = CHAR_D->get_char(p_id,"ranklocal");  //�ط���Ա,�ȿ��ǹ��ҹ�Աְλ
           rank_type = 1;}
           
      result = ("/sgdomain/event/ev_position")->check_whole(p_id,rank);
      if (stringp(result))
         {
         if (rank_type)
            {CHAR_D->set_char(p_id,"ranklocal",R_SG);
             CHAR_D->set_char(p_id,"grant",0);
             msg=sprintf("%s����%s���ͱ�%s����%s%sְλ��",
		CHAR_D->get_char(p_id,"name"),result,
		CHAR_D->get_char(ts_id,"name"),
		AREA_D->get_area(p_area,"name"),OFFICER_D->query_rank_name(rank));
            }
         else
            {CHAR_D->set_char(p_id,"ranknation",0);
             msg=sprintf("%s����%s���ͱ�%s����%s%sְλ��",
		CHAR_D->get_char(p_id,"name"),result,
		CHAR_D->get_char(n,"name"),
		COUNTRY_D->get_country(n,"name"),
		OFFICER_D->query_rank_name(rank));
            }
         CHANNEL_D->deliver_tell("rumor","system",msg);
         HIS(msg);    
         continue;    
         }
      if ((tmp=CHAR_D->get_char(p_id,"tsx"))>0)
	 {
	  tmp -= 15;     //��Աÿ����Ѳ�����ڷܶ�С��̫��,���趨Ϊ15
	  CHAR_D->set_char(p_id,"tsx",tmp);
	  continue;
	 }
     
      tmp = CHAR_D->get_char(p_id,"nationcontribution");
      tmp = tmp * 4 / 5;
      CHAR_D->set_char(p_id,"nationcontribution",tmp);
      tmp = CHAR_D->get_char(p_id,"reputation");
      tmp = tmp * 4 / 5;
      CHAR_D->set_char(p_id,"reputation",tmp);
      if (rank_type)
        {CHAR_D->set_char(p_id,"ranklocal",R_SG);
         CHAR_D->set_char(p_id,"grant",0);
         msg=sprintf("%s���ڻķ����±�%s����%s%s��Աְλ��",
		CHAR_D->get_char(p_id,"name"),
		CHAR_D->get_char(ts_id,"name"),
		AREA_D->get_area(p_area,"name"),
		OFFICER_D->query_rank_name(rank));
	}
      else
        {CHAR_D->set_char(p_id,"ranknation",0);
         msg=sprintf("%s���ڻķ����±�%s����%s%sְλ��",
		CHAR_D->get_char(p_id,"name"),
		CHAR_D->get_char(n,"name"),
		COUNTRY_D->get_country(n,"name"),
		OFFICER_D->query_rank_name(rank));
        }
      CHANNEL_D->deliver_tell("rumor","system",msg);
      HIS(msg);        
      CHAR_D->set_char(p_id,"tsx",100); //����ְ�Ĺ�Ա���ڷܶȻָ�����ʼ��һ��   
     	                                //���ⱻ��ְ������ְ,��Ϊ�ڷܶ�Ϊ��ֵ
     	                                //�����ٴν�ְ���ܸ�����ʧ.
     }

}

void act()    //called By ai_d.c
{       mixed result;
	SGSYS("������Ѳ�ĳ�����"+cities[last_ai_city_id]);
	result=test_npc_taishou(cities[last_ai_city_id]);
	if (stringp(result)) SGSYS(result);
	result=test_is_fit_officer(cities[last_ai_city_id]);
	if (stringp(result)) SGSYS(result);
	test_is_capital(cities[last_ai_city_id]);
        if (stringp(result)) SGSYS(result);
	think_about_war();    //need to finish
	think_about_event();  //need to finish
	last_ai_city_id++;
	if (last_ai_city_id == sizeof(cities))
	   last_ai_city_id =0;
	save_data();
	//call_out("act",240);  //MUDÿ�켴��ʵ16����,��Ѳһ��
	                      //���е���ִ��һ����16*99����1584����
	                      //��ʵһ�����24*60=1440����,Լ����һ��
	                      //���г�����Ѳһ��
}

void create()
{       
   	unguarded(1, (: restore_object, SAVE_FILE, 1 :));
   	if (!last_ai_city_id) last_ai_city_id=0;
   	if (!sizeof(cities)||!arrayp(cities))
   	   {cities = AREA_D->list_areas();
   	    save_data();}
	//call_out("act",240);
	return;
}

//stop the repeated func call(start_fate) 
void remove()
{
   remove_call_out("act");
}

int clean_up() {
   return 0; // means never_again
}
