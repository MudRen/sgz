// fan.c ������ by row
// for makedoufu

#include <ansi.h>
#include <mudlib.h>
inherit "/std/modules/m_waveable.c";
inherit OBJ;
inherit M_INPUT;

void setup()
{
	set_unit("��");
	set_id("fan","������");
	set_long("����һ������ӣ�����˩�Ÿ����ӵ���ĥ���Ĵ����ϣ���������\n��Ѭ���ǵĺۼ����Կ��ó�����������ɿ���(wave fan)��\n");
	set_in_room_desc("һ�������(fan)������˩�Ÿ����ӵ���ĥ���Ĵ����ϡ�");
}
int wave()
{
	object guozi,room;
	int status,isfill,islu;
	int m_hp;
	room = environment(this_body());
	guozi = present("guozi",room);
	if(this_body()->query_job("makedoufu","beg_time")==0)
	{
	this_body()->simple_action(
	"$Nץ������ʹ���ȣ��ɳ���Ū�����������ʲô��Ҳû�з�����\n");
	return 1;
	}
	if(!objectp(guozi))
	{
	write("����������������\n");
	return 1;
	}
	isfill=guozi->query_isfill();
	islu=guozi->query_islu();
	status=guozi->query_status();
	if(islu==1)
	{
	write("�������%^B_WHITE%^%^H_YELLOW%^����%^RESET%^�Ѿ����±�ˣ��ò��������ˡ�\n");
	return 1;
	}
	if(isfill==0)
	{
	write("�������ǿյģ���Ҳû�е��ţ�����ʲô��ѽ��\n");
	return 2;
	}
	if(status>34)
	{
	write("�������%^B_WHITE%^%^H_YELLOW%^����%^RESET%^�Ѿ�����ˣ�������Ӧ�õ�±(turn cruet)��\n");
	return 1;
	}
	if(status<35)
	{
	m_hp=this_body()->query_cur_hp();
	if (m_hp<10)
	{
	write("��̫���ˣ���Ϣһ����ɡ�\n");
	return 3;
	}
	m_hp-=5;
	this_body()->set_cur_hp(m_hp);
	guozi->do_wave();
	this_body()->start_busy(2,"����æ��ɿ���ء�\n");
	this_body()->simple_action( ({
	"$N�������ӣ�������ȥ��ֻ���������䣬�������ϴ���һ�¡�\n\n",
	"$N���������ػ������ӣ���ͷ��Ļ𽥽�����������\n\n",
	"$N��������һ�£���ͷ������ĺ��̽�$NŪ�˸�����ͷ��������\n\n",
	"$N��������ʹ�������ţ����緢�����������ˣ��ƺ��е��ܲ��ˡ�\n\n"}) );
	return 1;
	}
	write("�������%^B_WHITE%^%^H_YELLOW%^����%^RESET%^�Ѿ�����ˣ�������Ӧ�õ�±(turn cruet)��\n");
	guozi=present("guozi",room)->do_clear();
	return 1;
}
int query_clean_up()
{
	return 1;
}
