// this room is created by buzzer.c
// driver is 巴山夜雨
// created date is Sat May 28 19:45:34 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"村中心"+"%^RESET%^");
set_long("
    这里是武陵的村中心,东面通向武陵北街,北面通向
校场,南面通向武陵点将台,西面是大道。\n\n");
set_exits( ([
"east":"/a/wuling/wl_beijie1.c",

"north":"/a/wuling/wl_xiaochang.c",

"south":"/a/wuling/wl_dianjiangtai.c",

"west":"/a/wuling/wl_dadao2.c",
 ]));
}
