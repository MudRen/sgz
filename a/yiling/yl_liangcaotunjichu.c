// this room is created by buzzer.c
// driver is �������
// created date is Sun Jul  3 10:30:28 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("yiling");
set_light(50);
set_brief("%^YELLOW%^"+"�����ͻ���"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/yiling/yl_junying.c",
 ]));
set_objects( (["/sgdomain/obj/other/bed.c" : 1]) );
}
