// recover.c by fire on Jec 30 1997
// this cmd is just used for test period for player to
// recover the hp
// removed by yue
#include <mudlib.h>
#include <ansi.h>
#include <sanguo.h>
inherit CMD;
void main() 
{

	int p_tmp;
if(!wizardp(this_body()))
{
   write("�㻹ÿѧ�����ǹ���ѽ��\n");
return ;
}
	p_tmp=this_body()->query_sg_max_hp();
        this_body()->set_cur_max_hp(p_tmp);
        this_body()->set_cur_hp(p_tmp);
	this_body()->simple_action(HIG+
        "$N��������񹦣�һ˲�䣬һ����ʹȫ��Ϊ�ޡ�\n"+NOR);
}
