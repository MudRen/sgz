// this room is created by buzzer.c
// driver is �������
// created date is Tue Jul 19 09:45:36 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("changbanpo");
set_light(50);
set_brief("%^YELLOW%^"+"�ݾ�"+"%^RESET%^");
set_long("");
set_exits( ([
"north":"/a/changbanpo/cbp_duanbicanyuan.c",

"east":"/a/changbanpo/cbp_shadi.c",
 ]));
}
