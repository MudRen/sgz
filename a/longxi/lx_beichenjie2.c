// this room is created by buzzer.c
// driver is �������
// created date is Sat May  7 14:31:49 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"��巽�"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/longxi/lx_xiangguan.c",

"north":"/a/longxi/lx_beichenjie3.c",

"south":"/a/longxi/lx_beichenjie1.c",
 ]));
}
