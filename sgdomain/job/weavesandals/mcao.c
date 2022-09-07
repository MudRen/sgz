//mcao.c é�� by row
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
set_id("mao cao", YEL+"é��"+NOR,);
add_id("cao");
set_in_room_desc(YEL+"é��"+NOR+"(mao cao)");
set_long("�մ�·�߰�������é�ݣ��ֳ��ֽ�ʵ��Ѱ����ũ�ҳ���������Щ������");
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
	ob=present("cao",usr);
	if(!objectp(ob))
	{
	write("������û������������\n");
	return 1;
	}
	if(this_body()->query_job(JOBID,"beg_time")==0)
	{
	this_body()->simple_action(
	"ͻȻһ���磬��$N���е�"+YEL+"é��"+NOR+"�εò�֪ȥ��\n");
	destruct(ob);
	return 1;
	}
	if (m_hp<10)
	{write("��̫���ˣ���Ϣһ����ɡ�\n");
	return 1;
	}
	if(ob->query_count()<2)
	{
	write("������Ҫ����"+YEL+"é��"+NOR+"����֯��\n");
	return 1;
	}
	m_hp-=5;
	this_body()->set_cur_hp(m_hp);
	usr->simple_action(
	"$NС�ĵؽ�����"+YEL+"é��"+NOR+"��������һ��\n");
	usr->start_busy(10,"����æ�ű�����ء�\n");
	call_out("done",10);
}
void done(object ob)
{
	object mcao;
	int num;
	all_inventory(this_body());
	mcao=present("cao",this_body());
	num=mcao->query_count();
	if(num==2)
	{
	write("�ɹ��ˣ���õ�һ��"+YEL+"é����"+NOR+"��\n");
	ob=new(__DIR__+"mrope");
	ob->move(this_body());
	destruct(mcao);
	return;
	}
	write("�ɹ��ˣ���õ�һ��"+YEL+"é����"+NOR+"��\n");
	ob=new(__DIR__+"mrope");
	ob->move(this_body());
	mcao->set_count(num-2);
	mcao->set_look();
	return;
}