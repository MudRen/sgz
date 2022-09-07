// this room is created by buzzer.c
// driver is °ÍÉ½Ò¹Óê
// created date is Thu May 26 20:47:56 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit M_BANK;
void setup() {
set_area("taiyuan");
set_light(50);
set_brief("%^YELLOW%^"+"Ç®×¯"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/taiyuan/ty_nandajie1.c",
 ]));
set_objects( (["/sgdomain/obj/other/sign.c" : 1]) );
}
