// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sun May 29 12:10:32 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("xuchang");
set_light(50);
set_brief("%^YELLOW%^"+"�Ͻ�"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/xuchang/xc_nanjie2.c",

"west":"/a/xuchang/xc_guanzhai.c",

"north":"/a/xuchang/xc_xijieer.c",
 ]));
}
