//by fire on Jan 10 1997 
#include <sanguo.h>
#include <mudlib.h>
#include <bodyslots.h>
#include <ansi.h>
inherit M_WEARABLE;
inherit M_GETTABLE;
inherit M_DAMAGE_SINK;
void setup()
{
::mudlib_setup();
set_unit("֦");
set_id("rose", HIR+"õ��"+NOR);
set_in_room_desc("һ֦"+HIR+"��õ��"+NOR);
set_gettable(1);
set_slot(BREST);
set_wearmsg("$N����ǰ����һ֦"+HIR+"��õ��"+NOR+"���Եø��ӽ��޶��ˡ�\n");
set_removemsg("$NС������ؽ�"+HIR+"��õ��"+NOR+"����ǰȡ������\n");
}
