// warorder.c 
// by fire on Oct 7, 1998
// used for player to give order for other troops
mixed get_pos(string para)
{
   int *pos=({0,0});
   if(sizeof(para)<2) return 0;
   pos[0]=para[0]-'A';
   if((pos[0]<0)||(pos[0]>25)) return 0;
   pos[1]=to_int(para[1..<1]);
   pos[1]--;
   if((pos[1]<0)||(pos[1]>25)) return 0;
   return pos;
}
mixed order_stay()
{
   return (["action":"stay"]);
}
mixed order_match(string para)
{
   mixed pos;
   mapping ret=([]);
   pos=get_pos(para);
   if(!sizeof(pos)) return "��������\n";
   ret["action"]="match";
   ret["target"]=WARAI_D->point_tostring(pos);
   return ret;
}
mixed order_guard(int t_id,string para,string range)
{
   mixed pos;
   mapping ret=([]);
   int ran;
   if((!para)||(para==""))
     pos=TROOP_D->get_troops(t_id,"position");
   else
   {
     pos=get_pos(para);
     if(!sizeof(pos)) return "��������\n";
   }
   if((!range)||(range=="")) ran=1;
   else
        ran=to_int(range);
   
   ret["action"]="guard";
   ret["position"]=WARAI_D->point_tostring(pos);
   ret["range"]=ran;
   return ret;
}
int get_t_id(string tid)
{
   string id;
   if(tid[0..4]!="troop") return -1;
   id=tid[5..<1];
   return to_int(id);
}
mixed order_pursue(int *all_troop,string para)
{
   mapping ret=([]);
   int t;
   
   t=get_t_id(para);
   if(t<=0) return "��������\n";
  if(member_array(t,all_troop)==-1)
    return "׷����֧���ӣ�\n"; 
  ret["action"]="pursue";
   ret["aim"]=t;
   return ret;
}
void start(string arg)
{
    string tar="",cmd="",para1="",para2="";
    string *ex;
    int *troops, *troopt;
    int args;
    int t_id;
    object o;
    mixed order;
    int fake_s=0;
    int *t_task,task_id,*my_troops,*all_troops;
    string p_side,p_id;
    p_id=this_body()->query_id()[0];
    t_task=TASK_D->get_char_task(p_id);
    if((t_task[0]==-1)||((t_task[1]!=TASK_WAR)&&(t_task[1]!=TASK_TRAIN)))
    {  write("��û��ս���У�����ָ�Ӿ��ӡ�\n");
       return;
    }
    
    task_id=t_task[0];
    p_side="";
    if(TASK_D->get_task(task_id,"def_leader")==p_id){
       p_side="d";
       my_troops=TASK_D->get_task(task_id,"def_army");
       all_troops=TASK_D->get_task(task_id,"att_army");
    }
    if(TASK_D->get_task(task_id,"att_leader")==p_id){
       p_side="a";
       my_troops=TASK_D->get_task(task_id,"att_army");
       all_troops=TASK_D->get_task(task_id,"def_army");
    }
    troopt = TROOP_D->list_troops();
    if(!troopt)troopt =({});
    troops = ({});
    foreach(int c in troopt)
   {
      if(TROOP_D->get_troops(c,"fake")==p_id)
		troops +=({c});
   }

    if(sizeof(troops))
	{ p_side = TROOP_D->get_troop_side(p_id);
	  fake_s =1;
	  my_troops += troops;
	}

    if(p_side=="")
    {  write("ֻ��ս��ͳ˧�ſ��ԶԾ����´����\n");
       return;
    }
    if(!all_troops) all_troops=({});
    if(!my_troops) my_troops=({});
    all_troops+=my_troops;
    ex=explode(arg," ");
    if(sizeof(ex)>0) tar=ex[0];
    if(sizeof(ex)>1) cmd=ex[1];
    if(sizeof(ex)>2) para1=ex[2];
    if(sizeof(ex)>3) para2=ex[3];
    t_id=get_t_id(tar);
    if(t_id<=0) 
    { write ("��Ҫָ����֧���ӣ�\n"); return;
    }
    o=TROOP_D->find_troop(t_id);
    if(!objectp(o))
    { write ("��Ҫָ����֧���ӣ�\n"); return;
    }
    if(member_array(t_id,my_troops)==-1)
    { write ("��Ҫָ����֧���ӣ�\n"); return;
    }
// here need more check to make sure this user has the 
// right to give this order
    switch(cmd)
    {
       case "stay": order=order_stay(); break;
       case "go":
       case "match": order=order_match(para1); break;
       case "guard": order=order_guard(t_id,para1,para2); break;
       case "follow":
       case "pursue": order=order_pursue(all_troops,para1); break;
       default : write("û������ָ�\n"); return;
    }
    if(stringp(order))
    {  write(order); return;
    }
    if(fake_s) tell_user(p_id,"�����Ѿ��ɹ��´\n");
    TROOP_D->set_troops(t_id,"command",order);
    WARAI_D->order_display(t_id);
}
