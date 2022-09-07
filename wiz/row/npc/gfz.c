//�ط��� by row
#include <ansi.h>
#include <mudlib.h>
#define PMAKEDOUFU PJOB+"makedoufu"
#define JOBID "makedoufu"
#define MUTONG PJMAKEDOUFU+"mutong"
#define S_ROOM "/a/huayin/vmill"
inherit LIVING;

object room;
object mutong;
void ask_soybean(object usr);
void ask_job(object usr);
void ask_pay(object usr);
void ask_meat(object usr);
void ask_cruet(object usr);
void setup()
{
	set_name("guan fuzi","�ط���");
	add_id("guan");
	add_id("fuzi");
	set_in_room_desc("\n��%^B_WHITE%^"+HIG+"��䶹��"+NOR+"���ط���(guan fuzi)");
	set_gender(1);
	set_age(45);
	add_question("job","job");
	add_question("pay","pay");
	add_question("makedoufu","makedoufu");
	add_question("rumors","rumors");
	add_question("here","here");
	add_question("name","name");
	add_question("soybean","soybean");
	add_question("cruet","cruet");
	add_ask_str("soybean","$N��$T������ʦ�������ɻƶ������ˣ��ܲ����ٸ������\n");
	add_ask_str("cruet","$N��$T������ʦ��������±�����ˣ��ܲ����ٸ������\n");
	add_ask_str("makedoufu","$N��$T������ʦ�����������������������ôһ���£�\n");
	add_ask_str("job","$N��$T������λ$R����ʲô�ҿ��԰�æ����\n");
	add_ask_str("pay","$N��$Tһ���֣�����$R�����������Ǯ�����⡣����\n");
}
string long() {
	return "һλ��ĸߴ�ĵ����꺺�ӣ������鲼�̹ӣ��߸ߵؾ��ſ��\n"+
	       "�ӣ���̤һ˫��Ь������ͨ�Ĵ������ڲ�ס��ü���һ�ɱ���\n"+
	       "��Ӣ�����ټ��������Ʈ�ݵ����ף�����ع�����һ�㣬�ѹ�\n"+
	       "һЩ����������ҪŪ���ط���ƽʱ��ĥ����ĥ������������\n"+
		 "һ����Զ������(ask zhang about job)��\n";
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
	case "soybean":
		ask_soybean(player);
		return;
	case "cruet":
		ask_cruet(player);
		return;
	  case "makedoufu":
                this_object()->simple_action("$N°��°��µĳ��ף�����������ϸ�ˡ�\n"+
			"�Ƚ��ƶ��ŵ�ʯĥ��ĥ����ϸ(turn soy bean��push shimo)��\n"+
			"�ٽ����۷ŵ����������(turn shimo��wave fan)��\n"+
			"Ȼ����������һ��±(turn cruet)��\n"+
			"��󽫹�����Ķ�������ľͰ��ȴ�Ϳ�����(turn guozi)��\n");
		    return;
        case "rumors":
                this_object()->simple_action("$N̾�˿�����"+
"��ĳ�㲻�����Ѿã�ȫ��֪����������Σ�������������\n");
                return;
        case "name":
                this_object()->simple_action("$N��΢΢һ�죺"+
"�����������չأ���������Ҳ�ա�\n");
                return;
        case "here":
                this_object()->targetted_action("$NЦ����"+
"�˵����ǻ���Ψһ��ĥ������ĳƽʱ���ڴ���Щ������\n",ob);
                return;
        default:
                return;
        }
}
void ask_job(object usr)
{
        string n_id;
        int n_lasttimes,m_lasttimes;
        object ob,oc;
        n_id=usr->query_id()[0];
        if (usr->query_job(JOBID,"beg_time"))
        {
        this_object()->targetted_action(
        "$N��$T��������Ѿ��������ˣ����ȥ���ɡ�\n",usr);
        return;
        }
        if(CHAR_D->get_char(n_id,"nation"))
        {
        this_object()->targetted_action(
        "$N��һ����$RĪ������ϷŪ���ң�$T��Ϊ�߹٣���Ϊ���Ұ��ձ�����ȴΪ���Ĵ��й䣿\n",usr);
        return;
        }
        n_lasttimes=usr->query_job(JOBID,"count_lasttimes");
        m_lasttimes=JOB_D->query_job(JOBID,"count_lasttimes");
        if(n_lasttimes>m_lasttimes)
        {
        this_object()->targetted_action(
        "$N��$T�����ţ���������Ķ��������ˣ�����ЪϢȥ�ˡ�\n",usr);
        return;
        }
        usr->resign_job(JOBID);
        usr->add_job(JOBID);
        this_object()->targetted_action(
        "$N��$T���ͷ���ã���һ���ƶ��ȸ��㣬��͸���ĳ��һͰ����������\n"+
        "�����������ˣ������ǲ�������ô�������ʹ�ĳ��(ask guan about makedoufu)��\n"+
	"��һ�㻹��Ҫ�ƶ���±�������ĳҪ��(ask guan about soybean��ask guan about cruet)��\n",usr);
        this_object()->targetted_action(
        "$N����$Tһ��"+HIY+"�ƶ�"+NOR+"��һСƿ%^H_CYAN%^±֭%^RESET%^��ָ��ָ���ϵ�ʯĥ(shimo)����ͷ\n�ϵĴ����(guozi)�����Ϲ��ŵĴ�����(fan)��һ�Ե�ľͰ(mutong)��\n",usr);
	usr->add_job(JOBID);
	usr->set_job(JOBID,"status","beg");
	ob=new("/sgdomain/job/makedoufu/soybean");
	oc=new("/sgdomain/job/makedoufu/cruet");
	ob->move(usr);
	oc->move(usr);
}
void award(object usr)
{
        int isrobot;
        object ob;
        isrobot=usr->query_robot();
        if(isrobot)
        {
        this_object()->simple_action(
        "$N������ü��ԭ����ˡ�\n");
        this_object()->targetted_action(
        "$N��$Tһ�Ű�ԲֽǮ��\n",usr);
        usr->simple_action("$N���˵�����������������Ǯ�ˣ�\n");
        ob=new(PMONEY+"fmoney");
        ob->move(usr);
        }
        else
        {
        string p_id;
        p_id=usr->query_id()[0];
        CHAR_D->set_char(p_id,"reputation",
        CHAR_D->get_char(p_id,"reputation")+1);
        this_object()->simple_action("$N΢΢һЦ���ܺá�\n");
        this_object()->targetted_action("$N��$T��ʮ�����ӡ�\n",usr);
        ob=new(M_SILVER);
        ob->set_m_num(30);
        ob->move(usr);
        }
}
void ask_pay(object usr)
{
        string n_id;
        n_id=usr->query_id()[0];
        if(!usr->query_job(JOBID,"beg_time")) {
           this_object()->targetted_action(
           "$Nһ���ɻ󣬶�$T������ĳû��$R�ɹ���ɣ�\n",usr);
           return;
        }
	room=load_object(S_ROOM);
	mutong=present("mutong", room );
	if(mutong->query_status()!=1)
	{
	this_object()->targetted_action(
	"$N��$T���������㻹û�����ء�\n",usr);
	return;
	}
	this_object()->targetted_action(
	"$N�鿴��һ��ľͰ������Ķ�$T�������ĺã�\n$N�߸����˵ؽ�ľͰ���%^B_WHITE%^%^H_GREEN%^��䶹��%^RESET%^����������\n",usr);
	mutong->set_status();
	mutong->empty_it();
	this_object()->targetted_action(
	"$N��$T������ĳ��Ҫ��������⡣\n",usr);
	usr->finish_job(JOBID);
	ROBOT->robot_test(usr,(:award:));
}
void ask_soybean(object usr)
{
	object ob,soybean,shimo,guozi,mutong;
	int isfill1,isfill2,isfill3;
	object room;
	room = environment(this_body());
	guozi=present("guozi",room);
	shimo=present("shimo",room);
	mutong=present("mutong",room);
	if(!usr->query_job(JOBID,"beg_time"))
	{
	this_object()->targetted_action(
	"$Nһ���ɻ󣺹�ĳ�ƺ�û��$m$R�ɹ���ɣ���Ӻ�˵��\n",usr);
	return;
	}
	if(!objectp(guozi)||!objectp(shimo)||!objectp(mutong))
	{
	this_object()->targetted_action(
	"$N��$Tһҡͷ��$R����˰ɣ�����������ѽ��\n",usr);
	return;
	}
	soybean=present("soybean",usr);
	if(objectp(soybean))
	{
	this_object()->targetted_action(
	"$N��$TЦ�����㲻���лƶ���Ϊ�������ĳҪ�ˣ�\n",usr);
	return;
	}
	isfill1=shimo->query_isfill();
	isfill2=guozi->query_isfill();
	isfill3=mutong->query_isfill();
	if(isfill1==1||isfill2==1||isfill3==1)
	{
	this_object()->targetted_actioin(
	"$N��$TЦ����$R�����ò���ѽ���Ѿ�����Ҫ�ƶ��ˡ�\n",usr);
	return;
	}
	this_object()->targetted_action(
	"$N��$T���ͷ���ðɣ���ĳ���ٸ���Щ�ƶ�����ؿɱ����˷��ˡ�\n"+
	"$N�ݸ�$Tһ��%^H_YELLOW%^�ƶ�%^RESET%^��\n",usr);
	ob=new("/sgdomain/job/makedoufu/soybean");
	ob->move(usr);
}
void ask_cruet(object usr)
{
	object ob,cruet,shimo,guozi,mutong;
	int islu;
	object room;
	room = environment(this_body());
	guozi=present("guozi",room);
	shimo=present("shimo",room);
	mutong=present("mutong",room);
	if(!usr->query_job(JOBID,"beg_time"))
	{
	this_object()->targetted_action(
	"$Nһ���ɻ󣺹�ĳ�ƺ�û��$m$R�ɹ���ɣ���Ӻ�˵��\n",usr);
	return;
	}
	if(!objectp(guozi)||!objectp(shimo)||!objectp(mutong))
	{
	this_object()->targetted_action(
	"$N��$Tһҡͷ��$R����˰ɣ�����������ѽ��\n",usr);
	return;
	}
	cruet=present("cruet",usr);
	if(objectp(cruet))
	{
	this_object()->targetted_action(
	"$N��$TЦ�����㲻����±��Ϊ�������ĳҪ�ˣ�\n",usr);
	return;
	}
	islu=guozi->query_islu();
	if(islu==1)
	{
	this_object()->targetted_action(
	"$N��$TЦ����$R�����ò���ѽ���Ѿ�����Ҫ±�ˡ�\n",usr);
	return;
	}
	this_object()->targetted_action(
	"$N��$T���ͷ���ðɣ���ĳ���ٸ���Щ±����ؿɱ����˷��ˡ�\n"+
	"$N�ݸ�$TһСƿ%^H_CYAN%^±֭%^RESET%^��\n",usr);
	ob=new("/sgdomain/job/makedoufu/cruet");
	ob->move(usr);
}
