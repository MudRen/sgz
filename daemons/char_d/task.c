// task.c
// by fire on Dec 1998
string get_taskstr(string p_id)
{
   int p_task;
   p_task=CHAR_D->get_char(p_id,"task");
  switch(p_task)
  {
    case TASK_NONE: return ("����");
    case TASK_MEETING: return ("����");
    case TASK_WAR: return("ս��");
   case TASK_TRAIN: return("����");
   default: return ("δ֪");
  }
}
int get_task(string p_id)
{
        mixed task;
        int ret;
        task=TASK_D->get_char_task(p_id);
        switch(task[1])
        {case 0: return TASK_NONE;
         case TT_LOCALMEETING: return TASK_MEETING;
         case TT_WAR: return TASK_WAR;
        case TT_TRAIN: return TASK_TRAIN;
         default: return TASK_UNKNOW;
        }
}
