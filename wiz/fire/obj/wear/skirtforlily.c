//by fire on Jan 10 1997 
//skirtforlily.c
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
set_id("skirt", "һ��"+HIR+"�ʺ�"+HIG+"��ȹ"+NOR);
set_in_room_desc("һ��"+HIR+"�ʺ�"+HIG+"��ȹ"+NOR);
set_gettable(1);
set_slot(LEGS);
set_removemsg("$N����$o��"+HIR+"��ɫ�Ĺ�â"+NOR+"��ʱ��ʧ�ˡ�\n");
}
void do_wear()
{
    object who;
    who=owner(this_object());
    foreach (object ob2 in all_inventory(who)) 
    {
        
        if ((ob2->ob_state()==LEGS))
        {
                write("���Ѿ�������ͬ��װ���ˡ�\n");
                return;
        }
    }   
    if(who->query_userid()=="lily")
    {
	    set_is_on(1);
	    who->simple_action("$N����$o���������ﶼӳ��һƬ "+HIR+"��ɫ�Ĺ�â��"+NOR+"\n", this_object());
    }
    else
    {
	who->simple_action("$N����$o��һ�°��������ˣ�¶����ƨ�ɡ�\n",this_object());
    }
}
