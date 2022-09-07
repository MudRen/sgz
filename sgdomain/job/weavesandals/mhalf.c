//mhalf.c ��Ь�� by row
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
set_id("caoxie zhang", YEL+"��Ь��"+NOR,);
add_id("zhang");
set_in_room_desc(YEL+"��Ь��"+NOR+"(caoxie zhang)");
set_long("��ֿ���ȥ��һ���ò�����ɵ���Բ�ε�ƬƬ��\n������������ƴ��һ�𣬾��е����˽ŵ׵���״��");
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
	ob=present("zhang",usr);
	if(!objectp(ob))
	{
	write("������û������������\n");
	return 1;
	}
	if(this_body()->query_job(JOBID,"beg_time")==0)
	{
	this_body()->simple_action(
	"$Nһ����æ���ң����е�"+YEL+"��Ь��"+NOR+"��ɢ�˼��ˡ�\n");
	destruct(ob);
	return 1;
	}
	if (m_hp<10)
	{write("��̫���ˣ���Ϣһ����ɡ�\n");
	return 1;
	}
	if(ob->query_count()<2)
	{
	write("������Ҫ����"+YEL+"��Ь��"+NOR+"����ƴ��������\n");
	return 1;
	}
	m_hp-=10;
	this_body()->set_cur_hp(m_hp);
	usr->simple_action(
	"$N����ϸ������"+YEL+"��Ь��"+NOR+"ǰ��ƴ��������\n");
	usr->start_busy(10,"����æ��ƴЬ���ء�\n");
	call_out("done",10);
}
void done(object ob)
{
	object mhalf;
	int num;
	all_inventory(this_body());
	mhalf=present("zhang",this_body());
	num=mhalf->query_count();
	if(num==2)
	{
	write("�ɹ��ˣ���õ�һֻ"+YEL+"��Ь��"+NOR+"��\n");
	ob=new(__DIR__+"strawsandals");
	ob->move(this_body());
	destruct(mhalf);
	return;
	}
	write("�ɹ��ˣ���õ�һֻ"+YEL+"��Ь��"+NOR+"��\n");
	ob=new(__DIR__+"strawsandals");
	ob->move(this_body());
	mhalf->set_count(num-2);
	mhalf->set_look();
	return;
}