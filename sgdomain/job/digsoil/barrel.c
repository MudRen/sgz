// by fire on Jan 9 1998 barrel.c
#include <ansi.h>
inherit OBJ;
inherit M_GETTABLE;
inherit M_VALUE;
int isfill;
string short();
void setup() {
    set_adj("��ª��");
    set_id("mu tong", "ľͰ","barrel");
    set_unit("��");
    set_in_room_desc("һֻũ�ҽ��ص�ľͰ(mu tong)��");
    isfill=0;
    set_value(100);
    set_currency_type("coin");
}
string long()
{
    if(isfill)
    {
       return "һֻũ�ҽ��ص�ľͰ(mu tong)��\n"+
        "����װ����ˮ��\n";
    }
    return "һֻũ�ҽ��ص�ľͰ(mu tong)��\n";
}
mixed direct_fill_obj()
{
   return 1;
}
void fill_with(object with)
{
   string s_obj;
   if(isfill)
   {
      printf("%s�Ѿ����ˡ�\n",short());
      return;
   }
   isfill=1;
   this_body()->simple_action("$N��"+short()+"װ����ˮ��\n");
}
mixed direct_turn_obj()
{
        return 1;
}
int turn()
{
        object player;
        object room;
        object soil;
        int hp;
 	int stat;
        player = this_body();
        room = environment( player );
        if( !soil = present("tu di", room) )
        {
                write("�����ˮ�������\n");
                return 1;
        }
 	stat=soil->query_status();
	if((stat<21)) {
		write("����Ӧ���ȳ����ء�dig soil with chu tou\n");
		return 1;
	}
	if(stat>40) {
        if(this_body()->query_job("digsoil","beg_time"))
        {
           this_body()->set_job("digsoil","status","done");
        }
		write("���Ѿ�����ˣ���ȥ��Ǯ�ɡ�\n");
		return 1;
	}

        hp = player->query_cur_hp();    
        if( hp < 10 ){
                printf("���Ѿ�̫���ˣ���������Ϣһ���ٸɰɡ�\n");
                return 1;
        }
        if( !isfill){
                printf("Ͱ���ˮ�����ˡ�\n");
                return 1;
        }
	if(soil->water())
	{
	        player->set_cur_hp( hp - 10);
		isfill=0;
	}
}
