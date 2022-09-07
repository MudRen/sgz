/* RoomMaker.c
**Coded by 彩云深处
** Do not remove this header.
*/

#include <mudlib.h>
#include <ansi.h>
#include <sanguo.h>

inherit ROOM;

void setup(){
    set_area("xbv_area");
    set_light(50);
    set_brief(YEL+"彩云深处的工作室"+NOR);
    set_long("  
这里空空如野，什么也没有!
云彩到处飘荡，小心别弄湿了衣裳
桌子上放了些闲书,翻翻看，就是些三国演义之类的。

窗外风景倒是不错，可惜你出不去。窗边钉着一张字条：要找主人的话，
Please mail to net.
\n\n");
    set_exits( ([
        "out" :  FROOMPATH+"vzhu_lin.c",
        "fire" :"/wiz/fire/workroom.c"
    ]) );
}
