// this room is created by buzzer.c
// driver is �������
// created date is Thu May 26 20:05:24 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("taiyuan");
set_light(50);
set_brief("%^YELLOW%^"+"�ĳ�"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/taiyuan/ty_xidajie1.c",
 ]));
}
