// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sun May 29 12:01:22 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("xuchang");
set_light(50);
set_brief("%^YELLOW%^"+" У��"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/xuchang/xc_bingying.c",

"north":"/a/xuchang/xc_zhushuaiyingzhang.c",

"west":"/a/xuchang/xc_chengbeidajie.c",
 ]));
}
