// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
inherit ROOM;

void setup(){
set_area("wiz_area");
    set_brief("静修室");
    set_long("这里是静室，也是争论、吵架的发源地。");
    set_exits( ([
		 "east" : "wizroom.c"
    ]) );
    set_objects( ([
		   "/domains/std/large_oak_door" : ({ "east" }),
		   ]));
}


