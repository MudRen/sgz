#include <move.h>
inherit NON_ROOM;
inherit M_SMARTMOVE;
inherit M_MESSAGES;
string short();
string get_riders_as_string();
private string mount_msg = "$N翻身上马。" ;
private string dismount_msg= "$N一翻身，跳下马来。";
private static string arrival_msg= "骑着一匹战马奔驰而来。\n";
private static string departure_msg="骑在马上向远方离去。\n";
private static string ridetwo_msg="$N空出了一点地方, 让另一人上马。\n";
private static string rideone_msg="$N现在不想与别人共骑一匹马了。\n";

private static int m_attack_ablity=0;
private static int m_defence_ablity=0;
private static int m_attack_power=0;
private static int m_defence_power=0;

private *name_list=({"xiaolong"}); 
private int can_ride_two = 0;

int get_the_number_on_horse()
{
// Get the inventory of the horse.
  object array inv = all_inventory(this_object());
  // Filter out anything that isn't living.
  object array riders = filter(inv, (: $1->is_living() :));
  if(sizeof(riders) == 1)
    return 1;
  else return 0;
}

void set_defence_ablity(int p_tmp)
{
  m_defence_ablity=p_tmp;
}
void set_attack_power(int p_tmp)
{
  m_attack_power=p_tmp;
}
void set_attack_ablity(int p_attack)
{
  m_attack_ablity=p_attack;
}
void set_defence_power(int p_def)
{
  m_defence_power=p_def;
}

int query_defence_power()
{
  if(get_the_number_on_horse())
    return m_defence_power;
  else return m_defence_power/4;
}
int query_defence_ablity()
{
  if(get_the_number_on_horse())
    return m_defence_ablity;
  else return m_defence_ablity/4;
}
int query_attack_power()
{
  if(get_the_number_on_horse())
    return m_attack_power;
  else return m_attack_power/4;
}
int query_attack_ablity()
{
  if(get_the_number_on_horse())
    return m_attack_ablity;
  else return m_attack_ablity/4;
}

static void set_arrival_msg(string s)
{
  arrival_msg = s;
}
static void set_departure_msg(string s)
{
  departure_msg = s;
}
string get_arrival_msg()
{
  return get_riders_as_string()+arrival_msg;
}
string get_departure_msg()
{
  return get_riders_as_string()+departure_msg;
}

//### this isn't right, but I didn't want to redesign _too_ much just yet
string *get_player_message(string message, mixed arg) {
    string mess;
    if ( message == "leave" )
      {
    mess = get_departure_msg();
      }
    else if ( message == "enter" )
      {
    mess = get_arrival_msg();
      }
    return action( ({ this_object() }), mess, arg);
}

string query_final_exit_value(string str, int is_normal)
{
  string ret;
  if((!(ret = ::query_exit_value(str, is_normal)) || ret[0] == '#')
     && environment())
    return environment()->query_exit_value(str, is_normal);
  return ret;
}
int can_travel()
{
  return 1;
}

object array get_riders()
{
  return filter(all_inventory(this_object()), (:$1->is_living():));
}
string show_contents()
{
  if(environment(this_body()) != this_object())
    return inventory_recurse(0, get_riders());
//  return ::show_contents();
        return "";
}
string get_riders_as_string()
{
  // Get the inventory of the horse.
  object array inv = all_inventory(this_object());
  // Filter out anything that isn't living.
  object array riders = filter(inv, (: $1->is_living() :));
  if(!sizeof(riders))
    {
      return 0;
    }
  // Return a string that's a comma seperated list of the riders.
  if(sizeof(riders) == 1)
    {
      return riders[0]->short();
    }
  return implode(map(riders[0..<2], (: $1->short() :)), "、")+ "和" +
    riders[<1]->short();
}
string query_in_room_desc()
{
  string base_desc = ::query_in_room_desc();
  if(!inventory_visible() || !sizeof(get_riders()))
    {
      return base_desc;
    }
  else
    {
      string p_tmp;
        switch(random(5))
        {
                case 0:
                        p_tmp="雄赳赳地";
                        break;
                case 1:
                        p_tmp="得意洋洋地";
                        break;
                case 2:
                        p_tmp="垂头丧气地";
                        break;
                case 3:
                        p_tmp="呲牙咧嘴地";
                        break;
                default:
                        p_tmp="张牙舞爪地";
                        break;
        }
        if(sizeof(get_riders())==2)
        switch(random(3))
        {
                case 0:
                        p_tmp="柔情蜜意地";
                        break;
                case 1:
                        p_tmp="两情相依地";
                        break;
                default:
                        p_tmp="含情脉脉地";
                        break;
        }
      return get_riders_as_string()+p_tmp+"骑在"+base_desc+"上";
    }
}
void notify_move()
{
    object *inv;
    object curr;
    inv = all_inventory(this_object());
    foreach(curr in inv)  {
        if(curr->query_link())
            curr->force_game_command("look");
    }
}
int is_vehicle()
{
  return 1;
}
int is_horse()
{
  return 1;
}
static void set_ride_msg(string s)
{
  mount_msg = s;
}
static void set_unride_msg(string s)
{
  dismount_msg = s;
}
static void set_ridetwo_msg(string s)
{
 ridetwo_msg = s;
}
static void set_rideone_msg(string s)
{
  rideone_msg = s;
}
string query_rideone_msg()
{
  return rideone_msg;
}
string query_ridetwo_msg()
{
  return ridetwo_msg;
}
string query_ride_msg()
{
  return mount_msg;
}
string query_unride_msg()
{
  return dismount_msg;
}
string handle_exit_msgs(object last_loc)
{
  return query_ride_msg() || //"$N $vget on "+short()+".\n";
                               "$N站上了"+short()+"。\n";  
}
private void mount_it_already()
{
  if(environment(this_body()) == this_object())
    {
      write("你已经骑在马上了。\n");
      return;
    }
  if(this_body()->move(this_object())==MOVE_OK)
          this_body()->simple_action(mount_msg);
  else
          this_body()->simple_action(
"$N想跳上"+short()+"，结果没上去掉了下来。\n");
}
void ride()
{
  string p_id;
  p_id = this_body()->query_userid();
  if(!get_the_number_on_horse())
    {
      if(member_array(p_id,name_list) != -1)
        mount_it_already();
      else write("这不是你的马。\n");
    }
  else
    {
      if(can_ride_two) mount_it_already();
      else write("马的主人没有让你上马。\n");
    }
}
void ridetwo()
{
if(get_the_number_on_horse())
{
 can_ride_two = 1;
this_body()->simple_action(ridetwo_msg);
    }
  else write("马上已经有两个人了。\n");
}
void rideone()
{
if(get_the_number_on_horse())
 {
   can_ride_two = 0;
   this_body()->simple_action(rideone_msg);
 }
  else write("马上已经有两个人了，等他下去再说吧。\n");
}

mixed stand()
{
  return query_unride_msg() ;
}
int unride()
{
  if(environment(this_body()) != this_object())
    return 0;
  return stand();
}
int direct_unride_obj()
{
  return 1;
}
int direct_ride_obj()
{
  return 1;
}
int stat_me() {
    printf("房间: %s [ %s ]\n\n",
      short(), implode(query_exit_directions(1), ", "));
    ::stat_me();
    return 1;
}
void do_looking(int forced_look)
{
    this_look_is_forced = forced_look;
    if ( wizardp(this_body()) &&
      this_body()->query_shell_ob()->get_variable("show_loc") )
    {
    printf("[%s]\n", file_name(this_object()));
    }
    if ( environment(this_object())->query_light() < 1 )
    {
    write("这里很黑，什么也看不清楚。\n");
    }
    else
    {
        object array riders = filter(all_inventory(this_object()), (:
$1->is_living() :));

	printf("%s [exits: %s]\n",
	       environment(this_object())->get_brief(), 
	       environment(this_object())->show_exits());
	write(wrap(get_location_description()));
        if(sizeof(riders) == 1)
        {
                printf("你骑在%s上。\n",short());
        }
        else
        {
                object oth;
                if (riders[0]==this_body())
                        oth=riders[1];
                else
                        oth=riders[0];
                printf("你和%s骑在%s上。\n",oth->short(),short());
        }
    }
}
varargs string inventory_recurse(int depth, mixed avoid) 
{
    return "";
}
void horse_master_add(string man_id)
{
  name_list += ({ man_id });
}
int direct_ridetwo_obj()
{
  return 1;
}
int direct_rideone_obj()
{
  return 1;
}
