// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit ROOM;

int passage_open = 0;

void close_passage();

void setup() 
{
  set_area("pirate");
  set_brief("������");

  set_long("�����ǽ���ϻ���һ���ߴ���ĺ���ͼ����������һЩ���е�·�ߣ�"
           "�����Ͽ����ǿ�ͼ���������������һ��Сľ����");
  set_light(0);
  set_exits( ([
               ]) );
  set_hidden_exits();
  add_item("ceiling", "stars" , "����", "�ǿ�ͼ",
           "����һ�����ں���������ͼ��");
  add_item("legs","leg", "����", "����û��ʲô����ĵط���");
  add_item("surface", "����", "����û��ʲô����ĵط���");
  add_item("passage", "outline", "ͨ��", "ͨ��û��ʲô����ĵط���");
  add_item("maps", "����ͼ", 
           ([ "look" : "����ͼ��д������ʲݵ��ּ���",
            "get" : "�⺽��ͼ�ǿ���ǽ�ϵģ����ò�������" ]));

  set_objects( ([
                 "/domains/std/objects/navigation_table" : 1,
                 "/domains/std/objects/navigation_button" : 1,
                 ]) );
}

void open_passage()
{
  object o;

  if(passage_open)
    {
      return;
    }
  this_body()->simple_action("�������ǽҡ������һ�Ի�����¶��һ��ͨ����");
  o = load_object("/domains/std/rooms/caves/small_dock.c");
  add_exit("north" , "/domains/std/rooms/caves/small_dock.c");
  o->passage_opened();
  call_out((:close_passage:), 3);
  passage_open = 1;
}

void passage_opened()
{
    receive_inside_msg("�������ǽҡ������һ�Ի�����¶��һ��ͨ����\n");
    add_exit("north" , "/domains/std/rooms/caves/small_dock.c");
    passage_open = 1;
}


void close_passage()
{
  object o = load_object("/domains/std/rooms/caves/small_dock.c");
  o->passage_closed();
  delete_exit("north");
  receive_inside_msg("��ʯ���˻�ȥ��ǽ���ͨ���ֵ�ס�ˡ�\n");
  passage_open = 0;
}

void passage_closed()
{
  delete_exit("north");
  receive_inside_msg("��ʯ���˻�ȥ��ǽ���ͨ���ֵ�ס�ˡ�\n");
  passage_open = 0;
}
