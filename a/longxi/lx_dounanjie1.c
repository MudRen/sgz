// this room is created by buzzer.c
// driver is �������
// created date is Sat May  7 12:14:39 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"���Ͻ�"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/longxi/lx_qianmendajie1.c",

"south":"/a/longxi/lx_dounanjie2.c",

"west":"/a/longxi/lx_cangku.c",

"east":"/a/longxi/tmp.c",
 ]));
}
