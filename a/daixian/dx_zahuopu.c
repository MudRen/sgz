// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Mon May 30 20:15:33 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("daixian");
set_light(50);
set_brief("%^YELLOW%^"+"�ӻ���"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/daixian/dx_nanjie1.c",
 ]));
}
