// by row
#include <ansi.h>
inherit OBJ;
inherit M_GETTABLE;
void my_drop();
void add_hook(string s,function f);
void setup() {
    set_id("mai zhong", ""+HIY+"����"+NOR+"","seeds");
    set_unit("��");
   set_size(VERY_SMALL);
    set_in_room_desc(""+HIY+"����"+NOR+"(mai zhong)��\n");
    set_long("����һС����Ϊ���ӵ��������ſŽ�Ʊ�����\n");
   add_hook("move",(:my_drop:));
}
void my_drop()
{
   object env=environment();
   object soil;
   soil=present("tu di",env);
   if(objectp(soil))
   {
      tell_environment(this_object(),"I got it hehehehe\n");
   this_object()->remove();
   }
}
