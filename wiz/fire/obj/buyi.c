//by jiezhao on Dec 25 1997 buyi.c ����
#include <sanguo.h>
#include <mudlib.h>
#include <bodyslots.h>
inherit M_WEARABLE;
inherit M_GETTABLE;
inherit M_DAMAGE_SINK;
void setup()
{
::mudlib_setup();
set_adj("��");
set_unit("��");
set_id("cloth", "��");
add_id("linen");
add_id("buyi");
set_long("һ���Ʋ��£���������˲�����");
set_in_room_desc("����(cloth)");
set_gettable(1);
set_slot(TORSO);
}
