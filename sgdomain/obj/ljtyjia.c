//by ljty on Jan 10 1997 ljtyjia.c
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
set_id("ljtyjia", HIG+"����ϸ����"+NOR);
set_in_room_desc(HIG+"����ϸ����(ljtyjia)"+NOR);
set_gettable(1);
set_slot(TORSO);
set_wearmsg("$N����$o���������ﶼӳ��һƬ "+HIG+"��ɫ�Ĺ�â��"+NOR+"\n");
set_removemsg("$N����$o��"+HIG+"��ɫ�Ĺ�â"+NOR+"��ʱ��ʧ�ˡ�\n");
set_attack_ablity(0);
set_defence_power(250);
set_defence_ablity(1000);
set_rongmao(10);
}
