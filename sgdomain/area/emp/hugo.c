//by ljty.
#include <mudlib.h>
#include <sanguo.h>
#include <ansi.h>

inherit ROOM;

void setup()
{
   set_light(50);
   set_brief(""+YEL+"皇宫入口"+NOR+"");
   set_long("
    这里是金銮殿前的一片空地，面前是一道通往殿门的白玉台阶，
上面精雕细刻的是象征天子之姿的神龙。一批高大威猛的御林军正
五步一隔地守卫在四周，吓得你大气也不敢喘，低着头快步走了过
去。从这里出去通往长安驿站和长安城中心。
\n\n");
   set_exits( ([
             "dadian" : __DIR__+"dadi.c",
             "goout" : "/a/changan/ca_czx.c",
	]) );
    set_exit_msg("goout","\n$N在御前侍卫的护送之下，回到了长安城中心。\n\n");
}
