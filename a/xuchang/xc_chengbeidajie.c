// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sun May 29 11:59:20 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("xuchang");
set_light(50);
set_brief("%^YELLOW%^"+"�Ǳ����"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/xuchang/xc_xiaochang.c",

"north":"/a/xuchang/xc_beichengmen.c",

"south":"/a/xuchang/xc_dongjieyi.c",
 ]));
}
