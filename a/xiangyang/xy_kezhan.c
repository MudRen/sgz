// this room is created by buzzer.c
// driver is �������
// created date is Thu Jul 28 19:12:57 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("xiangyang");
set_light(50);
set_brief("%^YELLOW%^"+"��ջ"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/xiangyang/xy_nandajie1.c",
 ]));
set_objects( (["/sgdomain/obj/other/bed.c" : 1]) );
}
