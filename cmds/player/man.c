// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
inherit CMD;

private void main(string arg)
{
    new(HELPSYS)->begin_help(arg);
}

void player_menu_entry()
{
  bare_init();
  main("");
  done_outputing();
}
