// this room is created by buzzer.c
// driver is �������
// created date is Wed Jun 15 16:36:54 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("shangdang");
set_light(50);
set_brief("%^YELLOW%^"+"�����"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/shangdang/sd_jvhuisuo.c",
"south":"/a/shangdang/tmp.c",
"west":"/a/shangdang/sd_chengzhongxin.c",
 ]));
}
