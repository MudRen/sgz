/* tg_gk.c
** Coded by 和风@三国志
** Code generated with RoomMaker v0.9.1 coded by Onyx@RedDragon
** Do not remove this header.
*/

#include <mudlib.h>
#include </wiz/fire/fire.h>
#include <ansi.h>

inherit ROOM;

void setup(){
   set_area("tongguan");
    set_light(1);
    set_brief(YEL+"潼关关口"+NOR);
    set_long(
"   这里就是潼关的关口。潼关是著名的关隘重地，因其南倚秦岭，
有十二连城禁锢诸谷之险：北带渭、洛，会黄河抱关而下之要；东、
南山峰连接，谷深崖绝；中通羊肠小道，仅容一车一骑，人行其间，
仰视悬崖，俯察洪流，险恶峻极。"

);
    set_exits( ([
HIG+"home" :  "wiz/softwind/workroom.c",
"west"+NOR : "/wiz/softwind/tg_c1.c"
    ]) );
    set_objects( ([
    ]) );
}
