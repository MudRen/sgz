// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Mon May 30 20:57:01 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("chaisang");
set_light(50);
set_brief("%^YELLOW%^"+"���µ�"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/chaisang/cs_zahuodian.c",
 ]));
}
