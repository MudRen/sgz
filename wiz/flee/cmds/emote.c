//create by flee@lima, 30 july 1998
//using emote_menu
#include <mudlib.h>
#define EMOTE_MENU "/wiz/flee/menu/emotemenu.c"
inherit CMD;
inherit M_GRAMMAR;

void create()
{
  ::create();
  no_redirection();
}
void main(string message)
{
	new(EMOTE_MENU)->start_menu();
}
