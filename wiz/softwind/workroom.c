/* workroom.c
** Coded by 和风@三国志
** Code generated with RoomMaker v0.9.1 coded by Onyx@RedDragon
** Do not remove this header.
*/

#include <ansi.h>
#include <mudlib.h>
#include </wiz/fire/fire.h>

inherit ROOM;

void setup(){
    set_light(1);
    set_brief(HIC+"和风"+NOR+"的工作间");
    set_long(
"    这里是"+HIC+"和风"+NOR+"的工作间。看起来乱乱的。可能是工作太忙，没时
间收拾。

"
);
    set_exits( ([
HIG+"out"+NOR :  "tg_gk.c"
    ]) );
    set_objects( ([
    ]) );
}
