// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sun May 29 12:02:36 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("xuchang");
set_light(50);
set_brief("%^YELLOW%^"+"��˧Ӫ��"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/xuchang/xc_xiaochang.c",
 ]));
}
