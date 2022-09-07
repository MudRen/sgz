//order_display.c by fire
//this is used to display order on the war channel
mixed point_toint(string point);
void war_inf(int t_id,string mess,string side);
string get_pos_disp(int* t)
{
   string ps="���£ãģţƣǣȣɣʣˣ̣ͣΣϣУѣңӣԣգ֣ףأ٣�";
   string ret="";
   ret=ps[t[0]*2..t[0]*2+1];
   ret+=sprintf("%d",t[1]+1);
   return ret;
}
void order_display(int t)
{
   mixed cmd;
   string p_side,p_display="";
   string t_tmp,p_name;
   int task_id;
   cmd=TROOP_D->get_troops(t,"command");
   if(!sizeof(cmd)) return;
   if(!cmd["action"]) return;
   p_side=TROOP_D->get_troops(t,"side");
   p_display=TROOP_D->get_troops(t,"name");
   p_display+="����";
   switch(cmd["action"])
   {
      case "stay": p_display+="��ԭ�ش�����";break;
      case "match": 
        t_tmp=get_pos_disp(point_toint(cmd["target"]));
        p_display+="��"+t_tmp+"���о���";
        break;
      case "guard":
        t_tmp=get_pos_disp(point_toint(cmd["position"]));
        p_display+="��"+t_tmp+"�����أ���Χ�ǣ�"+
           chinese_number(cmd["range"])+"��";
        break;
      case "pursue": 
        p_name=TROOP_D->get_troops(cmd["aim"],"name");
        if(TROOP_D->get_troop(cmd["aim"],"side")==p_side)
           p_display+="����"+p_name+"һ���ж���";
        else
           p_display+="׷��"+p_name+"��";
        break;
      default: return;
    }
    task_id=TROOP_D->get_troops(t,"task_id");
    war_inf(task_id,p_display,p_side);
}           
        
