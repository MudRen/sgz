// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** _idea.c
**
** Converted to new /std/reporter usage (Deathblade 4-Sep-94).
** Original by Rust (?)
*/

#include <mudlib.h>
inherit CMD;

void create()
{
  ::create();
  no_redirection();
}

private void main(string str)
{
    REPORTER_D->report_something("Idea", str);
}

void player_menu_entry()
{
  bare_init();
  main("");
  done_outputing();
}
