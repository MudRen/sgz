/* workroom.c
** Coded by 玄冰@三国
** Code generated with RoomMaker v0.9.1 coded by Onyx@RedDragon
** Do not remove this header.
*/
#include <ansi.h>

inherit INDOOR_ROOM;
static string * nogo = ({
"\n$N抬脚想往里走去，犹豫了一下，又放弃了。\n\n",
"\n屋子里洋溢着一股懒洋洋的气氛，$N连动都懒得动了。\n\n",
});
string * going = ({ "飞一般","头也不回","一鼓作气", });
int do_go_backdoor() {
    object r;
    if( !wizardp(this_body()) ) {
        this_body()->simple_action(nogo[random(sizeof(nogo))]+"\n");
        return 1;
    }
    r = load_object(query_exits()[query_exit_directions(1)[random(sizeof(query_exit_directions(1)))]]);
    this_body()->simple_action("\n$N"+going[random(sizeof(going))]+
        "地向后门冲去，结果。。。。\n\n");
    this_body()->move(r);
    tell_environment(this_body(), sprintf("\n%s失魂落魄地走了过来。\n\n",
        this_body()->short()), 0, ({ this_body() }) );
    this_body()->force_look();
    return 1;
}

void setup(){
    set_area("westside");
    set_light(50);
        set_brief(""+YEL+"小白的工作室"+NOR+"");
    set_long("
    一桌，一椅，一沙发。
\n\n"
);
    set_exits( ([
        "goout" : "/sgdomain/museum/yard.c",
        "fire" : "/wiz/fire/workroom.c",
        "row" : "/wiz/row/workroom.c",
        "suicide" : "/wiz/suicide/workroom.c",
        "ice" : "/wiz/ice/workroom.c",
        "palace" : "/sgdomain/area/emp/dadi.c",
        "bwdh" : "/sgdomain/event/ev_bwdh/bw_room.c",
        "caolu" : "/a/huayin/vhall.c",
        "luoyang" : "/a/luoyang/ly_ly.c",
    ]) );
    set_hidden_exits("fire", "row", "suicide", "ice", "bwdh", "palace", "caolu", "luoyang");
    set_enter_msg("house","\n$N推开门，蹑手蹑脚地走了进来。\n\n");
    set_enter_msg("goup","\n$N惊惶失措地从呆呆屋逃了出来。\n\n");
    set_objects( ([
__DIR__"npc/newslady.c":1,
    ]) );
}
