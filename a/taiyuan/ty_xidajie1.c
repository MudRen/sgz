// this room is created by buzzer.c
// driver is �������
// created date is Thu May 26 20:03:38 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("taiyuan");
set_light(50);
set_brief("%^YELLOW%^"+"�����"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/taiyuan/ty_xidajie2.c",

"east":"/a/taiyuan/ty_chengzhongxin.c",

"north":"/a/taiyuan/ty_duchang.c",

"south":"/a/taiyuan/ty_buzhuang.c",
 ]));
}
