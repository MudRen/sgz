// this room is created by buzzer.c
// driver is �������
// created date is Sun May 29 19:31:48 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("qiao");
set_light(50);
set_brief("%^YELLOW%^"+"ʯ����"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/qiao/q_xidadao.c",

"southeast":"/a/qiao/q_caishikou.c",

"northeast":"/a/qiao/q_xiaochang.c",
 ]));
}
