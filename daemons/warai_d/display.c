// display.c
// to display the fight message
static private mapping old_inf=([]);
string get_neighbor_troop_name(int t_id,string direction);
void create_inf(int t_id)
{
    old_inf[t_id]=([]);
}
mixed query_inf()
{  return old_inf;
}
string get_dir_name(string dir)
{
   switch(dir)
   {
        case "e":
        case "east": return "����";
        case "s":
        case "south": return "����";
        case "w":
        case "west": return "����";
        case "n":
        case "north": return "����";
        case "e 2":
        case "east 2": return "����";
        case "s 2":
        case "south 2": return "�Ϸ�";
        case "w 2":
        case "west 2": return "����";
        case "n 2":
        case "north 2": return "����";
        
        case "nw":
        case "northwest": return "������";
        case "ne":
        case "northeast": return "������";
        case "sw":
        case "southwest": return "���Ϸ�";
        case "se":
        case "sougheast": return "���Ϸ�";
        default: return "δ֪";
    }
}
string get_dir_name_opp(string dir)
{
   string p_dir;
 
   switch(dir)
   {
        case "e":
        case "east": p_dir="w";break;
        case "s":
        case "south": p_dir="n";break;
        case "w":
        case "west": p_dir="e";break;
        case "n":
        case "north": p_dir="s";break;
        case "e 2":
        case "east 2": p_dir="w 2";break;
        case "s 2":
        case "south 2": p_dir="n 2";break;
        case "w 2":
        case "west 2": p_dir="e 2";break;
        case "n 2":
        case "north 2": p_dir="s 2";break;
        
        case "nw":
        case "northwest": p_dir="se";break;
        case "ne":
        case "northeast": p_dir="sw";break;
        case "sw":
        case "southwest": p_dir="ne";break;
        case "se":
        case "sougheast": p_dir="nw";break;
        default: return "δ֪";
    }
    return get_dir_name(p_dir);
}
void war_inf(int t_id,string mess,string side)
{
   string *att,*def;   
   string m_mess;
   int p_time=time();
   if(mess[<1]!=10)
      mess+="\n";
   
   switch(side)
   {   case "a" :
           m_mess="%^H_RED%^��������"+mess+"%^RESET%^";
           att=TASK_D->get_task(t_id,"att_party");
           if(sizeof(att))
           {
		foreach(string u in att)
                {
                   tell_user(u,m_mess);
                }
           }
           return;
       case "d" :
           m_mess="%^H_GREEN%^���ط���"+mess+"%^RESET%^";
           def=TASK_D->get_task(t_id,"def_party");
           if(sizeof(def))
           {
                foreach(string u in def)
                {
                   tell_user(u,m_mess);
                }
           }
           return;
      default:
           if(!old_inf[t_id])
              old_inf[t_id]=([]);
           
           if((old_inf[t_id][mess])&&(p_time-old_inf[t_id][mess]<60)) 
		return;
           old_inf[t_id][mess]=p_time;
           m_mess="%^H_BLUE%^��ս����"+mess+"%^RESET%^";
           def=TASK_D->get_task(t_id,"def_party");
           if(sizeof(def))
           {
                foreach(string u in def)
                {
                   tell_user(u,m_mess);
                }
           }
           att=TASK_D->get_task(t_id,"att_party");
           if(sizeof(att))
           {
		foreach(string u in att)
                {
                   tell_user(u,m_mess);
                }
           }
           return;
     }
}
string get_troops_name(string p_id,int x,int y)
{
    int *t;
    string ret;
    int sum,i;
    t=MAP_D->get_map_cell(p_id,y,x,"t");
    if((!t)||(!sizeof(t)))
       return "";
    sum=sizeof(t);
    switch(sum)
    {
         case 1:
           ret=TROOP_D->find_troop(t[0])->query_id()[1];
           return ret;
         case 2:
           ret=TROOP_D->find_troop(t[0])->query_id()[1]+
              "��"+TROOP_D->find_troop(t[1])->query_id()[1];
	   return ret;
    }
    ret=TROOP_D->find_troop(t[0])->query_id()[1];
    for(i=1;i<sum-1;++i)
    {
	ret+="��"+TROOP_D->find_troop(t[i])->query_id()[1];
    }
    ret+="��"+TROOP_D->find_troop(t[i])->query_id()[1];
    return ret;
}
string get_generl_infomation(int p_id,string dir)
{
   string ret;
   string p_dir;
   string p_troop;
   ret=TROOP_D->find_troop(p_id)->query_id()[1]+"��";
   p_dir=get_dir_name(dir);
   ret+=p_dir+"��";
   p_troop=get_neighbor_troop_name(p_id,dir);
   ret+=p_troop+"����������";
   return ret;
}
void info_troop(int p_id,string mess)
{
   object o_troop, o_env;
   object *o_char;
   o_troop=TROOP_D->find_troop(p_id);
   if(!objectp(o_troop)) return;
   o_env=environment(o_troop);
   if(!o_env) return ;
   o_char=deep_inventory(o_env);
   o_char=filter_array(o_char,(:($1)->query_link():));
   if(mess[<1]!=10)
      mess+="\n";
   tell(o_char,mess);
}
string get_generl_infomation_b(int p_id,string dir)
{
   string ret;
   string p_dir;
   string p_troop;
   ret=TROOP_D->find_troop(p_id)->query_id()[1]+"��";
   p_dir=get_dir_name_opp(dir);
   ret+=p_dir+"���������";
   return ret;
}
string get_array_attack_infomation_b(int p_id,string dir)
{
   string ret;
   string p_dir;
   string p_troop;
   ret=TROOP_D->find_troop(p_id)->query_id()[1]+"��";
   p_dir=get_dir_name_opp(dir);
   ret+=p_dir+"����������ꡣ";
   return ret;
}
string get_array_attack_infomation(int p_id,string dir)
{
   string ret;
   string p_dir;
   string p_troop;
   ret=TROOP_D->find_troop(p_id)->query_id()[1]+"һ���Ҽ���";
   p_dir=get_dir_name(dir);
   ret+=p_dir+"��";
   p_troop=get_neighbor_troop_name(p_id,dir);
   ret+=p_troop+"��ȥ��";
   return ret;
}
string get_horse_attack_infomation_b(int p_id,string dir)
{
   string ret;
   string p_dir;
   string p_troop;
   ret=TROOP_D->find_troop(p_id)->query_id()[1]+"��������Ӵ�";
   p_dir=get_dir_name_opp(dir);
   ret+=p_dir+"��ɱ������";
   return ret;
}
string get_horse_attack_infomation(int p_id,string dir)
{
   string ret;
   string p_dir;
   string p_troop;
   ret=TROOP_D->find_troop(p_id)->query_id()[1]+"�����������";
   p_dir=get_dir_name(dir);
   ret+=p_dir+"��";
   p_troop=get_neighbor_troop_name(p_id,dir);
   ret+=p_troop+"��ɱ��ȥ��";
   return ret;
}
string get_siege_attack_infomation(int p_id,string dir,mixed seg)
{
   string ret;
   string p_troop;
   string *d;
   int *t,i;
   p_troop=get_neighbor_troop_name(p_id,dir);
   d=keys(seg);
   t=({});
   foreach(string di in d)
   {
      t+=seg[di]["troop"];  
   }
   ret=TROOP_D->find_troop(t[0])->query_id()[1];
   for(i=1;i<(sizeof(t)-1);++i)
   {
      ret+="��"+TROOP_D->find_troop(t[i])->query_id()[1];
   }
   ret+="��"+TROOP_D->find_troop(t[i])->query_id()[1];
   ret+="��"+chinese_number(sizeof(d))+"�������"+
   p_troop+"�������ҹ�����\n";
   return ret;
}
string get_siege_attack_infomation_b(int p_id,string dir,mixed seg)
{
   string ret;
   string *d;
   int *t,i;
   d=keys(seg);
   t=({});
   foreach(string di in d)
   {
      t+=seg[di]["troop"];  
   }
   ret=TROOP_D->find_troop(t[0])->query_id()[1];
   for(i=1;i<(sizeof(t)-1);++i)
   {
      ret+="��"+TROOP_D->find_troop(t[i])->query_id()[1];
   }
   ret+="��"+TROOP_D->find_troop(t[i])->query_id()[1];
   ret+="��"+chinese_number(sizeof(d))+"�����򹥴����\n";
   return ret;
}
