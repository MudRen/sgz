// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit CMD;
inherit M_MESSAGES;



private void main(string notused)
{
  int hp = this_body()->query_hp();
  int sp = this_body()->query_sp();
 
  this_body()->my_action("$N����:  HP: " + hp + "  SP: " + sp + ".\n");
}
