// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
inherit NON_ROOM;

void setup(){
    set_area("wiz_area");
    set_brief("怪兽屋");
    set_long("这里是怪兽屋，是巫师夸耀各自的宠物的场所。北方过去是大厅。");
    set_exits( ([
                 "north" : "wizroom.c"
    ]) );
    set_objects(([ "/domains/std/guild_guard" : ({ "stock-mage" }) ]));
}


