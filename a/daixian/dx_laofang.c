// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Mon May 30 20:17:59 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("daixian");
set_light(50);
set_brief("%^YELLOW%^"+"�η�"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/daixian/dx_liangcang.c",
 ]));
}
