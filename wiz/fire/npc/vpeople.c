// vpeople.c "����"
#include <mudlib.h>
inherit LIVING;
inherit M_WANDER;
void setup()
{
    set_name("people", "����");
    add_id("cunmin");	 
   set_gender(1);
    set_proper_name("�������µĴ���");
    set_in_room_desc("�������µĴ���(people)");
    set_movement_time(20);
    set_wander_area("xbv_area");
}
