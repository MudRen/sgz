// this room is created by buzzer.c
// driver is �������
// created date is Tue May  3 21:13:07 2011
#include <mudlib.h>
#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("changan");
set_light(50);
set_brief("%^YELLOW%^"+"���ֽ�"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/changan/ca_dongdajie2.c",

"east":"/a/changan/ca_lushihang.c",

"north":"/a/changan/ca_changlejie.c",
 ]));
}
