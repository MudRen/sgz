// this room is created by buzzer.c
// driver is �������
// created date is Tue May  3 20:41:11 2011
#include <mudlib.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("changan");
set_light(50);
set_brief("%^YELLOW%^"+"���ֽ�"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/changan/ca_changlejie1.c",

"east":"/a/changan/ca_jianyu.c",

"west":"/a/changan/ca_yamen.c",

"south":"/a/changan/ca_changlejie1.c",

"north":"/a/changan/ca_qingshilu.c",
 ]));
}
