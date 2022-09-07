// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Sat Jul 23 22:10:13 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit M_BANK;
void setup() {
set_area("jiangxia");
set_light(50);
set_brief("%^YELLOW%^"+"ÔÓ»õÆÌ"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/jiangxia/jx_suishixiaolu.c",
 ]));
set_objects( (["/sgdomain/obj/other/sign.c" : 1]) );
}
