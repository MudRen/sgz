// condition poison.c �ж�
// group@sgz August 23, 1999
#include <ansi.h>
#include <mudlib.h>
#include <daemons.h>

void execute_con(int tid, int damage, int duration)
{
	object tt;

	tt = TROOP_D->find_troop( tid );

	if( !tt||!objectp(tt)||!tt->is_troop() ){
		SGSYS(sprintf("troop %O does not exist, ", tid));
		return;
	};
	
	WARAI_D->kill_troop(tid, damage);
	
	tell(all_inventory(tt),
	HIR"ֻ��ʿ������ɫ���࣬���°�ĭ�������ж��ļ���"+NOR+"\n");
	WARAI_D->war_inf(TROOP_D->get_troops(tid,"task_id"),
	tt->query_id()[1]+"���ж����ţ���ʧ"+chinese_number(damage)+"�ˡ�","b");
	WARAI_D->clear_empty_troop(({tid}));
	return;
}
