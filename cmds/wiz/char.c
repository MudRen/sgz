//create by flee@lima on 3 Aug 1998
//using character_menu
#include <mudlib.h>
#define CHAR_MENU "/wiz/flee/menu/charmenu.c"
inherit CMD;
inherit M_GRAMMAR;

void create()
{
  ::create();
  no_redirection();
}
void main(string message)
{
        new(CHAR_MENU)->start_menu();
}
