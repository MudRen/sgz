// this room is created by buzzer.c
// driver is �������
// created date is Sun Jul  3 10:32:26 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("yiling");
set_light(50);
set_brief("%^YELLOW%^"+"ɽ��"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/yiling/yl_caodi.c",
 ]));
}
