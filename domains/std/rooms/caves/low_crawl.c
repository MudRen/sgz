// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <size.h>
inherit ROOM;

void setup()
{
    set_area("pirate");
    set_brief("����");
    set_long(
      "������ֽŲ��ò����������ͨ������ʹ��������ı��������붴��"
      "��������ʯ�������߲������£���ʹ���ƶ������ѡ����ı����Կ�"
      "�����Ϸ�����һ����ʪ�ķ紵��������ϡ�");
    set_light(0);
    set_exits( ([
      "south" : "/domains/std/rooms/caves/grotto.c",
   "north" : "/domains/std/rooms/caves/inside_cave.c",
    ]) );
    set_default_exit( "�������û�г��ڡ�\n");

    add_item( "crawl", "low crawl" , "ͨ��", "����", 
              "��ת��ͷȥ���������￴���������и������ʯ���£����æ�������ۡ�");

    add_item( "ceiling" , "����", "�������û����̧ͷ���Ͽ��Ŀռ䡣");

    add_item( "rock", "rocks", "gravel", "rocks and gravel", "��ʯ", 
              ([ "look" : "��ʯ���Ϸ����£��ѻ��ڵ��ϣ�ʹ�õ��������ƽ��",
                 "get" : "����̫��С�ˣ�����û��ʲô�ô���" 
               ]));

    set_max_capacity(VERY_LARGE+3*MEDIUM); // A person + 3 medium items
}



