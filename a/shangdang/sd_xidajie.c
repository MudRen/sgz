// this room is created by buzzer.c
// driver is �������
// created date is Wed Jun 15 16:45:08 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("shangdang");
set_light(50);
set_brief("%^YELLOW%^"+"�����"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/shangdang/sd_bingqipu.c",

"north":"/a/shangdang/sd_junying.c",
"east":"/a/shangdang/sd_chengzhongxin.c",
 ]));
}
