// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <bodyslots.h>

inherit OBJ;
inherit M_GETTABLE;
inherit M_WEARABLE;
inherit M_VALUABLE;

void setup() {
    set_adj("red");
    set_id("scarf");
    set_gettable(1);
#ifdef USE_BODY_SLOTS
    set_slots(TORSO);
#endif
    set_value(10);
}
