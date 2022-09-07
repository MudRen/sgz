#include <mudlib.h>
#include <ansi.h>
#include <sanguo.h>

inherit ROOM;

private mapping exits;

void bind_exit(string direction, object room, int both);
void setexits();


void setup()
{
    set_area("nono_room");
    set_light(50);
    set_brief(""+HIW+"书房"+NOR+"");
    set_long(
"这里是侯府西厅，乃是都侯的书房。书案上凌乱地放着几本发黄的古籍。并十
数方宝砚，各色笔筒，笔海内插的笔如树林一般那一边设著斗大的一个汝窑花
囊，插著满满的水晶球的白菊花。引起你的注意的却是墙上悬挂着的那把剑。");


    set_exits( (["east" : "/wiz/nono/workroom.c",
                  ]) );              
}


