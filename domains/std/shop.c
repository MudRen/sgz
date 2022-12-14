// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit ROOM;

void setup()
{
set_area("wiz_area");
    set_brief("便利店");
    set_long(
        "这里是便利店。玩家到这里来售卖他们探险的战利品和购买所需的东西。\n"
        "墙上贴着一个告示(sign)。\n"
        );

    add_item("sign", ([
"look" : "请向 biff 打听 (swords, keys, etc),\n"
         "  朝 biff 购买 (sword or sword #)\n"          
         "  向 biff 出售 (sword, first sword etc)\n",
"read" : "请向 biff 打听 (swords, keys, etc),\n"
         "  朝 biff 购买 (sword or sword #)\n"
                  "  向 biff 出售 (sword, first sword etc)\n",
        ]) );
    set_objects( (["/domains/std/shopkeeper.c" :1,
        STAIRS : ({ 1, "/domains/std/wizroom" }),
        ]) );

    set_exits( ([ "up" : "wizroom" ]) );
}
