//���� by row
#include <ansi.h>
#include <mudlib.h>
#define PCHOPWOODS PJOB+"chopwoods"
#define JOBID "chopwoods"
#define WOODS PJCHOPWOODS+"woods"
//#define S_ROOM FROOMPATH+""
inherit LIVING;
void ask_job(object usr);
void ask_pay(object usr);
void ask_food(object usr);
void setup()
{
        set_name("chu niang","����");
        set_in_room_desc("��"+YEL+"������ˮ����"+NOR+"������(chu niang)");
        set_gender(2);
        set_age(40);
        add_question("job","job");
        add_question("pay","pay");
        add_question("rumors","rumors");
        add_question("here","here");
        add_question("name","name");
        add_ask_str("job","$N��$T������λ$R����ʲô�ҿ��԰������\n");
        add_ask_str("pay","$N��$T����$R���˵��ǡ�����\n");
        add_ask_str("food","$N��$T���������λ���裬$s����ͷ��·�ˣ������ͿڳԵİ�!\n");
        add_question("food","food");
}
string long() {
	return "һλ������ֵĳ����ɫ����͸�ڣ�����ͷ��æ����ͣ��\n"+
        "Ҳ�����ܰ���һЩæ(ask chu niang about job)��\n";
}
void ask_food(object usr)
{
    int n_withbody;
    int n_sum,n_bank,n_sal;
    string p_id;
    n_withbody=usr->query_all_con_money();
    n_bank=usr->query_amt_money("bank");
    p_id=(usr->query_id())[0];
    n_sal=CHAR_D->get_char(p_id,"gold")*10000;
    n_sum=n_withbody+n_bank+n_sal;
        this_object()->targetted_action(
                "$N����ϸϸ�������´�����$Tһ����\n",usr);
    if(n_sum>5000) // 50 silver
        {
                this_object()->targetted_action(
                        "$N��$T����$m$R����������ѽ���Լ���Եĺ�����\n",usr);
                return;
        }
        if(present("shuihu",usr)&&present("wotou",usr))
        {
                this_object()->targetted_action(
                        "$N��$T���������ϲ��Ǵ��ųԵġ��ȵ��𣬻�Ҫ����\n",usr);
                return;
        }
        this_object()->targetted_action(
                "$Nͬ��ض�$T�����ֿ����ģ������ܲ��ܸ����ҵ㶫����\n",usr);
        if(!present("wotou",usr))
        {       object o=OBJ_D->clone_obj("wotou");
                o->move(usr);
                this_object()->targetted_action(
                        "$N��$Tһ����ͷ��\n",usr);
        }
        if(!present("shuihu",usr))
        {       object o=new(PFOODANDDRINK+"shuihu");
                o->move(usr);
                this_object()->targetted_action(
                        "$N��$Tһ��ˮ����\n",usr);
        }
        usr->responda("thank chu niang");
        usr->responda("touch chu niang");
        usr->responda("kiss chu niang");
        return;
}
mixed special_answer(object ob, string str)
{
        object player;
        player = this_body();
        switch(str)
        {
        case "food":
                ask_food(player);
                return;
        case "job":
                ask_job(player);
                return;
        case "pay":
                ask_pay(player);
                return;
        case "rumors":
                this_object()->targetted_action("$N̾��һ������"+
"����������²�̫ƽ������������˶�����ȥ��������\n",ob);
                return;
        case "name":
                this_object()->targetted_action("$N�ֿ���Ц����"+
"��һ�����´��ˣ���������Ҳ�ա�\n",ob);
                return;
        case "here":
                this_object()->targetted_action("$N����������ǳ�����"+
"��ô�������һ���˸ɻ���æ��������\n",ob);
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
        if (usr->query_job(JOBID,"beg_time"))
        {
        this_object()->targetted_action(
        "$N��$T������ȥ����Ļ�ɡ�\n",usr);
        return;
        }
        if(CHAR_D->get_char(n_id,"nation"))
        {
        this_object()->targetted_action(
        "$N����������$m$R����ϷŪ$s��$s�����Ͷ�$R����ȴֻ\n",usr);
        return;
        }
        n_lasttimes=usr->query_job(JOBID,"count_lasttimes");	//�û�������״̬
        m_lasttimes=JOB_D->query_job(JOBID,"count_lasttimes");
        if(n_lasttimes>m_lasttimes)
        {
        this_object()->targetted_action(
        "$N��$T���������ɵĿ�������ˣ�����Ϣ��Ϣ�ˡ�\n",usr);
        return;
        }
        usr->resign_job(JOBID);
        usr->add_job(JOBID);
        this_object()->targetted_action(
        "$N��$T�����ðɣ�������������ȱЩ���������ȥ��Щ����\n"+
        "��������Ƭ�����ӡ���������һ�ѿ��񵶣�����ҲҪ��ʮ����\n",usr);
        this_object()->targetted_action(
        "$N����$Tһ��"+YEL+"����"+NOR+"��\n",usr);
        ob=new("/sgdomain/job/chopwoods/chopper");
        ob->move(usr);
}
void award(object usr)
{
        int isrobot;
        object ob;
        isrobot=usr->query_robot();
        if(isrobot)
        {
        this_object()->simple_action(
        "$N΢΢һЦ��ԭ����ˣ��ðɡ�\n");
        this_object()->targetted_action(
        "$N��$Tһ�Ű�ԲֽǮ��\n",usr);
        usr->simple_action("$N���˵�ֱ�֣�������Ǯ�ˣ�\n");
        ob=new(PMONEY+"fmoney");
        ob->move(usr);
        }
        else
        {
        string p_id;
        p_id=usr->query_id()[0];
        CHAR_D->set_char(p_id,"reputation",
        CHAR_D->get_char(p_id,"reputation")+1);
        this_object()->simple_action("$N������������\n");
        this_object()->targetted_action("$N��$Tʮ�����ӡ�\n",usr);
        ob=new(M_SILVER);
        ob->set_m_num(10);
        ob->move(usr);
        if(random(2)) {
              ob=new("/sgdomain/obj/other/tiezi");
              ob->move(usr);
             this_object()->targetted_action(
                "$N��$T�ֵ�����λ�ɵ������ɫ���ٽ���һ�����ӡ�\n",usr);
        }
        }
}
void ask_pay(object usr)
{
        object ob;
        object chopper;
        string n_id;
        int p_s;
        int isrobot;
        n_id=usr->query_id()[0];
        if(!usr->query_job(JOBID,"beg_time")) {
           this_object()->targetted_action(
           "$N�ɻ�ؿ���$Tһ�ۣ������㿪ʲô��Ц��\n",usr);
           return;
        }
        ob=present("firewoods",usr);
        chopper=present("chopper",usr);
        if(!objectp(ob))
        {
           this_object()->targetted_action(
           "$N�ɻ�ؿ���$Tһ�ۣ������㿪ʲô��Ц��\n",usr);
           return;
        }
        if(ob->query_count()<20)
        {
            this_object()->targetted_action(
            "$N��$Tҡҡͷ������������ѽ������ȥ��Щ����\n",usr);
           return;
        }
        else
        {
            this_object()->targetted_action(
            "$N�ӹ�$T�ݹ����Ĳ��\n",usr);
            destruct(ob);
            if(chopper)
                {
                this_object()->simple_action(
                "$N����Ҫ����"+YEL+"����"+NOR+"��\n");
                destruct(chopper);
                }
        this_object()->targetted_action(
        "$N��$T���ͷ�������ܺã����һ�Ҫ��������⿼���㡣\n",usr);
        usr->finish_job(JOBID);
        ROBOT->robot_test(usr,(:award:));
        }
}
