// this room is created by buzzer.c
// driver is �������
// created date is Sun May 29 20:43:34 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("qiao");
set_light(50);
set_brief("%^YELLOW%^"+"�����"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/qiao/q_changting.c",

"east":"/a/qiao/q_dongchengmen.c",

"south":"/a/qiao/q_qianzhuang.c",

]));
}
