//�Ϻ� by row
#include <ansi.h>
#include <mudlib.h>
#include <sanguo.h>
#define PWEAVESANDALS PJOB+"weavesandals"
#define JOBID "weavesandals"
#define STRAWS PJWEAVESANDALS+"straws"
inherit LIVING;
string employee;
int starttime;
void ask_job(object usr);
void ask_pay(object usr);
void setup()
{
	set_name("lao han","�Ϻ�");
	set_in_room_desc("��"+YEL+"һ��Ϊ�����Һ���"+NOR+"���Ϻ�(lao han)");
	set_long("һλ���θߴ��������Ϻ���������˪�����Ͽ������ƣ��ֲڵ�˫���ϱ鲼��롣\n"+
	"�����ڱ��Ь���������ܰ���һЩæ(ask lao han about job)��\n");
	set_gender(1);
	set_age(65);
	set_sg_rongmao(-1);
	employee="";
	starttime=0;
	add_question("job","job");
	add_question("pay","pay");
	add_question("rumors","rumors");
	add_question("here","here");
	add_question("name","name");
	add_question("weavesandals","weavesandals");
	add_ask_str("job","$N��$T������λ�ϲ�����ʲô�ҿ��԰������\n");
	add_ask_str("pay","$N��$T����$R���˵��ǡ�����\n");
	add_ask_str("weavesandals","$N��$T�����ϲ������Ь�׵�����ô��ѽ��\n");
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
	case "rumors":
		this_object()->targetted_action("$N�૵���"+
"�Ϻ����㲻���壬�������ϵ����ξͲ�̫����ˡ�\n",ob);
		return;
	case "name":
		this_object()->targetted_action("$N˫Ŀ������һ����â��"+
"�������ҵ����֣�������û������������\n",ob);
		return;
	case "here":
		this_object()->targetted_action("$N�����˴����ǻ���С�壬"+
"������������Ļ���Ϊ���֡�\n",ob);
		return;
	case "weavesandals":
		this_object()->targetted_action("$N΢΢һЦ���������������ʶ����ˣ�"+
"�Ϻ��ұ��Ь���˼�ʮ���ˣ��������˵���������е������ء�\n"+
"����ϸ���ţ��Ȱ�һЩé��(pull straws)��\n"+
"            �ٽ�����é�ݴ������(weave mao cao)��\n"+
"            Ȼ���Ķ�é�������Ь��(weave maocao sheng)��\n"+
"            �������Ь��ƴ�����͵���(weave caoxie zhang)��\n"+
"�տ�ʼ��ʱ����ܻ�Ƚ����裬�������ͺ�����\n",ob);
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
	this_object()->targetted_action(
	"$N��$T������ȥ����Ļ�ɡ�\n",usr);
	return;
	}
	if(employee!="")
	{
	object e;
	e=find_body(employee);
	if(objectp(e))
	{
		if((time()-starttime)<600)
		{
		this_object()->targetted_action(
		"$N��$T��������ûʲô�ɸɵģ�����������ɡ�\n",usr);
		return;
		}
	}
	}
	if(CHAR_D->get_char(n_id,"nation"))
	{
	this_object()->targetted_action(
	"$N�ִٵ���$m$R����ϷŪ$s��$s������$R��æ��\n",usr);
	return;
	}
	n_lasttimes=usr->query_job(JOBID,"count_lasttimes");
	m_lasttimes=JOB_D->get_job(JOBID,"count_lasttimes");
	m_lasttimes=10;
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
	"$N��$T�����ðɣ������ﻹȱһֻЬ�ף��������ľͰ��Ϻ��Ҹ�æ��\n"+
	"����·�ߵ�é�ݱ࣬С�ı���ָ����ˡ�\n"+
	"�����ʲô�����ľ����Һ���(ask lao han about weavesandals)��\n",usr);
	return;
}
void award(object usr)
{
	int isrobot;
	object ob;
	isrobot=usr->query_robot();
	if(isrobot)
	{
	this_object()->simple_action(
	"$N��һ�������ţ�ԭ����ˡ�\n");
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
	this_object()->targetted_action("$N��$T��ʮ�����ӡ�\n",usr);
	ob=new(M_SILVER);
	ob->set_m_num(20);
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
		"$N��$T�����Ѿ��������Ҹɻ��ˡ�\n",usr);
		usr->resign_job(JOBID);
		return;
		}
	this_object()->targetted_action(
	"$N��$T�����㻹û�ɻ��ء�\n",usr);
	return;
	}
	all_inventory(usr);
	ob=present("di",usr);
	if(!objectp(ob))
	{
	this_object()->targetted_action(
	"$N�ɻ�ؿ���$Tһ�ۣ������㿪ʲô��Ц��\n",usr);
	return;
	}
	if(ob->query_count()<1)
	{
	this_object()->targetted_action(
	"$N��$Tҡҡͷ�����㻹û����ɡ�\n",usr);
	return;
	}
	else
	{
	this_object()->targetted_action(
	"$N�ӹ�$T�ݹ���"+YEL+"��Ь��"+NOR+"��\n",usr);
	destruct(ob);
	this_object()->targetted_action(
	"$N��$T���ͷ�������ܺã����һ�Ҫ��������⿼���㡣\n",usr);
	usr->finish_job(JOBID);
	employee="";
	starttime=0;
	ROBOT->robot_test(usr,(:award:));
	}
}