// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sat May 28 19:41:46 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"�Ͻ�"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/wuling/wl_xiaowu.c",

"south":"/a/wuling/wl_nanjie1.c",

"north":"/a/wuling/wl_beijie1.c",

 ]));
}
