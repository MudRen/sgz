#include <mudlib.h>
#include <bodyslots.h>
#include <ansi.h>
#include <sanguo.h>
inherit M_WEARABLE;
inherit M_GETTABLE;
inherit M_DAMAGE_SINK;
inherit M_VALUE;
void setup()
{
    ::mudlib_setup();
    set_unit("ֻ");
    set_id("listenring", HIG+"����ָ"+NOR);
    add_id("ring");
    set_in_room_desc(HIG+"����ָ"+NOR+"(listen's ring)");
    set_long("��������С�ݵĶ������");
    set_gettable(1);
	set_slot(HANDS);
	set_wearmsg("$N����ذ�$o�����Լ�������ָ�ϡ�\n");
	set_removemsg("$NС�ĵذ�$o�Żؽ����С�\n");
    set_attack_ability(100);
	set_defence_power(40);
    set_defence_ability(100);
    set_value(-1);
    set_currency_type("gold"); 
}
