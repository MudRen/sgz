// this room is created by buzzer.c
// driver is �������
// created date is Sat May  7 13:52:43 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"��Ӫ"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/longxi/lx_xiaochang.c",

"north":"/a/longxi/lx_qianmendajie3.c",
 ]));
}
