//yuyi.c �������� by benben
#include <sanguo.h>
#include <mudlib.h>
#include <bodyslots.h>
inherit M_WEARABLE;
inherit M_GETTABLE;
inherit M_DAMAGE_SINK;
void setup(){	
::mudlib_setup();
    set_adj("������ۼ��");	
    set_unit("��");	 
    set_id("yuyi", "��������");		
        add_id("feather cloth");	
    set_long("һ�����������������¡�");	
    set_in_room_desc("��������(yuyi)");	
    set_gettable(1);	
    set_slot(TORSO);
}