#include <ansi.h>
inherit INDOOR_ROOM;
void setup()
{
   set_light(50);
   set_brief(""+YEL+"长廊"+NOR+"");
   set_long("
    这里是金銮殿东侧的长廊，两侧种满了花草，几个小宫女正在扑
蝶，银铃般的笑声引得你不由自主地缓下脚步，站在一旁暗暗欣赏。
远处隐约传来一些乐声，不知道后宫是哪位妃嫔又在抚琴自娱了，你
不由得心驰神往起来。

");
   set_exits( ([
             "west" : __DIR__+"cl4",
	     "north" : __DIR__+"cl6",
        ]) );
}
