// guozi.c ����� by row
// for makedoufu

#include <ansi.h>
#include <mudlib.h>
inherit OBJ;
inherit M_INPUT;

int query_status();
void set_islu();
int query_islu();
void do_wave();
int query_clean_up();
void set_isfill();
int query_isfill();
mixed direct_turn_obj();
int turn();
void do_clear();
void clear_it();

string *desc = ({
"һ�ڴ���ӣ����������ŵ������ζ�����㿴������ʢ������һ������ˮ\n��%^H_YELLOW%^����%^RESET%^�����ҹ����Ѿ�������С���ƺ����¾㱸(wave fan)��\n",
"������ˮ΢΢��ð��ЩС���ݣ��������Ѻ��ͷų���˿˿����(wave fan)��\n",
"������ˮ��Խ��Խ�࣬���ȿֺ��ӿ��ˮ�棬%^H_YELLOW%^����%^RESET%^Ҳ�����Ż���ط�����(wave fan)��\n",
"������ˮ�Ѿ���ȫ�����ˣ�һƬ�װ׵������������޷�����%^B_WHITE%^%^H_YELLOW%^����%^RESET%^��\n�����Ѿ���ȫ�����(wave fan)��\n",
"һ�ڴ���ӣ���������ǳ��ɫ��ŨŨ�����%^B_WHITE%^%^H_YELLOW%^����%^RESET%^����ð��������(turn cruet)��\n",
"һ�ڴ���ӣ���������ǳ��ɫ��ŨŨ�����%^B_WHITE%^%^H_YELLOW%^����%^RESET%^����ϸ�������Է���\n����Ʈ��һ��%^H_CYAN%^±֭%^RESET%^(turn guozi)��\n",
"һ�ڴ���ӣ��ǹط���������%^B_WHITE%^%^H_YELLOW%^����%^RESET%^�����ߣ����µ���ͷ����Ų��\n",});
int status; // 0-30
int push;
int isfill; // there is soy powder in
int islu;
string short();

void setup()
{
	set_unit("��");
	set_id("guozi","�����");
	set_in_room_desc("һ�ڴ��(guozi)��������ͷ�ϣ�����������Щ������");
	status=0;
	isfill=0;
	islu=0;
}
string long()
{
	if(islu==1)
	return desc[5];
	if(isfill==1&&status==0)
	return desc[0];
	if(isfill==1&&status<10)
	return desc[1];
	if(isfill==1&&status<20)
	return desc[2];
	if(isfill==1&&status<35)
	return desc[3];
	if(isfill==1&&status<40)
	return desc[4];
	return desc[6];
}
int query_status()
{
	return status;
}
void set_islu()
{
	islu=1;
}
int query_islu()
{
	return islu;
}
void do_wave()
{
	status=status+2+random(2);
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
	object mutong,guozi;
	int stat;
	player = this_body();
	room = environment( player );
	guozi=present("guozi",room);
	mutong=present("mutong",room);
	if(this_body()->query_job("makedoufu","beg_time")==0)
	{
	this_body()->simple_action(
	"$N���Ź���ֱգ���۾�����֪����ô��źá�\n");
	return 1;
	}
	if(!isfill)
	{
	write("������ʲô��û�У���Ҫ��ʲô��\n");
	return 1;
	}
	if(status<35)
	{
	write("%^B_WHITE%^%^H_YELLOW%^����%^RESET%^��û������ء�\n");
	return 1;
	}
	if( !mutong = present("mutong", room) )
	{
	write("��Ҫ��%^B_WHITE%^%^H_YELLOW%^����%^RESET%^��������ȥ��\n");
	return 1;
	}
	stat=mutong->query_isfill();
	if (stat==1)
	{
	write("ľͰ���Ѿ�װ��%^B_WHITE%^%^H_YELLOW%^����%^RESET%^�ˡ�\n");
	return 1;
	}
      this_body()->simple_action("$N�Ȱ���ͷ��Ļ�ŪϨ��Ȼ�������̧�����ӣ��������%^B_WHITE%^%^H_YELLOW%^����%^RESET%^һ����ȫ������һ�ԵĴ�ľͰ�\n");
	this_body()->start_busy(5,"����æ�ŵ�%^B_WHITE%^%^H_YELLOW%^����%^RESET%^�ء�\n");
	status=0;
	isfill=0;
	islu=0;
	mutong->set_isfill();
	mutong->do_cold();
	return 1;
}
void do_clear()
{
	call_out("clear_it",180);
	return;
}
void clear_it()
{
	if(islu==1)
	{
	status=0;
	isfill=0;
	islu=0;
	tell_environment(this_object(),"��������±��%^B_WHITE%^%^H_YELLOW%^����%^RESET%^���ڷŵ�ʱ��̫���������ˣ�ֻ�ܵ����ˡ�\n");
	return;
	}
	if(isfill==1)
	{
	status=0;
	isfill=0;
	islu=0;
	tell_environment(this_object(),"�������%^B_WHITE%^%^H_YELLOW%^����%^RESET%^���ڷŵ�ʱ��̫��������˵�±��ʱ����ֻ�ܵ����ˡ�\n");
	return;
	}
}
