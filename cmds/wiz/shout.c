// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

//  _shout.c
// Mars@ZorkMUD  4-24-94

#include <mudlib.h>
inherit CMD;
inherit M_GRAMMAR;

void create()
{
  ::create();
  no_redirection();
}

private void main(string s) {
    if (!s || s == "") {
        out("º°Ê²Ã´£¿\n");
        return;
    }

    tell(users()-({this_user()}), this_body()->query_name() + "×ÝÉù´ó½Ð£º" + punctuate(s) + "\n", MSG_INDENT);
    out("Äã×ÝÉù´ó½Ð£º" + punctuate(s) + "\n");
}

