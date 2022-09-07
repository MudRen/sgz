// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit OUTDOOR_ROOM;


void
setup()
{
    string m = "�����ɽ�ڹ��ڶ��ͣ����޷��ʵǣ�Ҫ��·���ܹ���\n";
    string o = "��ᱻ�����ģ�\n";
  set_brief("ʯ̲");
  set_area ("pirate");
  set_long("����û�ж���ɳ���෴�������Ǵ��СС����ʯ��ʯ�ѡ�Ⱥɽ��"
           "�����Χ���㣬���������ˮ�뿪���");
  set_exits( ([
               "west" : m,
               "northeast" :  m,
               "northwest" :  m,
               "north" : m,
               "east" : m,
               "south" : o,
               "southeast" : o,
               "southwest" : o,
               ]) );

  add_item("mountains", "steep mountains", "Ⱥɽ",
           ([
             "look" : "������±�̫�����ˣ��޷��ʵǡ�",
             "climb" : "������±�̫�����ˣ��޷��ʵǡ�"
             ]));

  add_item( "sand", "beach", "ɳ̲", "ɳ��", "�˴�ɳ���࣬ʯͷ�����١�");
               
  set_hidden_exits("northeast","northwest","south","southeast","southwest", 
                   "north", "east", "west");
  set_objects( ([
                 "/domains/std/objects/ocean" : 1,
                 "/domains/std/objects/debris" : 1,
                 ]));
}


mixed wade(string str)
{
  if(!str)
    {
      str = "water";
      write("[��ˮ��]\n");
    }
  switch(str)
    {
    case "water":
    case "waves":
    case "surf":
    case "ocean":
      write ("���ں��а��棬�ֻص����Ҷ���ڡ�\n\n"); 
      this_body()->other_action("$N��ˮ�뿪�ˡ�\n");
      this_body()->move(__DIR__ "outside_cave");
      this_body()->do_game_command("look");
      this_body()->other_action("$N����ˮ����������˹�����\n");
      return 1;
    default:
      return "���޴����뷨��!\n";
    }
}

