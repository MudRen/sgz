// created by fire on Jan 19 1998
#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit FURNITURE;
inherit M_VALUE;

private int p_status;  // 1 for on, 0 for off

int turn_onoff( string par_str )
{
   if ( par_str == "on" )
   {
        write( "��򿪿��ء�" );
        
        p_status = 1;
    
   }
   else if ( par_str == "off" )
   {
        write( "����Ͽ��ء�" );
        
        p_status = 0;
   }
   else
   {
        write( "turn on ���� turn off\n" );    
   }
    
   return p_status;
    
}

int turn( string par_str )
{
   if ( par_str == "on" )
   {
        write( "��򿪿��ء�" );
        
        p_status = 1;
    
   }
   else if ( par_str == "off" )
   {
        write( "����Ͽ��ء�" );
        
        p_status = 0;
   }
   else
   {
        write( "turn on ���� turn off\n" );    
   }
    
   return p_status;
}

void setup()
{
  set_id("sofa", HIY+"ɳ��"+NOR);
  set_unit("��");
  set_in_room_desc("һ�������"+HIY+"ɳ��"+NOR+"��(sofa)");
  set_value(5000000);
  set_get_on_msg("");
  set_get_off_msg("$N�Ѿ��ش�ɳ����վ��������\n");
  set_long("����һ����������ڵ���Ƥɳ����Ҫ����ȥ���� sit on sofa��\n");
  set_preposition("on");
  set_relations("on","under");
  set_max_capacity(VERY_LARGE*5, "on");
//  add_action( "turn" );
}
// Unlike most furniture, you can lie on a bed.  We'll assume you mean sit
// on the bed here, but you can do what you want...
int direct_lie_on_obj()
{
  return 1;
}
int lie()
{
  return sit();
}
int mount_it_already()
{
  string stat;
  if(environment(this_body()) == this_object())
    {
      write("���Ѿ�����ɳ�������ˣ��׳ա�\n");
      return 1;
    }
  this_body()->move(this_object());
  this_body()->simple_action("$N��������غ�����"+short()+"�ϣ���Ҳ�����Աߵ���һ�ۡ�\n");
  return 1;
}

void do_wish_for_str( string str )
{
    write( "����ϣ������\n" );
}

