// this room is created by buzzer.c
// driver is �������
// created date is Sat May  7 14:34:23 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"��巽�"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/longxi/lx_xiaoxiang1.c",

"north":"/a/longxi/lx_xipeng.c",

"east":"/a/longxi/lx_kedian.c",

"south":"/a/longxi/lx_beichenjie2.c",
 ]));
}
