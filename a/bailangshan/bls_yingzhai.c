// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sun Jun 12 20:18:00 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("bailangshan");
set_light(50);
set_brief("%^YELLOW%^"+"Ӫկ"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/bailangshan/bls_xiaolu.c",

"north":"/a/bailangshan/bls_junying.c",

"south":"/a/bailangshan/bls_shuaizhang.c",

"east":"/a/bailangshan/bls_xiaochang.c",
 ]));
}
