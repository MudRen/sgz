// this room is created by buzzer.c
// driver is �������
// created date is Sun Jul  3 10:27:28 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("yiling");
set_light(50);
set_brief("%^YELLOW%^"+"�ٳ�"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/yiling/yl_zhalan.c",

"east":"/a/yiling/yl_junying.c",

"south":"/a/yiling/yl_nitulu.c",

"west":"/a/yiling/yl_dalu.c",
 ]));
}
