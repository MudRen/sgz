// this room is created by buzzer.c
// driver is °¢Âå
// created date is Wed May 19 10:31:28 1999
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("changan");
set_light(50);
set_brief("%^YELLOW%^"+"ÇÞ¹¬"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/sgdomain/area/cities/changan/ca_hg.c",
 ]));
set_objects( ([
        "/sgdomain/event/ev_king/king.c" : 1,
]));
}
