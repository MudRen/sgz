/* tg_c2.c
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
上行人稀少，半天也见不到一两个。北边是潼关驻军议事的中军帐。
南边是军营。往东边走是潼关关口。从此再向西，就到华阴县了。\n"
);
    set_exits( ([
HIG+"west" :  "",
"east" :  "tg_c1.c",
"north" :  "tg_zjz.c",
"south" :  "tg_jy.c"+NOR
    ]) );
    set_objects( ([
    ]) );
}
