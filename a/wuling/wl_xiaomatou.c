// this room is created by buzzer.c
// driver is 巴山夜雨
// created date is Sat May 28 19:52:18 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"小码头"+"%^RESET%^");
set_long("
    这里是武陵的小码头,有几艘小鱼船停在码头边上,正
在叫卖今天刚捕的水产。\n\n");
set_exits( ([
"south":"/a/wuling/wl_xiaolu1.c",
 ]));
}
