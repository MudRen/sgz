// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Wed Jun 15 22:18:28 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("yanmenguan");
set_light(50);
set_brief("%^YELLOW%^"+"Сľ��"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/yanmenguan/ymg_banshanyao.c",
 ]));
set_objects( (["/sgdomain/obj/other/bed.c" : 1]) );
}
