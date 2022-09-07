// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** dismount.c
*/


inherit VERB_OB;


void do_dismount(object what)
{
  mixed s;
  string err;

  if(!objectp(what))
    what = environment(this_body());

  if(what != environment(this_body()))
    {
      write("�㲻�������档\n");
      return;
    }
  if(s = what->dismount())
    {
      if(!stringp(err=this_body()->move(environment(what))))
        {
          if(stringp(s))
            this_body()->simple_action(s);
          else
            this_body()->simple_action("$N��" + what->short()+
                                       "������");
        }
      else
        {
          write(err+"\n");
        }
    }
  else
    {
      if(!environment(environment(this_body())))
        write("���Ѿ���վ�ŵ��ˡ�\n");
      else
        write("You're have no mount of which to speak.\n");
    }
} 

void do_dismount_obj(object o)
{
  do_dismount(o);
}

array query_verb_info()
{
    return ({ ({ "", "OBJ" }) });
}


