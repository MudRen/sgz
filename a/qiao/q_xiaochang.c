// this room is created by buzzer.c
// driver is �������
// created date is Sun May 29 20:47:46 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("qiao");
set_light(50);
set_brief("%^YELLOW%^"+"У��"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/qiao/q_beidajie.c",

"east":"/a/qiao/q_bingying.c",

"west":"/a/qiao/q_yishiting.c",

"southeast":"/a/qiao/q_changting.c",

"southwest":"/a/qiao/q_shigongqiao.c",
 ]));
}
