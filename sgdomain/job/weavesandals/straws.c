// straws by row
// this is used for the job of ���Ь��
#include <mudlib.h>
#include <ansi.h>
#define JOBID "weavesandals"
inherit OBJ;
inherit M_INPUT;

string *desc = ({"�����Ӱ˵�"+YEL+"é�ݴ�"+NOR+"��\n"+
"�紵�ݶ����������ৡ�����������������Ű�һ������(pull straws)��\n",
"����ȥ�ߵͲ�ƽ�������˰ι�(pull straws)��\n",
"������ȥ�����ֻʣ�¸�����(pull straws)��\n",});

private int status;
private int pulled;
void setup()
{
	set_id("straws", YEL+"é�ݴ�"+NOR);
	set_in_room_desc("·�߷��Ƶ�"+YEL+"é�ݴ�"+NOR+"(straws)��");
	status=0;
	pulled=0;
	call_out("grow", 15);
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
	call_out("grow",15);
	pulled=pulled-1;
	if(pulled<0)
	pulled=0;
	if(pulled)
	return;
	status=status-2;
	if(status<0)
	status=0;
}
int pull()
{
	object ob;
	if(this_body()->query_job(JOBID,"beg_time")==0)
	{
	int m_hp;
	m_hp=this_body()->query_cur_hp();
	if (m_hp<10)
	{write("��ʡʡ�ɡ�\n");
	return 1;
	}
	m_hp-=15;
	this_body()->set_cur_hp(m_hp);
	this_body()->simple_action(
	"$Nץס����é��һ������������Ʊ����˼������ӡ�\n");
	return 1;
	}
	if (status<41)
	{
	int m_hp;
	m_hp=this_body()->query_cur_hp();
	if (m_hp<10)
	{write("��̫���ˣ���Ϣһ����ɡ�\n");
	return 1;
	}
	m_hp-=15;
	this_body()->set_cur_hp(m_hp);
	status=status+random(5);
	this_body()->simple_action(
	"$N������ק������ۣ����㳶��һ�ѷ��Ƶ�"+YEL+"é��"+NOR+"��\n",);
	ob=new(__DIR__"mcao");
	ob->move(this_body());
	return 1;
	}
	else
	write("é�ݱ��ι��ˡ�\n");
	return 1;
}