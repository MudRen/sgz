// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit VERB_OB;

void do_wish_for_str(string str) {
    write("������ܺã�����ô��\n");
}

array query_verb_info() 
{
    return ({ ({ "for STR" }) });
}
