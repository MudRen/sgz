// me.c 
// by fire on August 6, 1998
string s_ret;
void start(string arg)
{
  int my_id,task_id;
  int* my_task;
  string *u_list;
  my_id=this_body()->query_id()[0];
  if(!CHAR_D->get_char(my_id,"nation"))
  {
      write("������˸�һ�ٰ�ְ�Ժ��ٿ����Լ��ɡ�\n");
      return;
  }
  my_task = TASK_D->get_char_task(my_id);
  task_id=my_task[0];
  switch(my_task[1])
  {
      case TT_WAR:
//////emperor�������¼��У���ֹ��ҷֱ�Ϊ0
		if (CHAR_D->get_char(CHAR_D->get_char(my_id,"nation"),"type")==TYPE_NPC){
      		write("����NPC������ҹ�Ա�������쵼���ز��ӡ�\n");
      		return;
      	}
//////emperor�������ϼ��У���ֹ��ҷֱ�Ϊ0
        if(CHAR_D->get_char(my_id,"level")<3)
        {
                write("��Ĺ�ְ̫�ͣ������쵼���ز��ӡ�\n");
                return;
        }

        u_list=TASK_D->get_task(task_id,"def_party");
        if(member_array(my_id,u_list)!=-1) // defmember
        {
          string def_stage;
          def_stage=TASK_D->get_task(task_id,"def_stage");
          if(def_stage=="search_leader")
          {   (EV_WAR)->i_want_leader(task_id,my_id);
              return;
          }
        }
        break;
      case TT_LOCALMEETING:
         {
           string sub;
           mixed ret;
           sub=TASK_D->get_task(task_id,"suggestion");
           if(sub!="train") break;
           ret=(EV_LOCALMEETING)->i_want_join(task_id,my_id);
           if(ret==1) return;
           write(ret); return;
         }
     }
     write("����û��ʲô����Ҫ���Լ���\n");
     return;
}
