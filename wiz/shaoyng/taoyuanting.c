#include <mudlib.h>
#include <ansi.h>
#include <sanguo.h>
inherit ROOM;
void setup()
{
    set_area("xbv_area");
    set_light(50);
    set_brief(""+HIR+"猪香庄"+HIY+"桃源厅"+NOR+"");
    set_long("
大厅上  姜母正用大白兔奶糖逗弄着猪小星。\n
流星的光芒虽短促，但天上还有什么星能比它更灿烂，辉煌？
当流星出现的时候，就算是永恒不变的星座，也夺不去它的光芒。\n
无所事事的魏延心中的苦恼，又会有谁知道呢？\n\n");
    set_exits ((["out" :  "/wiz/shaoyng/workroom.c"]) );
    set_objects (([ "/wiz/shaoyng/npc/weiyan.c" : 1 ]));
}                             

