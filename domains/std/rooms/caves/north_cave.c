// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit ROOM;


void setup()
{
    set_area("pirate");
    set_brief( "北岩洞" );

    set_long ("这里是洞穴的北面，一条东西向的小河从南方川流而过。东西两面的岩壁朝中间挤压过来，似乎有什么不祥的预兆。");

    set_objects( (["/domains/std/objects/gate": ({ "north" })]) );

    add_item("wall", "这里的岩石是很普通的一种，没有什么特别的。");
    set_exits( ([
        "north" : "/domains/std/rooms/caves/north_tunnel.c",
        "south" : "/domains/std/rooms/caves/inside_cave.c",
        ]) );

    set_state_description("gate_open_off", "北面的一个生满锈的铁门似乎挡住了地道的入口。\n");

    set_state_description("gate_open_on", "北面的一个生锈的铁门，门正开着，露出了一个地道的入口。\n");
}
