// this room is created by buzzer.c
// driver is �������
// created date is Mon Jul 25 23:38:23 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("chibi");
set_light(50);
set_brief("%^YELLOW%^"+"Ӫ��"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/chibi/cb_shuaizhang.c",
 ]));
set_objects( (["/sgdomain/obj/other/bed.c" : 1]) );
}
