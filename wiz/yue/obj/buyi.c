//by fire on Jan 10 1997 
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
set_id("buyi", "����");
add_id("buyi","linen","cloth");
set_in_room_desc("����(cloth)");
set_long("һ���Ʋ��£���������˲�����");
set_gettable(1);
set_slot(TORSO);
set_wearmsg("$N����һ��$o��\n");
set_removemsg("$N����һ��$o��\n");
    set_currency_type("silver");
    set_value(3);
}
