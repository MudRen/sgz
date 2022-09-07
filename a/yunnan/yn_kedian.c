// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Fri Jun  3 21:58:25 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("yunnan");
set_light(50);
set_brief("%^YELLOW%^"+"¿Íµê"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/yunnan/yn_shibanlu2.c",
 ]));
set_objects( (["wiz/fire/obj/bed.c" : 1 ]) );
}
