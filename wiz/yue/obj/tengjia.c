/* /wiz/yue/obj/tengjia.c */
// created by yue 19980301
#include <sanguo.h>
#include <mudlib.h>
#include <bodyslots.h>
#include <ansi.h>
inherit M_VALUE;
inherit M_WEARABLE;
inherit M_GETTABLE;
inherit M_DAMAGE_SINK;
void setup()
{
::mudlib_setup();
set_unit("��");
set_id("teng jia", "�ټ�");
add_id("tengjia","jia","armor");
set_in_room_desc("�ټ�(teng jia)");
set_gettable(1);
set_slot(TORSO);
set_wearmsg(YEL+"$N����һ���ټס�"+NOR);
set_removemsg(YEL+"$N���ټ�����������"+NOR);
set_value(15);
set_currency_type("silver");
set_defence_power(25);
set_defence_ablity(0);
}
