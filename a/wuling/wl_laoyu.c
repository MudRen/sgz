// this room is created by buzzer.c
// driver is 巴山夜雨
// created date is Sat May 28 19:26:32 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"牢狱"+"%^RESET%^");
set_long("
    这里是武陵牢狱,关押犯人的地方。\n\n");
set_exits( ([
"south":"/a/wuling/wl_yamen.c",
 ]));
}
