// condition fake.c �Ի�
// group@sgz August 23, 1999
#include <ansi.h>
#include <mudlib.h>
#include <daemons.h>

void execute_con(int tid, int damage, int duration)
{
	object tt;
	int mora, mora1;

	tt = TROOP_D->find_troop( tid );
	
	if( !tt||!objectp(tt)||!tt->is_troop() ){
		SGSYS(sprintf("troop %O does not exist, ", tid));
		return;
	};
	
	if (duration <= 3)
	{ tell(all_inventory(tt),
	  HIR"�Ի�����"+NOR+"\n");
	  if (TROOP_D->get_troops(tt, "fake"))
		TROOP_D->set_troops(tt,"fake", 0);
	}	
	return;
}
