// this room is created by buzzer.c
// driver is �������
// created date is Fri May  6 15:09:23 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("wuzhangyuan");
set_light(50);
set_brief("%^YELLOW%^"+"Ӫ��"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/wuzhangyuan/wzy_dalu2.c",
 ]));
set_objects( (["/sgdomain/obj/other/bed.c" : 1]) );
}
