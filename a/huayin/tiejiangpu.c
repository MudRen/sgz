// this room is created by buzzer.c
// driver is �������
// created date is Thu Apr 28 23:29:06 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("");
set_exits( ([
"south":"/a/huayin/xiaolu.c",
 ]));
}
