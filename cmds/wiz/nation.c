//create by flee@lima on 3 Aug 1998
//using character_menu
#include <mudlib.h>
#define NATION_MENU "/cmds/area/nation_menu.c"
inherit CMD;
inherit M_GRAMMAR;

void create()
{
  ::create();
  no_redirection();
}
void main(string message)
{
        new(NATION_MENU)->start_menu();
}
