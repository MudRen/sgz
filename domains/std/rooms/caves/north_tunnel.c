// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit ROOM;

void setup()
{
    set_area("pirate");
    set_brief("北地道");
    set_long("这条地下通道从岩洞一直向北，通向远处。");

    set_objects( (["/domains/std/objects/gate.c":  ({ "south" }) ]) );

    set_exits( ([
        "south" : "/domains/std/rooms/caves/north_cave.c"
        ]) );

    set_state_description("gate_open_off", "南面是一道生锈了的铁门，它正关着。");
    set_state_description("gate_open_on", " \n南面是一道生锈了的铁门，门正斜开着。");
}
