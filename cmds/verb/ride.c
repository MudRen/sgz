#include <mudlib.h>
#include <move.h>
#include <setbit.h>
inherit VERB_OB;

void do_qi_obj(object what)
{
    what->ride();
}

void do_ride_obj(object what)
{
  what->ride();
}

void do_xia_obj(object what)
{
    mixed s;
    string err;
    if(what != environment(this_body()))

    {
        write("�㲻�������档\n");
        return;
    }
    if(s = what->unride())
    {
        if(!stringp(err=this_body()->move(environment(what))))
        {
            if(stringp(s))
                this_body()->simple_action(s);
            else
                this_body()->simple_action("$N��" + what->short()+
                  "��������");
        }
        else
        {
            write(err+"\n");
        }

    }
    else
    {
        write("���Ѿ�վ�ڵ����ˡ�\n");
    }
}
void do_unride_obj(object what)
{
  do_xia_obj(what);
}
int do_xia()
{
    "/cmds/verbs/stand"->do_stand();
}

int do_unride()
{
    "/cmds/verbs/stand"->do_stand();
}

array query_verb_info()
{
      return ({ ({ "OBJ"}) });
}
