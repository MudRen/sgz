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
    set_brief(""+HIW+"侯府大门"+NOR+"");
    set_long(
"你正站在一座豪华的府门前，两头高大的石狮子镇住了大门两侧，大门上的朱
漆足足有三寸厚。门上高悬一块横匾，上书「都亭侯府」四个金字。门口站着
两排侍卫，身着锦衣，手握长戟，气宇轩昂。。");


    set_exits( (["enter" : "/wiz/nono/fuyuan.c",
                  ]) );              
}
