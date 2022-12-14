// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
#include <move.h>

inherit OBJ;
inherit M_GETTABLE;

void setup() {
    set_id("rock", "碎石", "rocks", "debris", "rubble");
    set_unit("块");
    set_attached(1);
    set_long("碎石没什么意思。");
    set_gettable(1);
    set_size(TOO_LARGE);
}

mixed get()
{
    object env = environment(); 
    mixed  r;

    if((r = ::get()) == MOVE_OK)
    {
        this_body()->simple_action ("$N拾起一块石头。");
        new(__DIR__+  "rock")->move(this_body());
        return MOVE_NO_ERROR;
    }
    return r;
}
