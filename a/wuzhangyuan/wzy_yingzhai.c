// this room is created by buzzer.c
// driver is �������
// created date is Fri May  6 15:10:43 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuzhangyuan");
set_light(50);
set_brief("%^YELLOW%^"+"Ӫկ"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/wuzhangyuan/wzy_luzhai.c",

"south":"/a/wuzhangyuan/wzy_xiaoshulin.c",

"north":"/a/wuzhangyuan/wzy_zhongjunzhang.c",

"east":"/a/wuzhangyuan/wzy_dalu2.c",
 ]));
}
