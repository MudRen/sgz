// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sun May 29 12:11:58 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("xuchang");
set_light(50);
set_brief("%^YELLOW%^"+"�Ͻ�"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/xuchang/xc_wangfu.c",

"north":"/a/xuchang/xc_nanjie1.c",
 ]));
}
