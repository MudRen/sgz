// this room is created by buzzer.c
// driver is �������
// created date is Sat May  7 14:36:47 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"Ϸ��"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/longxi/lx_beichenjie3.c",
 ]));
}
