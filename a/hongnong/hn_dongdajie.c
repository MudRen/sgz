// this room is created by buzzer.c
// driver is �������
// created date is Wed Jun 15 20:12:48 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("hongnong");
set_light(50);
set_brief("%^YELLOW%^"+"�����"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/hongnong/hn_juhuisuo.c",

"south":"/a/hongnong/hn_datang.c",

"east":"/a/hongnong/hn_dongchengmen.c",

"west":"/a/hongnong/hn_chengzhongxin.c",
 ]));
}
