// by fire
/* Do not remove the headers from this file! see /USAGE for more info. */
#include <ansi.h>

inherit LIVING;
inherit M_BLOCKEXITS;

private mixed handle_blocks( string dir )
{
	if(present("ysf pass",this_body())) {
		this_object()->targetted_action(
"$N��$Tһ�Ϲ�����$R��Ȼ��ʥ�ϵ����ͣ������롣\n",this_body());
		return 0;
	}
        return ::handle_blocks(dir);    
}
void setup()
{
        set_name("xiao daoshi", "С��ʿ");
        set_gender(1);
        set_in_room_desc("С��ʿ(xiao daoshi)");
        set_age(10);
        add_block("north");
        set_block_action(
"$Nһ������ķ�������$T����������ʥ�ϵ���������$R��������û��ʥ�ϵ����ͣ�˭Ҳ���ܽ���\n");
}
string long() {
	return "һ��С̫�ࡣ\n";
}