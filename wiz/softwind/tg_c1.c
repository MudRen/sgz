/* tg_c1.c
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
    set_brief(YEL+"潼关街上"+NOR);
    set_long(
"    这里就已经进入潼关了。从关口进来，就只有这么一条小街。街
上行人稀少，半天也见不到一两个。南边有一个客栈。因为潼关地处
险峻，道路难行，过路人都在此过夜。往东边走是潼关关口。从此再
向西，就到华阴县了。\n"
);
    set_exits( ([
HIG+"west" :  "tg_c2.c",
"east" :  "tg_gk.c",
"south"+NOR :  "tg_jg.c"
    ]) );
    set_objects( ([
    ]) );
}
