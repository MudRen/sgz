// by fire on Jan 9 1998 barrel.c
#include <ansi.h>
#include <mudlib.h>
inherit M_INPUT;
inherit OBJ;
inherit M_GETTABLE;

void setup() {
	set_adj("����������");
	set_long("����һ����ѡ��%^H_YELLOW%^�ƶ�%^RESET%^����������������ò������ˡ�\n");
	set_id("soy bean", "%^H_YELLOW%^�ƶ�%^RESET%^","soybean");
	set_unit("��");
	set_in_room_desc("һ������������%^H_YELLOW%^�ƶ�%^RESET%^(soy bean)��\n");
	set_can_give(0);
	set_is_keeping(1);
	set_can_drop(0);
	set_can_drop("�ѻƶ����˾��ò�����Ǯ�ˡ�\n");
	set_size(SMALL);
}
mixed direct_turn_obj()
{
	return 1;
}
int turn()
{
	object player;
	object room;
	object shimo,soy;
	int stat;
	player = this_body();
	room = environment( player );
	soy=present("soy bean",player);
	shimo=present("shimo",room);
	if(this_body()->query_job("makedoufu","beg_time")==0)
	{
	this_body()->simple_action(
	"$Nһ����æ���ң���%^H_YELLOW%^�ƶ�%^RESET%^����һ�ء�\n");
	destruct(soy);
	return 1;
	}
	if( !shimo = present("shimo", room) )
	{
	write("�����%^H_YELLOW%^�ƶ�%^RESET%^����ʲô�ط���\n");
	return 1;
	}
	stat=shimo->query_isfill();
	if(stat==1) {
	write("ʯĥ���Ѿ�װ��%^H_YELLOW%^�ƶ�%^RESET%^�ˡ�\n");
	return 1;
	}
      this_body()->simple_action("$N������ף�������һ�ڴ�%^H_YELLOW%^�ƶ�%^RESET%^ȫ������ʯĥ�\n");
	shimo->set_isfill(1);
	destruct(soy);
	return 1;
}
