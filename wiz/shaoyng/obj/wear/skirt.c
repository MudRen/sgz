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
set_unit("��");
set_id("skirt", HIG+"һ������ȹ"+NOR);
set_in_room_desc(HIG+"һ������ȹ(skirt)"+NOR);
set_gettable(1);
set_slot(TORSO);
set_wearmsg("$N����$o���������ﶼӳ��һƬ "+HIG+"��ɫ�Ĺ�â��"+NOR+"\n");
set_removemsg("$N����$o��"+HIG+"��ɫ�Ĺ�â"+NOR+"��ʱ��ʧ�ˡ�\n");
}
