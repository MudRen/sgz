#include <mudlib.h>
#include <ansi.h>
#include <sanguo.h>

inherit ROOM;
void setup(){
    set_area("liz_room");
    set_light(50);
    set_brief(""+HIR+"等明天"+NOR+"的"+HIG+"家"+NOR+"");
    set_long(
"\n 幽人归独卧,滞虑洗孤清,持此谢高鸟,因之传远情,
日夕怀空意,人谁感至精,飞沈理自隔,何所慰吾诚. \n
等明天大概是世界上最懒的人了， 
什么事情都明天 再说吧！ :) \n
面包会有的，房子刚找到，该买车了! \n");    set_exits((["out" :  FROOMPATH+"vzhu_lin.c",]) );              
    set_objects (([ "/wiz/shaoyng/npc/jiangwei.c" : 1 ]));
}

