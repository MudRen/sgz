// accountant �ʷ�����
//fire
#include <ansi.h>
#define JOBID "digsoil"
#define SOIL PJDIGSOIL+"soil"
#define S_ROOM "/a/huayin/vfield"
inherit LIVING;
object room;
object soil;
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
   set_gender(1);
   set_age(50);
   set_sg_rongmao(-1);
   add_question("job", "job");
   add_question("pay","pay");
   add_ask_str("pay","$N���������ض�$T�������ң��⣬���⣬��Ǯ������\n");
  set_clean_up(1);
}
string long() {
   return "�ʷ�����̧ͷ������һ�ۣ�\n"+
       "Ҫ������ask xian sheng about job��\n"+
       "ҪǮ��ask xian sheng about pay��\n";
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
        this_object()->simple_action("$N˵������������\n");
        this_object()->targetted_action(
         "$N��$Tʮ�����ӡ�\n",usr);
        ob=new(M_SILVER);
        ob->set_m_num(10);
        ob->move(usr);
        if(random(2)==1) {
              ob=new("/sgdomain/obj/other/tiezi");
              ob->move(usr);
             this_object()->targetted_action(
                "$N��$T�ֵ�����λ�ɵ������ɫ���ٽ���һ�����ӡ�\n",usr);
        }
    }
}
void ask_pay(object usr)
{
    string n_id;
   int p_s;
    int isrobot;
    n_id=usr->query_id()[0];
    if(!usr->query_job(JOBID,"beg_time")) {
        this_object()->targetted_action(
            "$N��$T����û�ɻ������Ǯѽ��\n",usr);
        return;
    }
    if((usr->query_job(JOBID,"status"))!="done")
    {
        this_object()->targetted_action(
          "$N��$T˵�����û��������������Ǯ����\n",usr);
        return;
    }
    this_object()->targetted_action(
      "$N��$T˵��������ɵò������һ�Ҫ����һ����,���������������\n",
      usr);
    usr->finish_job(JOBID);
    ROBOT->robot_test(usr,(:award:));
}
void ask_job(object usr)
{
    string n_id;
    int n_lasttimes,m_lasttimes;
    int p_s;
    n_id=usr->query_id()[0];
    if(CHAR_D->get_char(n_id,"nation"))
    {
       this_object()->targetted_action(
         "$N��$T��������Ц����$m$R��ɱ$sҲ���������˵Ļ�����Ͷ�$R��\n",usr);
       return;
    }
    if (usr->query_job(JOBID,"beg_time"))
    {
        this_object()->targetted_action(
         "$N��$T��������Ѿ����Ÿ����ˣ�����ȥ����\n",usr);
        return;
    }
    n_lasttimes=usr->query_job(JOBID,"count_lasttimes");
    m_lasttimes=JOB_D->query_job(JOBID,"count_lasttimes");
    if(n_lasttimes>m_lasttimes)
    {
      this_object()->targetted_action(
          "$N��$T�����������ؽ�ˮ�Ļ�ɵù�����ˣ�����Ϣ��Ϣ�ˡ�\n",usr);
        return;
    }
    room=load_object(S_ROOM);
    soil=present("soil", room );
    soil->set_status(0);
    usr->resign_job(JOBID);
    usr->add_job(JOBID);
    usr->set_job(JOBID,"status","beg");
    this_object()->targetted_action(
     "$N��$T�����Ǻã��山ͷ�ǿ�ؾͽ������ˣ�\n"+
     "�س��ã�ˮ���㣬������Ǯ�ɣ����ߵ�����ȥ�ҡ�\n",usr);
}
