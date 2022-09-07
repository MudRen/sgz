// woods by row
// this is used for the job of ����
#include <mudlib.h>
#include <ansi.h>
#define JOBID "chopwoods"
inherit OBJ;
inherit M_CHOPPABLE;
inherit M_INPUT;

string *desc = ({"һƬ"+GRN+"����"+NOR+"�������м��������£���ȫҰ��Ұ����\n"+
"������ȡ��ؾ�����֦Ҷ��ï��(chop woods with kanchai dao)\n",
"�������������Ե�����ӡ�ǣ�һ�������ڴ˿������(chop woods with kanchai dao)\n",
"������ȥ�����϶��ǹ�ͺͺ�ģ��ܵ�����֦Ҷ�Ѿ������ˡ�(chop woods with kanchai dao)\n",});

int status;
int chopped;

void setup()
{
	set_id("woods", "һƬ"+GRN+"����"+NOR+"","shu lin");
	set_in_room_desc("һƬ"+GRN+"����"+NOR+"(woods)");
	status=0;
	chopped=0;
	call_out("grow", 10);
}
string long()
{
	if(status<11)
	return desc[0];
	if(status<21)
	return desc[1];
	if(status<41)
	return desc[2];
}
void grow()
{
	call_out("grow",10);
	chopped=chopped-1;
	if(chopped<0)
	chopped=0;
	if(chopped)
	return;
	status=status-2;
	if(status<0)
	status=0;
}
void chop(object o)
{
	object chopper;
	object ob;
	if(this_body()->query_job(JOBID,"beg_time")==0)
	{
	all_inventory(this_body());
	chopper=present("chopper",this_body());
	this_body()->simple_action(
	"$Nһ������辿�ȥ����"+YEL+"����"+NOR+"��ž����һ�����ˡ�\n");
	destruct(chopper);
	return;
	}
	if (status<41)
	{
	int m_hp;
	m_hp=this_body()->query_cur_hp();
	if (m_hp<10)
	{write("��̫���ˣ���Ϣһ����ɡ�\n");
	return;
        }
        m_hp-=5;
        this_body()->set_cur_hp(m_hp);
	status=status+random(5);
	this_body()->simple_action( ({"$N����"+YEL+"����"+NOR+"�����꡹�����꡹�ؿ���\n",
	"$Nһ�����񣬱����µ���֦����������\n",
	"$N�������ͣ�һͷײ�������ϣ����˸�������\n",
	"$N��������������׼����Ѿ����һ�£�ֻ�������꡹һ����������䡣\n"}) );
        ob=new(__DIR__"firewoods");
        ob->move(this_body());
	}
	else
	write("��Ƭ���ֹ�ͺͺ�ģ��Ѿ�����������ˡ�\n");
}
