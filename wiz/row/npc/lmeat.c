// lmeat by row
// this is used for the job of ����
#include <mudlib.h>
#include <ansi.h>
#define JOBID "choppork"
inherit OBJ;
inherit M_CHOPPABLE;
inherit M_INPUT;
inherit M_GETTABLE;

string *desc = ({"����һ����Ϻõ�%^B_WHITE%^%^H_RED%^����%^RESET%^���ʱ���񣬹�ͷ�����޸ɾ��ˡ�\n"+
"����һ������û����Ҫ�ģ���Ҫ�õ��ӹ��ɴ�С���ȵ�%^B_WHITE%^%^H_RED%^������%^RESET%^����\n(chop meat with tigudao)\n",
"����һ���Ϻõ�%^B_WHITE%^%^H_RED%^����%^RESET%^���ʱ���񣬹�ͷ�����޸ɾ��ˡ�\n���Կ��ó�����ⱻ���й���\n(chop meat with tigudao)\n",
"����һ���Ϻõ�%^B_WHITE%^%^H_RED%^����%^RESET%^���ʱ���񣬹�ͷ�����޸ɾ��ˡ�\n��������������ô��൶���Ѿ�ûʣ�¶����ˡ�\n(chop meat with tigudao)\n"});

int status;

void setup()
{
	set_id("meat", "%^B_WHITE%^%^H_RED%^������%^RESET%^","da zhulei");
	set_in_room_desc("һ��%^B_WHITE%^%^H_RED%^������%^RESET%^(large meat)");
	status=30;
	set_unit("��");
	set_size(SMALL);
	set_can_drop(0);
	set_can_drop("���ⶪ�˾��ò�����Ǯ�ˡ�\n");
	set_can_give(0);
}
string long()
{
	if(status<11)
	return desc[2];
	if(status<21)
	return desc[1];
	if(status<31)
	return desc[0];
}
void chop(object o)
{
	object tigudao,lmeat;
	object ob;
	int m_hp;
	if(this_body()->query_job(JOBID,"beg_time")==0)
	{
	all_inventory(this_body());
	tigudao=present("tigudao",this_body());
	lmeat=present("meat",this_body());
	this_body()->simple_action(
	"$N������%^H_CYAN%^�޹ǵ�%^RESET%^һ����ȥ�����ǲ��ɶ���һ��Ӳ��ͷ�ϣ�����ž����һ�����ˡ�\n"+
	"�������������������ֽ�$N���е�����˹�ȥ���������������ʲô����������ɲ�����������ġ�\n");
	destruct(tigudao);
	destruct(lmeat);
	return;
	}
	if (status<31)
	{
	if (status==0)
	{
	lmeat=present("meat",this_body());
	this_body()->simple_action(
	"$N����%^H_CYAN%^�޹ǵ�%^RESET%^�����м��飬ȴ�������Ѿ������ˡ�\n");
	destruct(lmeat);
	return;
	}
	m_hp=this_body()->query_cur_hp();
	if (m_hp<10)
	{
	write("��̫���ˣ���Ϣһ����ɡ�\n");
	return;
	}
	m_hp-=5;
	this_body()->set_cur_hp(m_hp);
	status=status-1;
	switch(random(7))
	{
	case 0:
	this_body()->start_busy(3,"����æ�������ء�\n");
	this_body()->simple_action("$N����%^H_CYAN%^�޹ǵ�%^RESET%^��׼%^B_WHITE%^%^H_RED%^������%^RESET%^"+
	"�͵ؾ���һ�£���û�뵽����ʹ���ˣ�����һ��񱡲�һ����Ƭ����\n�����������϶�����Ҫ�����ӵ����ŵģ����˰ɡ�\n\n");
	break;
	case 5:
	this_body()->start_busy(3,"����æ�������ء�\n");
	this_body()->simple_action("$N�ٵ�������ȥ�����ˣ�������Լ�����ָ��$Nһ�ţ���С�İѸ����µ��������ڵ��ϵĳ�ˮ���\n"+
	"���ˣ�������������������ã����ǲ���Ҫ��������ģ��������˰ɡ�\n\n");
	break;
	default:
	this_body()->start_busy(3,"����æ�������ء�\n");
	this_body()->simple_action( ({"$N�ò����������ַ�����%^H_CYAN%^�޹ǵ�%^RESET%^��С������ش�%^B_WHITE%^%^H_RED%^������%^RESET%^������һ����Ƭ\n"+
	"�ţ��񱡾��ȣ��������У���һ��ϸ��%^B_WHITE%^%^H_RED%^������%^RESET%^��\n\n",
	"$N���ֽ�%^B_WHITE%^%^H_RED%^������%^RESET%^���ڰ�̨�ϣ�����߬��%^H_CYAN%^�޹ǵ�%^RESET%^������������һƬ������\n"+
	"�ţ��񱡾��ȣ��������У���һ��ϸ��%^B_WHITE%^%^H_RED%^������%^RESET%^��\n\n",
	"$Nһ�߿��������������ƣ�һ��ѧ�Ŵ�%^B_WHITE%^%^H_RED%^������%^RESET%^������һƬ��������ͦ����ôһ���¡�\n"+
	"�ţ��񱡾��ȣ��������У���һ��ϸ��%^B_WHITE%^%^H_RED%^������%^RESET%^��\n\n"}) );
	ob=new(__DIR__"pork");
	ob->move(this_body());
	break;
	}
	}
}