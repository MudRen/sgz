/* RoomMaker.c
** Coded by 苑璧@LIMA
** Code generated with RoomMaker v0.9.1 coded by Onyx@RedDragon
** Do not remove this header.
*/

#include <mudlib.h>
#include <ansi.h>

inherit ROOM;

void setup(){
    set_area("huayin");
    set_light(50);
    set_brief("%^H_MAGENTA%^苑璧的会客厅%^RESET%^");
    set_long("  
室内东西一大堆，地上摊了一堆杂物，走起路来真麻烦！
桌子上放了些闲书，显然主人是没事干找事干。还是帮主人理理东西吧。
窗外风景倒是不错，可惜你出不去。窗边钉着一张字条：要找主人的话，
请 mail tset 。
\n\n");
    set_exits( ([
        "out" :  FROOMPATH+"vzhu_lin.c",
        "zatan" : __DIR__+"chatroom.c", 
    ]) );
}
