// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit ROOM;

void setup()
{
  set_area ("pirate");
  set_brief("�ʻ���Ѩ");
  set_long("���ڵĺ��˳������Ѩ����ڣ�"
           "��Ȼ�����һЩͼ������ˮ��٣������Ծ������쳣��"
           "�����Ĺ������������Ѩ�������޷��ֱ�����������⻹���¹⡣"
           "��ֻ����ǿ���Ա��ϳ��Ǳ���ǽ���������İ����ڡ�");
  set_exits( ([
               "south" : "../beach/outside_cave.c",
               "out" : "../beach/outside_cave.c",
               "north" : "low_crawl.c"
               ]) );
  set_hidden_exits("south");
  set_default_exit( "�������û�г��ڡ�\n");

  set_objects( ([
                 "/domains/std/objects/dead_adventurer" : 1,
              "/domains/std/monsters/troll" :1,
                 ]) );

  add_item( "cave", "paint", "paintings", "grotto", "�ʻ�", "ͼ��",
           "��Щͼ���������������ģ����˲����ľ�������");

  add_item( "light", "����", "�ƺ��Ǵ������ս����ġ�" );
  add_item( "moonlight", "�¹�", "���޷��϶������¹⡣" );
  add_item( "sunlight",  "����", "���޷��϶��������⡣");
  add_item( "crawl", "low crawl", "������", "����", "���ڱ��档" );

  add_item( "waves", "water" , "����", "��ˮ",
           ([
             "look" : "ֻ��������ͨ��ˮ��",
             "wade" : "�ǲ������˷�ʱ�䡣",
             "swim" : "��Щˮ̫ǳ�ˡ�",
             ]));
  
}


