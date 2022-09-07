#include <ansi.h>

inherit INDOOR_ROOM;

void setup(){
    set_area("westside");
    set_light(50);
          set_brief(""+YEL+"飘雪的休息室"+NOR+"");
    set_long("
      这里是飘雪的休息室，陈设比较简单，但朴素中显出一种高贵的气质。
进入这里时，不由使你由然产生一种崇敬的感觉。对了，忘记告诉你了，
飘雪不喜欢人打拢他的，你最好能早点出去，要不他发现了，可能会杀了
你的。小心点好。
\n\n"
);
    set_exits( ([
              "east" : "/wiz/ghyg/workroom.c",
            "west" : "/a/huayin/venter.c",
    ]) );
    set_objects( ([
//   __DIR__"npc/piaox.c":1,
      ]) );
}
