// yufu.c (���)
#include <ansi.h>
#include <mudlib.h>
#define JOBID "fishing"
inherit LIVING;
string employee;
int starttime;
void ask_job(object usr);
void ask_pay(object usr);
void setup()
{
        set_name("yu fu", "���");
        add_id("yufu");
        set_in_room_desc("���ڲ�������(yu fu)");
        set_long("һλ��ͺܴ����򣬱����紵���\n"+
        "Ҳ�����ܰ���һЩæ(ask yu fu about job)��\n");
        set_gender(1);
        set_age(56);
        set_sg_rongmao(-5);
        employee="";
        starttime=0;   
        add_question("job","job");
        add_question("pay","pay");
        add_question("name", "name");
        add_question("rumors", "rumors");
        add_ask_str("job","$N��$T������λ$R����ʲô�ҿ��԰������\n");
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
        case "name":
                this_object()->targetted_action("$N΢΢���˵�ͷ����"+
                        "С���С�ڴ˲��㣬��������ҳݡ�\n", ob);
                return;
        case "rumors":
                this_object()->targetted_action("$NЦ����"+
                        "С���С�ڴ˲��㣬��֪��������¡�\n", ob);
                return;
        default:   
                return;
        }
}
                
void ask_job(object usr)
{
        string n_id;
        int n_lasttimes,m_lasttimes;
        int p_s;
        object ob;
        n_id=usr->query_id()[0];
        if(employee==n_id)
        {
        this_object()->targetted_action("$N��$T������ȥ����Ļ�ɡ�\n",usr);
        return;
        }
        if(employee!="")
        {
        object e;
        e=find_body(employee);
        if(objectp(e))
        {
                if((time()-starttime)< 300)
                {
                this_object()->targetted_action(
                "$N��$T��������Ѿ������ڸ��ˣ����������ɡ�\n",usr);
                return;
                }
        }
        }
        if(CHAR_D->get_char(n_id,"nation"))
        {
        this_object()->targetted_action(
        "$Nһ����������˵Ļ�����Ͷ�$R����Ҫ���㣬"+
        "$s�պ����Է��ͼ����ϸ���\n", usr);
        return;
        }
        n_lasttimes=usr->query_job(JOBID,"count_lasttimes");
        m_lasttimes=JOB_D->get_job(JOBID,"count_lasttimes");
        m_lasttimes=15; 
        if(n_lasttimes>m_lasttimes)
        {
        this_object()->targetted_action(
        "$N��$T���������ɵĻ����ˣ�����Ϣ��Ϣ�ˡ�\n",usr);
        return; 
        }
        usr->resign_job(JOBID);
        usr->add_job(JOBID);
        employee=n_id;
        starttime=time();
        this_object()->targetted_action(
        "$N��$T�����ðɣ�����Ҳ���������ɡ��������������ðɡ�\n", usr);
        this_object()->targetted_action("$N����$Tһ��������\n",usr);
        ob=new("/sgdomain/job/fishing/net");
        ob->move(usr);
}
         
void award(object usr)  
{
        int isrobot;
        object ob;
        isrobot=usr->query_robot();
        if(isrobot)
        {
        this_object()->simple_action("$N΢΢һЦ��ԭ����ˣ��ðɡ�\n");
        this_object()->targetted_action("$N��$Tһ�Ű�ԲֽǮ��\n",usr);
        usr->simple_action("$N���˵�ֱ�֣�������Ǯ�ˣ�\n");
        ob=new(PMONEY+"fmoney");
        ob->move(usr);
        }
        else
        {
        string p_id;
        int p_sjlev, p_sjexp;   
        p_id=usr->query_id()[0];
        p_sjlev=usr->query_sk_level("jbsj");
        p_sjexp=usr->query_sk_exp("jbsj");
        if((p_sjlev<50) )
        {
                write("��Ļ���ˮ������ˡ�\n");
                usr->award_exp(100,"jbsj");
        }
        this_object()->simple_action("$N������������\n");
        this_object()->targetted_action("$N��$Tʮ�����ӡ�\n",usr);
        ob=new(M_SILVER);
        ob->set_m_num(10);
        ob->move(usr);
        }
}
void ask_pay(object usr)
{
        object ob;
        string n_id;
        int p_s;
        int isrobot;
        n_id=usr->query_id()[0];
        if(employee!=n_id)
        {
                if(usr->query_job(JOBID,"beg_time"))
                { 
                this_object()->targetted_action(
                "$N��$T��������Ѿ��������ˡ�\n",usr);
                usr->resign_job(JOBID);
                return;
                }
        this_object()->targetted_action(
        "$N��$T�����㻹û�ɻ��ء�\n",usr);
        return;
        }
        all_inventory(usr);
        ob=present("fish",usr);
        if(!objectp(ob))
        {
        this_object()->targetted_action(
        "$N�ɻ�ؿ���$Tһ�ۣ������㿪ʲô��Ц��\n",usr);
        return;
        }
        if(count(ob)<2)
        {
        this_object()->targetted_action(
        "$N��$Tҡҡͷ��������������\n",usr);
        return;
        }
        else
        {
        this_object()->targetted_action(
        "$N��$T���ͷ�������ܺã����һ�Ҫ��������⿼���㡣\n",usr);
        destruct(ob);
        ob=present("fish",usr);
        destruct(ob);
        ob = present("net", usr);
        if (ob) destruct(ob);
        usr->finish_job(JOBID);
        employee="";
        starttime=0;
        ROBOT->robot_test(usr,(:award:));
        }
}        
