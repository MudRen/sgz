// this room is created by buzzer.c
// driver is �������
// created date is Sun Jul  3 10:29:16 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("yiling");
set_light(50);
set_brief("%^YELLOW%^"+"˧��"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/yiling/yl_junying.c",
 ]));
}
