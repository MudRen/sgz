//都亭侯侯府

#include <mudlib.h>
#include <ansi.h>
#include <sanguo.h>

inherit ROOM;

void setup()
{
    set_area("nono_room");
    set_light(50);
    set_brief(""+HIW+"大厅 "+NOR+"");
    set_long(

"进入堂，堂上东西有两根楹住，挂着一幅对联，但是你无心细看。正墙上悬挂一个横
匾，上面写著斗大字「忠」。厅中摆着一张杉木圆桌和几张椅子，桌上是一套精致的
宜兴瓷器。右侧挂着一幅中堂，画的是猛虎下山，乃是都侯的手笔。西边不远则是书
房。");
    set_exits( (["up" : FROOMPATH+"vzhu_lin.c", 
                 "west" : "/wiz/nono/shufang.c",
 "out" : "/wiz/nono/fuyuan.c",
             ]) );

}
