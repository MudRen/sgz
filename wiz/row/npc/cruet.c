// by row on 12/1999 cruet.c
#include <ansi.h>
#include <mudlib.h>
inherit M_INPUT;
inherit OBJ;
inherit M_GETTABLE;

void setup() {
	set_adj("������ζ��");
	set_long("����һƿ�ö����䷽��������%^H_CYAN%^±֭%^RESET%^��\n");
	set_id("cruet", "%^H_CYAN%^±֭ƿ%^RESET%^");
	set_unit("��");
	set_in_room_desc("һ��Сƿ�ӣ�����װ��%^H_CYAN%^±֭%^RESET%^(cruet)��\n");
	set_can_give(0);
	set_is_keeping(1);
	set_can_drop(0);
	set_can_drop("�����ƿ�Ӷ��˾������ɶ����ˡ�\n");
	set_size(VERY_SMALL);
}
mixed direct_turn_obj()
{
	return 1;
}
int turn()
{
	object player;
	object room;
	object guozi,cruet;
	int stat,isfill,status;
	player = this_body();
	room = environment( player );
	cruet=present("cruet",player);
	guozi=present("guozi",room);
	if(this_body()->query_job("makedoufu","beg_time")==0)
	{
	this_body()->simple_action(
	"$Nһ��С�ģ�ƿ�����ֶ��������ڵ���ˤ���ˣ���ʱ��ζ���硣\n");
	destruct(cruet);
	return 1;
	}
	if( !guozi = present("guozi", room) )
	{
	write("�����%^H_CYAN%^±֭%^RESET%^����ʲô�ط���\n");
	return 1;
	}
	isfill=guozi->query_isfill();
	if(!isfill)
	{
	write("������ʲôҲû�У����˷���ô�õ�%^H_CYAN%^±֭%^RESET%^��\n");
	return 1;
	}
	stat=guozi->query_islu();
	if(stat==1)
	{
	write("�������%^B_WHITE%^%^H_YELLOW%^����%^RESET%^�Ѿ����%^H_CYAN%^±%^RESET%^�ˡ�\n");
	return 1;
	}
	status=guozi->query_status();
	if(status<35)
	{
	write("�������%^B_WHITE%^%^H_YELLOW%^����%^RESET%^��û����ã����ܵ�%^H_CYAN%^±%^RESET%^(wave fan)��\n");
	return 1;
	}
      this_body()->simple_action("$N�ó�Сƿ�ӣ���%^H_CYAN%^±֭%^RESET%^С������ص����˴�����е�%^B_WHITE%^%^H_YELLOW%^����%^RESET%^���±����ˣ�\n");
	guozi->set_islu();
	destruct(cruet);
	return 1;
}
