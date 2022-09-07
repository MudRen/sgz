#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>

inherit M_BLOCKEXITS;

string the_direction;
mixed ret;

void set_the_direction(string str)
{
  the_direction = str;
}
int can_go_the_direction()
{
  if(this_body()->query_door_state(the_direction) == "�����ǿ����ġ�")
    return 1;
  else return 0;
}

string query_door_state()
{
  object ob;
  string tmp;
  tmp = environment(this_body())->query_exit_value(the_direction);
  ob = load_object(tmp);
  foreach (object ob2 in all_inventory(ob))
    {
      if(member_array("citydoor",ob2->query_id())!=-1)
       {
         if(ob2->query_locked()) return "�����Ѿ������ˡ�";
         if(ob2->query_closed()) return "�����ǹرյġ�";
         if(ob2->query_damaged()) return "�����Ѿ���ײ���ˡ�";
         return "�����ǿ����ġ�";
       }
    }
}

int can_go_str(string str)
{
  object env = environment(this_body());
  if (is_chinese(str)) 
    {
      str = DIRECTION_D->to_english(str);
    }
  if( function_exists( "can_go_" + str, env) && (this_body()->query_door_state(the_direction) == "�����ǿ����ġ�"))
    {
      ret = call_other( env, "can_go_" + str );
      if( ret == 1 ) return 1;
      return ret;
    }
}


