// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sun May 29 11:56:42 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("xuchang");
set_light(50);
set_brief("%^YELLOW%^"+"�鱦��"+"%^RESET%^");
set_long("");
set_exits( ([
"east":"/a/xuchang/xc_chunqiulou.c",
 ]));
}
