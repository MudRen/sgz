// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit ROOM;

private static int passage_open = 0;

void close_passage();
void open_passage();

void setup() 
{ 
  string river = "��ᱻ��ˮ�����ġ�";

  set_area("pirate");
  set_brief("С����");
  set_long("��ˮ���Ҷ����������룬������ĳ��ڡ�������һ����ľͷ���С"
           "���룬ľ�����Ѹ����ˣ�����һ�����ܵ���ͷ��");
  
  set_light(0);
  set_exits( ([
               "north" : river,
               "east" : river,
               "northeast" : river,
               "northwest" : "inside_cave",
               ]) );

  set_exit_msg("south", "$N���������Ӻ�ˮ������˳�ȥ��\n");

  set_hidden_exits("north","east", "northeast");
  set_default_exit ("�������û�г��ڡ�\n");
  add_item("door", "outline", 
           ([ 
             "look" :  "���������ģ�����㿴�˿������ò�̫���ܴ���߰����򿪡�", 
             "open" : "����߲�̫���ܰ����򿪡�"
            ]));

  set_objects( ([
                 "/domains/std/objects/river" : 1,
                 "/domains/std/objects/dock_wall" : 1,
                 "/domains/std/objects/dock" : 1, 
                 ]) );
}

string swim ()
{
  write("[in the river]\n");
  return present("river", this_object())->swim();
}

string wade ()
{
  write("[in the river]\n");
  return present("river", this_object())->wade();
}

void close_passage()
{
  object o = load_object("/domains/std/rooms/caves/navigation_room.c");
  o->passage_closed();
  delete_exit("south");
  receive_inside_msg("ͨ�����������ˡ�\n");
  passage_open = 0;
}

void passage_closed()
{
  delete_exit("south");
  receive_inside_msg("ͨ�������ˡ�\n");
  passage_open = 1;
}

void open_passage()
{
  object o;

  if(passage_open)
    {
      return;
    }
  this_body()->simple_action("�����·���ʯͷͻȻ��һ�Ի�����¶��һ��ͨ����");
  QUEST_D->grant_points(this_body(),"pirate:secretPsg");
  o = load_object("/domains/std/rooms/caves/navigation_room.c");
  add_exit("south" , "/domains/std/rooms/caves/navigation_room.c");
  o->passage_opened();
  call_out((:close_passage:),6);
  passage_open = 1;
}

void passage_opened()
{
    receive_inside_msg("�����·���ʯͷͻȻ��һ�Ի�����¶��һ��ͨ����\n");
  add_exit("south" , "/domains/std/rooms/caves/navigation_room.c");
  passage_open = 1;
}
