// this room is created by buzzer.c
// driver is �������
// created date is Fri Apr 29 10:58:39 2011
#include <mudlib.h>
#include <ansi.h>
//inherit INDOOR_ROOM;
inherit M_BANK;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"Ǯׯ"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/huayin/daguchang.c",
 ]));
set_objects( (["/sgdomain/obj/other/sign.c" : 1]) );
}
