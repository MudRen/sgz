// shimo.c ʯĥ re-design by row
// for makedoufu

#include <ansi.h>
#include <mudlib.h>
inherit "/std/modules/m_pushable.c";
inherit OBJ;
inherit M_INPUT;

string *desc = ({"һ��ʯĥ��ƽ��ũ�Ҿ�������ĥ��(push shimo)������Կ�������װ��Щ�ƶ���\n",
"ʯĥ��Ļƶ�������֨֨�¸¡����������Ѿ���ĥ��������(push shimo)��\n",
"�ƶ���ʯĥ���ȵ�ת���£���ɳɳ���ر�ĥ����ϸ��(push shimo)��\n",
"һ��ʯĥ��ƽ��ũ�Ҿ�������ĥ��(push shimo)��\n"});

int status; // 0-30
int push;
int isfill; //put soy bean in shimo
string short();

void setup()
{
	set_unit("��");
	set_id("shimo","ʯĥ", "miller");
//	set_long("һ��ũ������ĥ��ĥ���ʯĥ������ȥ��������ʯĥûʲô��ͬ��\n
//��Ҫĥ���ʱ�ת���������裩���Ϳ����ˡ�\n\n");
	set_in_room_desc("һ��ũ������ĥ��ĥ���ʯĥ(shimo)��\n");
	status=0;
	push=0;
	isfill=0;
}
string long()
{
	if(isfill==1&&status<11)
	return desc[0];
	if(isfill==1&&status<21)
	return desc[1];
	if(isfill==1&&status<40)
	return desc[2];
	return desc[3];
}
int query_isfill()
{
	return isfill;
}
int push()
{
	int m_hp;
	int x;
	x=this_object()->query_isfill();
	printf("the isfill para is "+x+"\n");
	if(this_body()->query_job("makedoufu","beg_time")==0)
	{
	this_body()->simple_action(
	"$N��ס������ʹ����ʯĥ��ȥ������һ����ˤ��һ������ſ��\n");
	return 1;
	}
	if(isfill!=1)
	{
	write("ʯĥ��ʲô��û�У�����ֻ�ǰ׷�������\n");
	return 2;
	}
	if (status<31)
	{
	m_hp=this_body()->query_cur_hp();
	if (m_hp<10)
	{
	write("��̫���ˣ���Ϣһ����ɡ�\n");
	return 3;
	}
	m_hp-=5;
	this_body()->set_cur_hp(m_hp);
	status=status+random(2);
	this_body()->start_busy(2,"����æ����ĥ�ء�\n");
	this_body()->simple_action( ({
	"$N������סʯĥ�ϵ�ľ����������ȥ��ֻ����֨֨�¸¡���������ʯĥת����������\n\n",
	"$Nǰ����������ֱ������һͦ�����١��غ���һ������ʯĥת���ˣ�\n\n",
	"$Nʹ��������ʯĥ����ʯĥ���붯�£�ԭ��������������Բ�Ļƶ��۷��飬©����ʯ���\n\n",
	"$Nʹ�����̵ľ�����ĥ��һ���ڳ��������ƶ���£������ʯĥ���ϵ�С���\n\n"}) );
	}
	return 4;
}
int is_pushable()
{
	return 1;
}
int query_clean_up()
{
	return 1;
}
void set_isfill()
{
	isfill=1;
}
