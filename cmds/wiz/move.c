// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

//Megaboz@ZorkMUD

#include <mudlib.h>
inherit CMD;

private void main( mixed *arg )
{
//:FIXME the room where the object was probably needs a message too
    arg[0]->move(arg[1]);
    tell(arg[0], "�㱻���͵���" + arg[1]->short() + "\n");
    tell_from_inside(arg[1], arg[0]->a_short() + "���������͵������\n", 0, ({arg[0]}));
}
