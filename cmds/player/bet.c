// bet.c
// by Suicide on Sep 6 2000

#include <mudlib.h>
#include <daemons.h>
inherit CMD;
inherit M_GLOB;

private void main(string arg)
{
   string result;
   object me = this_body();
   if (!environment(me)->is_casino())
      {write("������Ƕĳ�����ָ����Ч��\n");
       return;}
   if (stringp(result=environment(me)->do_bet(arg)))
      write(result);
   
}
