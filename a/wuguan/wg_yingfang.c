// this room is created by buzzer.c
// driver is �������
// created date is Fri May  6 22:00:25 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("wuguan");
set_light(50);
set_brief("%^YELLOW%^"+"Ӫ��"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/wuguan/wg_yingzhai.c",
 ]));
set_objects( (["/sgdomain/obj/other/bed.c" : 1]) );
}
