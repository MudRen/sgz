// kill.c
// this is the file to handle the death of soldier of troop

// #define _DEBUG_ID   "xiaobai"

void war_inf(int t_id,string mess,string side);
void info_troop(int p_id,string mess);
string get_generl_infomation(int p_id,string dir);
string get_generl_infomation_b(int p_id,string dir);
void add_war_lose(int t_id,string p_side,string wat,int num);
mixed get_neighbor_defence_rate(int t_id,string direction);
mixed get_neighbor_troops(int t_id,string direction);
void general_attack_kill_back(int p_id,string dir);

void clear_empty_troop(int* t)
{
    int sum,i;
    sum=sizeof(t);
    if(!sum)
    return;
    for(i=0;i<sum;++i)
    {
	if((TROOP_D->get_troops(t[i],"total_num")==0)||
            (sizeof(TROOP_D->get_troops(t[i],"chars"))==0))
        {
	    int task_id;
            task_id=TROOP_D->get_troops(t[i],"task_id");	
            war_inf(task_id,
	      TROOP_D->find_troop(t[i])->query_id()[1]+
	       "�������ˣ�","b");
            {
               mixed army;
               if(TROOP_D->get_troops(t[i],"side")=="a")
               {
                  army=TASK_D->get_task(task_id,"att_army");
                  army-=({t[i]});
                  TASK_D->set_task(task_id,"att_army",army);
		  TROOP_D->add_morale(army,-10);
               }
               else
               {
                  army=TASK_D->get_task(task_id,"def_army");
                  army-=({t[i]});
                  TASK_D->set_task(task_id,"def_army",army);
		  TROOP_D->add_morale(army,-5);
               }
            }
            TROOP_D->remove_troop(t[i]);
        }
    }
}
int kill_troop(int p_id,int p_kill)
{
   int real_kill=0;
   mixed soldier;
   int total_num;
   string *p_type;
   string p_side;
   int task_id;
   p_side=TROOP_D->get_troops(p_id,"side");
   task_id=TROOP_D->get_troops(p_id,"task_id");
   total_num=TROOP_D->get_troops(p_id,"total_num");
   if(!total_num) return 0;
   soldier=TROOP_D->get_troops(p_id,"soldier");
   if(!sizeof(soldier))
      return 0;
   p_type=keys(soldier);
   foreach(string p_t in p_type)
   {
      int my_num,m_kill;
      my_num=soldier[p_t]["number"];
      m_kill=p_kill*my_num/total_num+1;
      if(m_kill>my_num) m_kill=my_num;
      if(m_kill) add_war_lose(task_id,p_side,p_t,m_kill);
      real_kill+=m_kill;
      soldier[p_t]["number"]=my_num-m_kill;
      if((my_num-m_kill)==0)
         map_delete(soldier,p_t);
    }
    TROOP_D->set_troops(p_id,"soldier",soldier);
    return real_kill;
}
int kill_troops(mixed t,int p_kill)
{
   int real_kill=0;
   int total_num;
   int troop_number,i;
   troop_number=sizeof(t);
   if(!t) return 0;
   total_num=0;
   for(i=0;i<troop_number;++i)
   {
      total_num+=TROOP_D->get_troops(t[i],"total_num");
   }
   for(i=0;i<troop_number;++i)
   {
       int t_kills;
       mixed soldier;
       int p_num;
       p_num=TROOP_D->get_troops(t[i],"total_num");
if(p_num==0) return 0;
       t_kills=p_kill*p_num/total_num+1;
       real_kill+=kill_troop(t[i],t_kills);
   }
   return real_kill;
}
void general_attack_kill(int p_id, string dir)
{
   string mess;
    int p_kill,p_defrate;
    int *t;
	p_kill=TROOP_D->get_attack_rate(p_id,"general");
    t=get_neighbor_troops(p_id,dir);
	p_kill=TROOP_D->attack_troops(t,p_kill,"general");
    mess=get_generl_infomation(p_id,dir);
    info_troop(p_id,mess);
    info_troop(p_id,"%^H_GREEN%^����о�"+CHINESE_D->chinese_number(p_kill)+"�ˣ�%^RESET%^\n");
    mess=get_generl_infomation_b(p_id,dir);
    info_troop(t[0],mess);
    info_troop(t[0],"%^H_RED%^�ҷ���ʧ"+CHINESE_D->chinese_number(p_kill)+"�ˣ�%^RESET%^\n");
    clear_empty_troop(t);
}

#if 0
void general_attack_kill_back(int p_id,string dir)
{
    int p_kill;
    int *t,i,sum;
    t=get_neighbor_troops(p_id,dir);
    sum=sizeof(t);
    if(!sum) return;
    p_kill=0;
    for(i=0;i<sum;++i)
    {
		p_kill+=TROOP_D->get_attack_rate(t[i],"general");
    }
    p_kill=p_kill/2;
	p_kill=TROOP_D->attack_troops(({p_id}),p_kill,"general");

    info_troop(t[0],"�ҷ���ʿ���𻹻���");
    info_troop(t[0],"%^H_GREEN%^����о�"+TROOP_D->find_troop(p_id)->query_id()[1]+
        CHINESE_D->chinese_number(p_kill)+"�ˣ�%^RESET%^\n");
    info_troop(p_id,"�о�����ˣ�");
    info_troop(p_id,"%^H_RED%^�ҷ�"+TROOP_D->find_troop(p_id)->query_id()[1]+
       "��ʧ"+CHINESE_D->chinese_number(p_kill)+"�ˣ�%^RESET%^\n");
    clear_empty_troop(({p_id}));
}
#endif 

void general_attack_kill_back( int p_id,string dir )
{
    int p_kill;
    int *t,i,sum;
    string* p_strlstTrpLeader;  // ���� id ��
    string p_strId;
    int p_nLeaderNum = 0;
    string* p_strlstTrpType;  // ���ӱ��ּ�
    string p_strType;
    mixed p_soldiers;  // �����и����ֶַ�  
    int is_npc = 1;
    
    // xiaobai: �������ڶ��ǵ�һ���֣��� p_id ���ӵı���, ֻ����һ�ֶ�
    p_soldiers = TROOP_D->get_troops(p_id,"soldier");
    p_strlstTrpType = keys(p_soldiers);
    p_strType = p_strlstTrpType[0];
    
    t = get_neighbor_troops(p_id,dir);
    sum=sizeof(t);
    if(!sum) return;
    p_kill=0;
    for(i=0;i<sum;++i)
    {
        switch( p_strType )
        {       
            case "bowman":
                // xiaobai: only pure npc troop will kill back
                is_npc = 1;
                p_strlstTrpLeader = TROOP_D->get_troops( t[i], "chars" );
                p_nLeaderNum = sizeof( p_strlstTrpLeader );
                foreach( p_strId in p_strlstTrpLeader )
                {
#ifdef _DEBUG_ID
        tell_user( _DEBUG_ID, sprintf( "���� %s �� npc : %d ��", p_strId, ( CHAR_D->get_char_status( p_strId ) != STATUS_ONLINE ) ) );        
#endif
                    if ( CHAR_D->get_char_status( p_strId ) == STATUS_ONLINE )
                    {
                        // one of the troop leader is online, this troop is a player troop
                        is_npc = 0;
                        break;
                    }
                    
                }  // end loop, for leaders of a troop
                
                if ( is_npc )
                {
                    // xiaobai: �Թ����ķ������趨Ϊ��ͨ��һ��                
                    p_kill += TROOP_D->get_attack_rate(t[i],"general")/2;
                    
                    info_troop( t[i], "���ֵо��������, �������ӹ�ľ��ʯ׼��������");
    	            info_troop( p_id, "������ر��о�����, �о���Ӫ���ֹ�ľ��ʯ��");
                 }
                 break;

            default:
                p_kill+=TROOP_D->get_attack_rate(t[i],"general");
                break;
        
        }  // end switch
                   
    }

    if ( p_kill > 0 )
    {
        p_kill=p_kill/2;
    	p_kill=TROOP_D->attack_troops(({p_id}),p_kill,"general");
    
        info_troop(t[0],"�ҷ���ʿ���𻹻���");
        info_troop(t[0],"%^H_GREEN%^����о�"+TROOP_D->find_troop(p_id)->query_id()[1]+
            CHINESE_D->chinese_number(p_kill)+"�ˣ�%^RESET%^\n");
        info_troop(p_id, "�о�����ˣ�");
        info_troop(p_id,"%^H_RED%^�ҷ�"+TROOP_D->find_troop(p_id)->query_id()[1]+
           "��ʧ"+CHINESE_D->chinese_number(p_kill)+"�ˣ�%^RESET%^\n");
        clear_empty_troop(({p_id}));

#ifdef _DEBUG_ID
        tell_user( _DEBUG_ID, sprintf( "\n�Ա��� %s ���з�����ɱ�� %d �ˡ�\n", p_strType, p_kill ) );        
#endif
        
    }
}
