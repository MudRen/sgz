/* tg_jy.c
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
    set_brief(YEL+"军营"+NOR);
    set_long(
"    这里是潼关守关官兵住宿操练的地方。\n"
);
    set_exits( ([
HIG+"north"+NOR :  "tg_c2.c"
    ]) );
    set_objects( ([
    ]) );
}
