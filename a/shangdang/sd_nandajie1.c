// this room is created by buzzer.c
// driver is �������
// created date is Wed Jun 15 16:10:28 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("shangdang");
set_light(50);
set_brief("%^YELLOW%^"+"�ϴ��"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/shangdang/sd_chengzhongxin.c",

"west":"/a/shangdang/sd_yamen.c",
"east":"/a/shangdang/sd_xiaochang.c",
"south":"/a/shangdang/sd_nandajie2.c",
 ]));
}
