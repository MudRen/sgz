// A simple condition stim_pack.c �˷ܼ�
// Flee@sgz August 21, 1999
#include <ansi.h>

void execute_con(int tid, int damage)
{
	object tt;

	tt = TROOP_D->find_troop( tid );

	if( !tt||!objectp(tt)||!tt->is_troop() ){
		SGSYS(sprintf("troop %O does not exist, ", tid));
		return;
	};
	
	TROOP_D->recover_energy( tid );
	
	tell(all_inventory(tt), "ֻ��ʿ���Ǹ�����ɫ"+HIC+"����"+NOR+"���۾�"+HIR+"����"+NOR+"�����ȵ�ƣ�ͷ·�һɨ�����ˣ�\n"+HIW+"ʿ�����ж����ָ��ˣ�����"+NOR+"\n");

	return;
}
