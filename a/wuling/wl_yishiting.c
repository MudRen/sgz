// this room is created by buzzer.c
// driver is 巴山夜雨
// created date is Sat May 28 19:51:24 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"议事厅"+"%^RESET%^");
set_long("
    这里是武陵议事厅,中间摆着一张长桌,两旁摆着几张凳子。
这里是太守日常处理政务的地方，这里进出的都是儒雅的文官和
威武的将军，他们带着忧国忧民，统一天下的抱负聚集到一起。
门口站着两个官兵，防止闲杂人等骚扰村长。\n\n");
set_exits( ([
"east":"/a/wuling/wl_xiaolu1.c",

"south":"/a/wuling/wl_dadao2.c",
 ]));
}
