// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** sit.c
*/


inherit VERB_OB;


void do_sit_in_obj(object ob1)
{
  ob1->sit("in");
} 

void do_sit_on_obj(object ob1)
{
  ob1->sit("on");
}

void do_sit_at_obj(object ob1)
{
    ob1->sit("at");
}
void do_sit_obj(object ob1)
{
  ob1->sit();
}

array query_verb_info()
{
    return ({ ({ "in OBJ", "on OBJ", "at OBJ","OBJ" }) });
}


