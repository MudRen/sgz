// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Thu May 26 20:54:24 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("taiyuan");
set_light(50);
set_brief("%^YELLOW%^"+"�����"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/taiyuan/ty_yulinjunying2.c",

"west":"/a/taiyuan/ty_yulinjunying1.c",

"south":"/a/taiyuan/ty_beidajie2.c",
 ]));
}
