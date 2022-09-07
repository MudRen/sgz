// train.c
// by fire on Dec 1998
// this is used to handle the suggestion of train
void dis_over(int task_id);
mixed i_want_join(int task_id,string my_id);
void auto_want_join(int task_id);
void discuss_train(int task_id,int p_disnum)
{
   string p_area,p_leader;
   object o_leader;
   p_area=TASK_D->get_task(task_id,"area");
   p_leader=AREA_D->get_area(p_area,"leader");
   o_leader=CHAR_D->find_char(p_leader);
   if(p_disnum==1) // first time
   {
      if(objectp(o_leader))
          o_leader->simple_action(
     "$N��������ǧ�գ��ñ�һʱ���˵��ǣ���������������֪��λ\n�������˻�Ըһͬ������\n");
     call_out("auto_want_join",random(3)+1,task_id);
   }
   if(p_disnum>5)
   {
      string *join,*suggested,leader;
      join=TASK_D->get_task(task_id,"supportgrp");
      TASK_D->set_task(task_id,"traingrp",join);
      if(objectp(o_leader))
          o_leader->simple_action("$N����������̸��������Ϳ�ʼ�����ɡ�\n");
      leader=TASK_D->get_task(task_id,"suggestionppl");
      TASK_D->set_task(task_id,"trainleader",leader);
      suggested=TASK_D->get_task(task_id,"suggested");
      if(!arrayp(suggested))
              suggested=({});
      suggested+=({"train"});
      TASK_D->set_task(task_id,"suggested",suggested);
      dis_over(task_id);
   }
}
void auto_want_join(int task_id)
{
    string p_subject,my_id;
    string p_leader;  // ̫�� id
    string p_area;  // ���� id
    mixed chars,join,left;
    int nleft;

    p_area=TASK_D->get_task(task_id,"area");
    p_leader=AREA_D->get_area(p_area,"leader");
    
    p_subject=TASK_D->get_task(task_id,"suggestion");
    if(p_subject!="train") // discuss over
       return ;
    chars=TASK_D->get_task(task_id,"chars");
    chars=keys(chars);
    join=TASK_D->get_task(task_id,"supportgrp");
    left=chars-join;
    nleft=sizeof(left);
    if(!nleft) return;
    my_id=left[random(nleft)];
    // xiaobai: ����̫�ص� npc �Ż�μ�ѵ��
    if( ( my_id!=p_leader ) && ( CHAR_D->get_char_status(my_id)!= STATUS_ONLINE ) )
    {
       i_want_join(task_id,my_id);
    }
     call_out("auto_want_join",random(3)+1,task_id);
}
mixed i_want_join(int task_id,string my_id)
{
   object o_id;
   string* join_group;
   o_id=CHAR_D->find_char(my_id);
   join_group=TASK_D->get_task(task_id,"supportgrp");
   if(!join_group) // that is impossible
      join_group=({});
   if(member_array(my_id,join_group)==-1)
   {
       if(objectp(o_id))
         o_id->simple_action("$N����$sԸһͬ������\n");
       join_group+=({my_id});   
       TASK_D->set_task(task_id,"supportgrp",join_group);
       return 1;
   }
   return "���Ѿ�Ҫ����ˡ�\n";
}