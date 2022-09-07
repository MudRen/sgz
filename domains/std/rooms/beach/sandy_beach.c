// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit OUTDOOR_ROOM;

void setup()
{
    string m = "�����ɽ�ڹ��ڶ��ͣ����޷��ʵǣ�Ҫ��·���ܹ���";
    string o = "��ᱻ�����ģ�\n";
  set_brief("ɳ̲");
  set_area ("pirate");
  set_long("��ˮ������Ĵ���ɳ����һ�Ե�ɽ��ֱ����չ���˺��û�пɹ�������ɳ̲��"); 
  set_exits( ([
               "northeast" :  m,
               "northwest" :  m,
               "north" : m,
               "west" : m,
               "east" : m,
               "south" : o,
               "southeast" : o,
               "southwest" : o,
               ]) );


  add_item( "tide", "��ˮ", "����ĳ�ˮҲ������������Ȼ�������������������У���������о���");

  add_item("mountains", "ɽ��",
           ([
             "adjs" : "���͵�", // Can also use an array...
             "look" : "������±�̫�����ˣ��޷��ʵǡ�",
             "climb" : "������±�̫�����ˣ��޷��ʵǡ�" 
             ]));
               
  set_hidden_exits("northeast","northwest","south","southeast","southwest", 
                   "north", "west", "east");
  set_objects( ([
                 "/domains/std/objects/sand_castle" : 1,
                 "/domains/std/objects/sand_with_treasure" : 1,
                 "/domains/std/objects/welcome_sign" : 1,
                 "/domains/std/objects/ocean" : 1,

  ]) );
}

mixed wade(string str)
{
  switch(str)
    {
    case 0:
      write("[��ˮ��]\n");
    case "water":
    case "waves":
    case "surf":
    case "ocean":
      write ( "�����뺣ˮ�У�ˮ�׵İ�����ǿ�����㻹�Ǳ�����ƽ�⡣\n"
              "�㳯������ȥ���Ǳ�û��ʲôɳ̲��������ɽ����ȥ�ƺ��е���˼��\n");
      this_body()->other_action("$N��ˮ������һ������ͳ�����ȥ�ˣ��뿪��������ߡ�");
      this_body()->move(__DIR__ "outside_cave");
      QUEST_D->grant_points(this_body(),"pirate:foundCave");
      this_body()->do_game_command("look");
      this_body()->other_action("$N���ź�ˮ���������������\n");
      return 1;
    default:
      return "���޴����뷨��!\n";
    }
}

