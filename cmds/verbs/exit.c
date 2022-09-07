// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */


inherit VERB_OB;

//### Odd.  This never uses 'ob'.
void do_exit(object ob)
{
  mixed s;
  string err;
  object last_loc;

  if(objectp(ob) && ob != environment(this_body()))
    {
      write("�㲻�������档\n");
      return;
    }
  last_loc = environment(this_body());

  if(s = environment(this_body())->exit())
    {
      if(!stringp(err=this_body()->move(environment(environment(this_body())))))
        {
          if(stringp(s))
            this_body()->simple_action(s);
          else
            this_body()->simple_action("$N�뿪��$o.", last_loc);
        }
      else
        {
          write(err+"\n");
        }
    }
  else
    {
      if(environment(environment(this_body())))
        {
          write("��˿��޷��뿪��\n");
        }
      else
        {
          write("û���뿪�ķ���\n");
        }
    }
} 

void do_exit_obj(object ob)
{
  do_exit(ob);
}


array query_verb_info()
{
    return ({ ({ "OBJ", "" }), ({ "leave", "disembark" }) });
}
