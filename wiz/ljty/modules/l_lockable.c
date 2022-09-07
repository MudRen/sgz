//By ljty. 

#include <mudlib.h>
#include <hooks.h>

string short();
void hook_state(string, function, mixed);
mixed call_hooks(string, int);

private string locked, key_type;
private int door_damaged = 0;

string unlock_msg =
"$N�ó���Կ�״򿪳��ŵĿ���װ�ã�ֻҪ��$o�ƿ������ˡ�\n"; 

string unlock_fail =
"$N��Կ�ײ��뿪��װ�õĿ����$oһ�㷴ӦҲû�С�\n";

string lock_msg = "$N�ó���Կ�״򿪳��ŵĹ���װ�ã�$o���̶������ˡ�\n";

string lock_fail = "$N��Կ�ײ������װ�õĿ����$oһ�㷴ӦҲû�С�\n";

string chuang_msg = "$N�Ĳ����ù��ǳ�ʹ����ײ$o�������е������ˡ�\n";

string chuang_fail =
"$N�Ĳ���ʹ����ײ$o��������˿������һ��Ч��Ҳû�С�\n"; 

string chuang_final_msg =
"$N�Ĳ����͵�һ�°�$oײ���ˣ�ȫ��һƬ��������Ҫ�����ӿ����\n"; 

string xiufu_msg = "$Nָ�Ӳ��ӿ��ٵ��޸�$o��ʹ���ӹ��˴ˡ�\n";

string xiufu_fail =
"$Nָ�Ӳ����޸�$o����һƬæ�ң�ָ��ʧ�飬����û�б仯��\n"; 

string xiufu_nouse_msg = 
"$Nָ�Ӳ����޸�$o����һЩ���˳��֮�����ƻ��˲��٣���û��֮ǰһ����\n";

string xiufu_final_msg =
"$oҲ���޵����ļ�̶̳��ˣ����������ˡ�\n";

function my_open_hook = (: short() + "�����ˡ�\n"    
                        :);

int is_lockable() { return 1; }

string query_locked() { return locked; }
int query_damaged() {return door_damaged;}

string query_key_type() { return key_type; }

varargs void set_locked(string x, string y) 
{
  key_type = y;
  locked = x;
  hook_state("prevent_open", my_open_hook, locked);
}

int resistance_to_chuanging;
int max_resistance_to_chuanging;

void set_resistance_to_chuanging(int s)
{
  resistance_to_chuanging = s;
  max_resistance_to_chuanging = s;
}

int get_resistance_to_chuanging()
{
  return resistance_to_chuanging;
}

void xiufu_with(object ob)
{
  int xiufu_prob = random(10);

  if(!( ob->xiufu_type() == "muchai"))
    {
      this_body()->simple_action(xiufu_fail, this_object());
      return;
    }
  else 
    {
      ob->num_decrease();
      if(xiufu_prob < 7) 
	{
	  resistance_to_chuanging ++;
	  this_body()->simple_action(xiufu_msg, this_object());
	}
      else 
	{
	  resistance_to_chuanging+= 0;
	  this_body()->simple_action(xiufu_nouse_msg, this_object());
	}
    }
  
  if (resistance_to_chuanging >= max_resistance_to_chuanging)
    {
      set_locked(0, key_type);
      door_damaged = 1;
      this_body()->simple_action(xiufu_final_msg, this_object());
    }
  else
    {
      if(resistance_to_chuanging > 10) door_damaged = 0;
    }
}

void xiufu()
{
  object ob = present("muchai",this_body());
  //write("(with " + ob->short() + ")\n");
  write("(��"+ob->short() + ")\n");
  xiufu_with(ob);
}


void chuang_with(object ob)
{
  if(!locked)
    //write("It's not locked.\n");
  write("��û�����ϡ�\n");     

  if(door_damaged) write("the door damaged\n");
  /*mixed ex = call_hooks("prevent_chuanging", HOOK_YES_NO_ERROR);

  if(!ex) ex = //"You can't seem to get it open.\n";
               "���޷�����Ū����\n"; 
  if(stringp(ex))
    {
      write(ex);
      return;
    }*/

  if(!( ob->chuang_type() == "gongchengche"))
    {
      this_body()->simple_action(chuang_fail, this_object());
      return;
    }
  else 
    {
      resistance_to_chuanging --;
    }
  
  if (resistance_to_chuanging < 0)
    {
      set_locked(0, key_type);
      door_damaged = 1;
      this_body()->simple_action(chuang_final_msg, this_object());
    }
  else
    {
      this_body()->simple_action(chuang_msg, this_object());
    }
}

void chuang()
{
  object ob= present("gongchengche", environment(this_body()));
  write("(��"+ob->short() + ")\n");
  chuang_with(ob);
}

      
void unlock_with(object ob)
{

  /*mixed ex = call_hooks("prevent_unlock", HOOK_YES_NO_ERROR);
  if (!ex) ex = //"You can't seem to unlock it.\n";
  "���޷��������򿪡�\n";
    if (stringp(ex)) {
      write(ex);
      return;
    }*/
   
  if (ob->key_type() == key_type)
    {
      this_body()->simple_action(unlock_msg, this_object(), ob);
      set_locked(0, key_type);
      hook_state("prevent_open", my_open_hook, locked);
    }
  else
    {
      this_body()->simple_action(unlock_fail, this_object(), ob);
    }
}

void unlock() 
{
  object ob = present("key", this_body());
  //write("(with " + ob->short() + ")\n");
  write("(��"+ob->short() + ")\n");
  unlock_with(ob);
}

void lock_with(object ob) 
{
  if(door_damaged) 
    {
      "���������ˣ��޷���ʹ�����ϡ�\n";
    }
  else
    {
      if (ob->key_type() == key_type) 
	{
	  this_body()->simple_action(lock_msg, this_object(), ob);
	  set_locked(key_type,key_type);
	}
      else 
	{
	  this_body()->simple_action(lock_fail,this_object(), ob);
	}
    }
}

void lock() {
    object ob = present("key", this_body());
    //write("(with " + ob->short() + ")\n");
    write("(��"+ ob->short() + ")\n");
    lock_with(ob);
}

/*********************************************************/
/*    verb interactions                                   */
/**********************************************************/

mixed direct_chuang_obj(object ob)
{
    if (!locked)
      return //"It isn't locked.\n";
               "��û�����ϡ�\n";
    if (present("gongchengche", environment(this_body())))
      return 1;
    return "��ʲô��\n";     
}

mixed direct_xiufu_obj(object ob)
{
  if (present("muchai",this_body()))
    return 1;
  return "��ʲô��\n";     
}

mixed direct_unlock_obj(object ob) {
    if (!locked)
        return //"It isn't locked.\n";
               "��û�����ϡ�\n"; 
    if (present("key", this_body()))
        return 1;
    return //"With what?\n";
           "��ʲô��\n";     
}

mixed direct_lock_obj(object ob) {
    if (locked)
        return //"It is already locked.\n";
               "���Ѿ��������ˡ�\n";
    if (present("key", this_body()))
        return 1;
    return //"With what?";
           "��ʲô��\n";    
}

mixed direct_unlock_obj_with_obj(object ob1, object ob2) {
    return 1;
}

mixed direct_chuang_obj_with_obj() {
  return 1;
}

mixed direct_xiufu_obj_with_obj() {
  return 1;
}

mixed direct_lock_obj_with_obj() {
    return 1;
}

int can_chuang_obj()
{
  return 1;
}

int can_chuang_obj_with_obj()
{
  return 1;
}

int can_xiufu_obj()
{
  return 1;
}

int can_xiufu_obj_with_obj()
{
  return 1;
}
