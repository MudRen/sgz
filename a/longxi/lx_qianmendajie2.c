// this room is created by buzzer.c
// driver is �������
// created date is Sat May  7 13:48:43 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"ǰ�Ŵ��"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/longxi/lx_qianmendajie3.c",

"north":"/a/longxi/lx_yuzhenlou.c",

"east":"/a/longxi/lx_qianmendajie1.c",
 ]));
}
