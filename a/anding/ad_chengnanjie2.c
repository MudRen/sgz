// this room is created by buzzer.c
// driver is �������
// created date is Fri May 27 19:56:45 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("anding");
set_light(50);
set_brief("%^YELLOW%^"+"���Ͻ�"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/anding/ad_nanchengmen.c",

"north":"/a/anding/ad_chengnanjie1.c",

"east":"/a/anding/ad_kezhan.c",
]));
}
