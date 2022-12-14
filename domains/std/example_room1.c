// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
/*                                                             */
/*   This is an example room for the lima mudlib          */
/*                                                             */
/*   Created by zifnab@lima bean 7/24/95                         */
/*                                                             */
/****************************************************************/

#include <mudlib.h>
inherit ROOM;

mixed can_go_east()
{
    object env = environment( this_body());
    if( env->is_vehicle() && member_array( "car", env->query_id()) != -1)
    {
        return 1;
    }
    return "你可能乘坐一辆车来更好一些。\n";
}


void setup(){
    set_area("wiz_area");
    set_brief("样品房间");
 
    set_long("这是一个 lima mudlib 的样品房间。西南角有一个废弃的盔甲，西面有一个拱门通向巫师大厅。不知是何故，东边有一个洗车厂。\n"); 
 
    set_exits( ([
        "west" : "wizroom",
        "south" : "room2",
        "north" : "/domains/std/rooms/v_plains/4/7",
        "east" : "/domains/std/car_wash.c",
    ]) );
    set_exit_msg("east", "当你进入洗车场时，水笼头开始冲洗车的底盘。\n");
 
    add_item( "suit" , "armor" , "suit of armor" , "这件铠甲又破又旧，当你凝视它的时候，你的耳中似乎响起了战场厮杀的声音。");

    set_objects ( ([
                    "/domains/std/safe.c" : 1 
                    ]));
}

