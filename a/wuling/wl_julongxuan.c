// this room is created by buzzer.c
// driver is 巴山夜雨
// created date is Sat May 28 20:00:26 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"聚龙轩"+"%^RESET%^");
set_long("
    这里是武陵的聚龙轩,主要经营文房四宝,一些学子在
店里走来走去。\n\n");
set_exits( ([
"west":"/a/wuling/wl_beijie3.c",
 ]));
}
