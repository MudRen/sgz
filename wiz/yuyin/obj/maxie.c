//maxie.c ��Ь by row
#include <sanguo.h>
#include <ansi.h>
#include <mudlib.h>
#include <bodyslots.h>
inherit M_WEARABLE;
inherit M_GETTABLE;
inherit M_DAMAGE_SINK;
void setup()
{
::mudlib_setup();
set_unit("˫");
set_id("ma xie", YEL+"��Ь"+NOR);
add_id("shoes","xie");
set_in_room_desc(YEL+"��Ь(ma xie)"+NOR);
set_long("һ˫��������ɵ�Ь�ӣ��������е����š�");
set_wearmsg("$N����һ˫"+YEL+"��Ь"+NOR+"��\n");
set_removemsg("$N����һ˫"+YEL+"��Ь"+NOR+"��\n");
set_gettable(1);
set_slot(FEET);
}