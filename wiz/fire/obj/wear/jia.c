//by fire on Jan 10 1997 jia.c
// modified by fire on March 1 1998
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
set_id("jia", HIG+"����ϸ����"+NOR);
set_in_room_desc(HIG+"����ϸ����(jia)"+NOR);
set_gettable(1);
set_slot(ARMORS);
set_wearmsg("$N����$o���������ﶼӳ��һƬ "+HIG+"��ɫ�Ĺ�â��"+NOR+"\n");
set_removemsg("$N����$o��"+HIG+"��ɫ�Ĺ�â"+NOR+"��ʱ��ʧ�ˡ�\n");
set_attack_ability(-10);
set_defence_power(50);
set_defence_ability(-5);
set_rongmao(1);
}
