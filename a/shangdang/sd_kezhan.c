// this room is created by buzzer.c
// driver is �������
// created date is Wed Jun 15 16:03:20 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("shangdang");
set_light(50);
set_brief("%^YELLOW%^"+"��ջ"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/shangdang/sd_nandajie2.c",
 ]));
set_objects( (["/sgdomain/obj/other/bed.c" : 1]) );
}
