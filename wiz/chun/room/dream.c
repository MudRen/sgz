//wiz/chun/room/dream.c
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup(){
  set_area("westside");
  set_light(80);
  set_brief(""+HIC+"奇香葩"+NOR+"");
  set_long("
  这是一个种满了奇花异草雅至的小小花园，散发着让人陶醉的异香．
这么美丽的地方，应该，只有在梦境中才有吧．．．\n\n");
  set_objects( ([
  "/wiz/chun/roses.c":1,
  ]) );
  set_exits( ([
        "enter" : "/wiz/chun/workroom.c",
  ]));
};

