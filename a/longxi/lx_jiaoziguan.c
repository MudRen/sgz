// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sat May  7 14:35:05 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
inherit STORE;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"饺子馆"+"%^RESET%^");
set_long("
    这里是陇西饺子馆,几张饭桌现在都空着,店就在林下,靠
近大路,左手两间瓦屋,右首空地上搭了一个松棚,放上四五张桌板凳,如
此而已,小店没有招牌,只在松林前面挑着一个'饺子'字的布帘.\n\n");
set_exits( ([
"west":"/a/longxi/lx_beichenjie1.c",
 ]));
set_objects( (["/sgdomain/obj/other/null.c" : 1]) );
add_object("/sgdomain/obj/foodanddrink/mantou.c");
add_object("/sgdomain/obj/foodanddrink/shuihu.c");
}
