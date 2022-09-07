// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Fri Jun  3 22:07:39 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit M_BANK;
void setup() {
set_area("yunnan");
set_light(50);
set_brief("%^YELLOW%^"+"½ðÆÌ"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/yunnan/yn_tulu1.c",
 ]));
set_objects( ([POBJ+"other/sign" : 1 ]) );
}
