//mrope.c é���� by row
#include <sanguo.h>
#include <ansi.h>
#include <mudlib.h>
#define JOBID "weavesandals"
inherit OBJ;
inherit M_MERGEABLE;
inherit M_GETTABLE;
inherit "/std/modules/m_weaveable";
void setup()
{
merge_setup();
set_unit("��");
set_id("maocao sheng", YEL+"é����"+NOR,);
add_id("sheng","mrope");
set_in_room_desc(YEL+"é����"+NOR+"(maocao sheng)");
set_long("���Ƕ��ü���é�ݱ�ɵ����ӣ�����ȥ�൱��ʵ��");
set_gettable(1);
set_is_keeping(1);
set_size(SMALL);
set_ori_size(SMALL);
}
mixed weave()
{
	int m_hp;
	object usr;
	object ob;
	m_hp=this_body()->query_cur_hp();
	usr=this_body();
	all_inventory(usr);
	ob=present("sheng",usr);
	if(!objectp(ob))
	{
	write("������û������������\n");
	return 1;
	}
	if(this_body()->query_job(JOBID,"beg_time")==0)
	{
	this_body()->simple_action(
	"��֪������ܳ�һֻС������$N���е�"+YEL+"é����"+NOR+"���˾��ܡ�\n");
	destruct(ob);
	return 1;
	}
	if (m_hp<10)
	{write("��̫���ˣ���Ϣһ����ɡ�\n");
	return 1;
	}
	if(ob->query_count()<4)
	{
	write("������Ҫ�Ķ�"+YEL+"é����"+NOR+"����֯��\n");
	return 1;
	}
	m_hp-=5;
	this_body()->set_cur_hp(m_hp);
	usr->simple_action(
	"$N���Ķ�"+YEL+"é����"+NOR+"���Ұ��룬Ȼ�������ң��Ҵ���\n�����ػأ�һ��һ��ر�֯������\n");
	usr->start_busy(10,"����æ�ű�Ь���ء�\n");
	call_out("done",10);
}
void done(object ob)
{
	object mrope;
	int num;
	all_inventory(this_body());
	mrope=present("sheng",this_body());
	num=mrope->query_count();
	if(num==4)
	{
	write("�ɹ��ˣ���õ�һ��"+YEL+"��Ь��"+NOR+"��\n");
	ob=new(__DIR__+"mhalf");
	ob->move(this_body());
	destruct(mrope);
	return;
	}
	write("�ɹ��ˣ���õ�һ��"+YEL+"��Ь��"+NOR+"��\n");
	ob=new(__DIR__+"mhalf");
	ob->move(this_body());
	mrope->set_count(num-4);
	mrope->set_look();
	return;
}