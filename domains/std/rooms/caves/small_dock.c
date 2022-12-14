// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit ROOM;

private static int passage_open = 0;

void close_passage();
void open_passage();

void setup() 
{ 
  string river = "你会被河水淹死的。";

  set_area("pirate");
  set_brief("小船坞");
  set_long("河水从岩洞的南面流入，流向东面的出口。这里有一个用木头搭建的小"
           "船坞，木质早已腐烂了，象是一个秘密的码头。");
  
  set_light(0);
  set_exits( ([
               "north" : river,
               "east" : river,
               "northeast" : river,
               "northwest" : "inside_cave",
               ]) );

  set_exit_msg("south", "$N弯下腰，从河水入口走了出去。\n");

  set_hidden_exits("north","east", "northeast");
  set_default_exit ("这个方向没有出口。\n");
  add_item("door", "outline", 
           ([ 
             "look" :  "这个轮廓很模糊，你看了看，觉得不太可能从这边把它打开。", 
             "open" : "从这边不太可能把它打开。"
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
  receive_inside_msg("通道慢慢关上了。\n");
  passage_open = 0;
}

void passage_closed()
{
  delete_exit("south");
  receive_inside_msg("通道关上了。\n");
  passage_open = 1;
}

void open_passage()
{
  object o;

  if(passage_open)
    {
      return;
    }
  this_body()->simple_action("碑铭下方的石头突然向一旁滑开，露出一个通道。");
  QUEST_D->grant_points(this_body(),"pirate:secretPsg");
  o = load_object("/domains/std/rooms/caves/navigation_room.c");
  add_exit("south" , "/domains/std/rooms/caves/navigation_room.c");
  o->passage_opened();
  call_out((:close_passage:),6);
  passage_open = 1;
}

void passage_opened()
{
    receive_inside_msg("碑铭下方的石头突然向一旁滑开，露出一个通道。\n");
  add_exit("south" , "/domains/std/rooms/caves/navigation_room.c");
  passage_open = 1;
}
