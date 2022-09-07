// this room is created by buzzer.c
// driver is »¨¶ù¶ä¶ä
// created date is Wed Jun 15 20:14:20 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit M_BANK;
void setup() {
set_area("hongnong");
set_light(50);
set_brief("%^YELLOW%^"+"´óÌÃ"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/hongnong/hn_yishiting.c",

"north":"/a/hongnong/hn_dongdajie.c",
 ]));
set_objects( (["/sgdomain/obj/other/sign.c" : 1]) );
}
