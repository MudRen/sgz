/* tg_jg.c
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
    set_brief(HIY+"酒馆"+NOR);
    set_long(
"    这是一间小酒馆。门外的幌子上写着一个大大的“酒”字。门口
立着一个牌子(pai zi)。进门左手边墙上挂着一幅对联：“店小名气
大  老酒醉人多”。虽是乡下人写的，到也有几分才气。\n"
);
    add_item("pai zi" , "明日开张，届时敬请光临！\n");
    set_exits( ([
HIG+"north"+NOR :  "tg_c1.c"
    ]) );
    set_objects( ([
    ]) );
}
