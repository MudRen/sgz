// this room is created by buzzer.c
// driver is �������
// created date is Thu Jul 28 19:14:43 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit M_BANK;
void setup() {
set_area("xiangyang");
set_light(50);
set_brief("%^YELLOW%^"+"Ǯׯ"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/xiangyang/xy_tianchijie1.c",
 ]));
set_objects( (["/sgdomain/obj/other/sign.c" : 1]) );
}
