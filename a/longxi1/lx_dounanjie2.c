// this room is created by buzzer.c
// driver is �������
// created date is Sat May  7 12:16:15 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"���Ͻ�"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/longxi/lx_dounanjie3.c",

"east":"/a/longxi/lx_budaochang.c",

"west":"/a/longxi/lx_dianxinpu.c",

"north":"/a/longxi/lx_dounanjie1.c",
 ]));
}
