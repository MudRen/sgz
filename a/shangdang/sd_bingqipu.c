// this room is created by buzzer.c
// driver is �������
// created date is Wed Jun 15 16:45:38 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit M_BANK;

void setup() {
set_area("shangdang");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/shangdang/sd_xidajie.c",
 ]));
set_objects( (["/sgdomain/obj/other/sign.c" : 1]) );
}
