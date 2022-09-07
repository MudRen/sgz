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
	set_in_room_desc("һ��ũ������ĥ��ĥ���ʯĥ(shimo)��");
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
int query_status()
{
	return status;
}
int push()
{
	int m_hp;
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
	status=status+2+random(2);
	this_body()->start_busy(2,"����æ����ĥ�ء�\n");
	this_body()->simple_action( ({
	"$N������סʯĥ�ϵ�ľ����������ȥ��ֻ����֨֨�¸¡���������ʯĥת����������\n\n",
	"$Nǰ����������ֱ������һͦ�����١��غ���һ������ʯĥת���ˣ�\n\n",
	"$Nʹ��������ʯĥ����ʯĥ���붯�£�ԭ��������������Բ��%^H_YELLOW%^�ƶ�%^RESET%^�۷��飬©����ʯ���\n\n",
	"$Nʹ�����̵ľ�����ĥ��һ���ڳ�������%^H_YELLOW%^�ƶ�%^RESET%^��£������ʯĥ���ϵ�С���\n\n"}) );
	return 1;
	}
	write("%^H_YELLOW%^�ƶ�%^RESET%^�Ѿ�ĥ���ˣ���������Ҫ��%^H_YELLOW%^����%^RESET%^����������(turn shimo)��\n");
	call_out("clear_it",180);
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
int query_isfill()
{
	return isfill;
}
mixed direct_turn_obj()
{
	return 1;
}
int turn()
{
	object player;
	object room;
	object shimo,guozi;
	int stat;
	player = this_body();
	room = environment( player );
	guozi=present("guozi",room);
	shimo=present("shimo",room);
	if(this_body()->query_job("makedoufu","beg_time")==0)
	{
	this_body()->simple_action(
	"$N��Ҫɨ%^H_YELLOW%^����%^RESET%^��ȴ��֪�������ֺ��أ�������һ�ߵ�Сɨ��á�\n");
	return 1;
	}
	if(!isfill)
	{
	write("ʯĥ��ʲô��û�У������ʲôѽ��\n");
	return 1;
	}
	if( !guozi = present("guozi", room) )
	{
	write("��Ҫ��%^H_YELLOW%^����%^RESET%^ɨ������ȥ��\n");
	return 1;
	}
	if(status<31)
	{
	write("����û��ĥ�õ�%^H_YELLOW%^����%^RESET%^�����á�\n");
	return 1;
	}
	stat=guozi->query_isfill();
	if (stat==1)
	{
	write("��������Ѿ���%^H_YELLOW%^����%^RESET%^�ˡ�\n");
	return 1;
	}
      this_body()->simple_action("$N�������ʯĥ�ϵ�Сɨ�㣬�����۶�ɨ����һ�ԵĴ�����\nȻ��$N�������ﵹ��Щˮ����������ͷ��׼����%^H_YELLOW%^����%^RESET%^��\n");
	this_body()->start_busy(5,"����æ��׼����%^H_YELLOW%^����%^RESET%^�ء�\n");
	status=0;
	isfill=0;
	guozi->set_isfill();
	return 1;
}
void clear_it()
{
	if(isfill==1)
	{
	status=0;
	isfill=0;
	tell_environment(this_object(),"ʯĥ���%^H_YELLOW%^����%^RESET%^���ڷŵ�ʱ��̫�����ܳ���飬�������ˡ�\n");
	return;
	}
}
