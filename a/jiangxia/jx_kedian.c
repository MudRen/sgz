// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Sat Jul 23 22:05:01 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("jiangxia");
set_light(50);
set_brief("%^YELLOW%^"+"¿Íµê"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/jiangxia/jx_fanguan.c",
 ]));
set_objects( (["/sgdomain/obj/other/bed.c" : 1]) );
}
