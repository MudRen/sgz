/* ground.c
** Coded by 玄冰@三国
** Code generated with RoomMaker v0.9.1 coded by Onyx@RedDragon
** Do not remove this header.
*/
#include <ansi.h>

inherit OUTDOOR_ROOM;

void setup(){
    set_light(50);
    set_area("westside");
        set_brief(""+YEL+"空地"+NOR+"");
    set_long("
    小木屋门前的一小片空地，周围一片静谧，耳边传来「淙淙」的
小河流水声，以及偶尔几声不合时宜的乌鸦叫声。面前是一条宽不过
两丈的小河，一座小木桥横亘其上。木屋的周围种着些柏树，看样子
也已届高龄了。门前还有一张油漆已经斑驳的桌子，以及几张椅子，
经年累月的日晒雨淋，原先完好的桌椅都已经出现了一丝丝的裂纹。

%^H_BLUE%^天色似乎已近黄昏，天边的晚霞一片火红。%^RESET%^
\n\n"
);
    add_item("duilian", "对联",
        ([ "look" : "

          落        秋
          霞        水
          与        共
          孤        长
          鹭        天
          齐        一
          飞        色

\n\n",
        ]));
    set_exits( ([
        "house" : __DIR__+"workroom.c",
        "bridge" : __DIR__+"bridge.c",
    ]));
    set_enter_msg("goout","\n只听见木门「吱呀」一声，$N走了出来。\n\n");
    set_objects( ([
        __DIR__"bridge" : 1,
    ]) );
}
