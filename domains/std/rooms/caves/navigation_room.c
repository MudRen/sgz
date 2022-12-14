// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit ROOM;

int passage_open = 0;

void close_passage();

void setup() 
{
  set_area("pirate");
  set_brief("导航室");

  set_long("这里的墙面上画着一幅七大洋的航海图，上面标记着一些航行的路线，"
           "洞顶上刻着星空图，室内正中央摆着一张小木桌。");
  set_light(0);
  set_exits( ([
               ]) );
  set_hidden_exits();
  add_item("ceiling", "stars" , "洞顶", "星空图",
           "这是一幅用于航海的星座图。");
  add_item("legs","leg", "桌腿", "桌腿没有什么特殊的地方。");
  add_item("surface", "桌面", "桌面没有什么特殊的地方。");
  add_item("passage", "outline", "通道", "通道没有什么特殊的地方。");
  add_item("maps", "航海图", 
           ([ "look" : "航海图上写着许多潦草的字迹。",
            "get" : "这航海图是刻在墙上的，你拿不下来。" ]));

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
  this_body()->simple_action("北面的岩墙摇晃着向一旁滑开，露出一个通道。");
  o = load_object("/domains/std/rooms/caves/small_dock.c");
  add_exit("north" , "/domains/std/rooms/caves/small_dock.c");
  o->passage_opened();
  call_out((:close_passage:), 3);
  passage_open = 1;
}

void passage_opened()
{
    receive_inside_msg("北面的岩墙摇晃着向一旁滑开，露出一个通道。\n");
    add_exit("north" , "/domains/std/rooms/caves/small_dock.c");
    passage_open = 1;
}


void close_passage()
{
  object o = load_object("/domains/std/rooms/caves/small_dock.c");
  o->passage_closed();
  delete_exit("north");
  receive_inside_msg("岩石滑了回去，墙面把通道又档住了。\n");
  passage_open = 0;
}

void passage_closed()
{
  delete_exit("north");
  receive_inside_msg("岩石滑了回去，墙面把通道又档住了。\n");
  passage_open = 0;
}
