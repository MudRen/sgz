// this room is created by buzzer.c
// driver is �������
// created date is Fri May  6 21:59:01 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("wuguan");
set_light(50);
set_brief("%^YELLOW%^"+"Ӫկ"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/wuguan/wg_dadao.c",

"south":"/a/wuguan/wg_yingfang.c",

"north":"/a/wuguan/wg_zhongjunzhang.c",

"west":"/a/wuguan/wg_huangtulu.c",
 ]));
}
