// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sun May 29 12:13:02 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("xuchang");
set_light(50);
set_brief("%^YELLOW%^"+"����"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/xuchang/xc_houhuayuan.c",

"east":"/a/xuchang/xc_nanjie2.c",
 ]));
}
