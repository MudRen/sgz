// accountant �ʷ�����
//fire
#include <ansi.h>
#define JOBID "digsoil"
#define SOIL PJDIGSOIL+"soil"
#define S_ROOM FROOMPATH+"vfield"
inherit LIVING;
object room;
object soil;
string employee;
int starttime;
void ask_pay(object usr);
void ask_job(object usr);
void setup()
{
   object jia;
   jia=new(PTORSO+"choup");
   jia->move(this_object());
   jia->do_wear();
   set_name("xian sheng", "�ʷ�����");
   set_in_room_desc("��"+HIR+"���ɻ��������Ǯ"+NOR+"���ʷ�����(xian sheng)");
   set_long("�ʷ�����̧ͷ������һ�ۣ�\n"+
       "Ҫ������ask xian sheng about job��\n"+
       "ҪǮ��ask xian sheng about pay��\n");
   set_gender(1);
   set_age(50);
   set_sg_rongmao(-1);
   employee="";
   starttime=0;
   add_question("job", "job");
   add_question("pay","pay");
   add_ask_str("pay","$N���������ض�$T�������ң��⣬���⣬��Ǯ������\n");
  set_clean_up(1);
}
mixed special_answer(object ob, string str)
{
   object player;
   player = this_body();
   switch(str)
   {
      case "job":
          ask_job(player);
          return;
      case "pay":
          ask_pay(player);
          return;
      default:
         return ;
    }
}
void award(object usr)
{
    int isrobot;
    object ob;
    isrobot=usr->query_robot();
    if(isrobot)
    {   this_object()->simple_action(
         "$N��Ц�������Ǹ��׳�,�ٺ١�\n");
        this_object()->targetted_action(
         "$N��$T����$R�������ܸɣ��ִ��������ǽ����Ŵ�Ʊ�ӡ�\n",usr);
        this_object()->targetted_action(
         "$N��$Tһ�Ű�ԲֽǮ���\n",usr);
        usr->simple_action("$N���˵����ƣ��ã��ã�л�����ʹ͡�\n");
        ob=new(PMONEY+"fmoney");
        ob->move(usr);
    }
    else
    {
        string p_id;
        p_id=usr->query_id()[0];
        CHAR_D->set_char(p_id,"reputation",
         CHAR_D->get_char(p_id,"reputation")+1);
        tell_user(p_id,"�����������ˡ�\n");
        this_object()->simple_action("$N˵������������\n");
        this_object()->targetted_action(
         "$N��$T��ʮ�����ӡ�\n",usr);
        ob=new(M_SILVER);
        ob->set_m_num(20);
        ob->move(usr);
    }
}
void ask_pay(object usr)
{
    string n_id;
   int p_s;
    int isrobot;
    n_id=usr->query_id()[0];
    if (employee!=n_id)
    {
        if(usr->query_job(JOBID,"beg_time"))
        {
          this_object()->targetted_action(
            "$N��$T��������Ѿ��������ˡ�\n",usr);
          usr->resign_job(JOBID);
          return;
        }
        this_object()->targetted_action(
            "$N��$T����û�ɻ������Ǯѽ��\n",usr);
        return;
    }
    room=load_object(S_ROOM);
    soil=present("soil", room );
    p_s=soil->query_status();
    if(p_s<40)
    {
        this_object()->targetted_action(
          "$N��$T˵�����û��������������Ǯ����\n",usr);
        return;
    }
    this_object()->targetted_action(
      "$N��$T˵��������ɵò������һ�Ҫ����һ����,���������������\n",usr);
    usr->finish_job(JOBID);
    employee="";
    starttime=0;
    ROBOT->robot_test(usr,(:award:));
}
void ask_job(object usr)
{
    string n_id;
    int n_lasttimes,m_lasttimes;
    int p_s;
    n_id=usr->query_id()[0];
    if (employee==n_id)
    {
        this_object()->targetted_action(
         "$N��$T��������Ѿ����Ÿ����ˣ�����ȥ����\n",usr);
        return;
    }
    if(employee!="") // some body working
    {
        object e;
        e=find_body(employee);
        if(objectp(e)) // this guy still on line
        {
           if((time()-starttime)<600) // not long to 10 min
           {
                this_object()->targetted_action(
                 "$N��$T�����������������������������ɡ�\n",usr);
                return;
           }
         }
    }
    if(CHAR_D->get_char(n_id,"nation"))
    {
       this_object()->targetted_action(
         "$N��$T��������Ц����$m$R��ɱ$sҲ���������˵Ļ�����Ͷ�$R��\n",
usr);
       return;
    }
    n_lasttimes=usr->query_job(JOBID,"count_lasttimes");
    m_lasttimes=JOB_D->get_job(JOBID,"count_lasttimes");
    m_lasttimes=10; // because job_d not finished
    if(n_lasttimes>m_lasttimes)
    {
      this_object()->targetted_action(
          "$N��$T���������ɵĻ����ˣ�����Ϣ��Ϣ�ˡ�\n",usr);
        return;
    }
    room=load_object(S_ROOM);
    soil=present("soil", room );
    p_s=soil->query_status();
    if(p_s>20)
    {
        this_object()->targetted_action(
          "$N��$T��������ûʲô����ɸɣ�����������ɡ�\n",usr);
        return;
    }
    usr->resign_job(JOBID);
    usr->add_job(JOBID);
    employee=n_id;
    starttime=time();
    this_object()->targetted_action(
     "$N��$T�����Ǻã��山ͷ�ǿ�ؾͽ������ˣ�\n"+
     "�س��ã�ˮ���㣬������Ǯ�ɣ����ߵ�����ȥ�ҡ�\n",usr);
}