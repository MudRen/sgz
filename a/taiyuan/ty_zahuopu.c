// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Thu May 26 20:48:20 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("taiyuan");
set_light(50);
set_brief("%^YELLOW%^"+"�ӻ���"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/taiyuan/ty_nandajie1.c",
 ]));
}
