// this room is created by buzzer.c
// driver is �������
// created date is Tue Jul 19 09:30:30 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("changbanpo");
set_light(50);
set_brief("%^YELLOW%^"+"����"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/changbanpo/cbp_changbanqiao.c",

"south":"/a/changbanpo/cbp_linjianxiaodao.c",

"east":"/a/changbanpo/cbp_yingzhai.c",

"west":"/a/changbanpo/tmp.c",
 ]));
}
