// this room is created by buzzer.c
// driver is 巴山夜雨
// created date is Sat May 28 19:30:30 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"茶馆"+"%^RESET%^");
set_long("
    这里是武陵茶馆,你一走进来，就闻到一股茶香沁入心脾，精
神为之一爽。 几张八仙桌一字排开，坐满了客人，或高声谈笑，
或交头接耳。店小二提着大茶壶四处走动招呼客人。\n\n");
set_exits( ([ 
"east":"/a/wuling/wl_xiaoxiang.c",
 ]));
}
