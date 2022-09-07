//yuyi.c ÄŞÉÑÓğÒÂ by benben
#include <sanguo.h>
#include <mudlib.h>
#include <bodyslots.h>
inherit M_WEARABLE;
inherit M_GETTABLE;
inherit M_DAMAGE_SINK;
void setup(){	
::mudlib_setup();
    set_adj("ÃÀÂ×ÃÀÛ¼µÄ");	
    set_unit("¼ş");	 
    set_id("yuyi", "ÄŞÉÑÓğÒÂ");		
        add_id("feather cloth");	
    set_long("Ò»¼şÇáÈç²õÒíµÄÄŞÉÑÓğÒÂ¡£");	
    set_in_room_desc("ÄŞÉÑÓğÒÂ(yuyi)");	
    set_gettable(1);	
    set_slot(TORSO);
}