// this room is created by buzzer.c
// driver is 花儿朵朵
// created date is Sat May  7 13:45:33 2011
#include <mudlib.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"前门大街"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/longxi/lx_beichenjie1.c",

"east":"/a/longxi/lx_dongchengmen.c",

"west":"/a/longxi/lx_qianmendajie2.c",

"south":"/a/longxi/lx_dounanjie1.c",
 ]));
set_objects(([M_BOARD : ({ 1,"十字路口来往的车马络绎不绝，显出了凉州中心城市的繁华。\n\n路边张贴着"+"%^MAGENTA%^"+"陇西留言榜"+"%^RESET%^", "city.longxi" }) ]) );
}
