// this room is created by buzzer.c
// driver is �������
// created date is Sun Jul 17 23:19:44 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("gongan");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/gongan/ga_maowu.c",
 ]));
set_objects( (["/sgdomain/obj/other/bed.c" : 1]) );
}
