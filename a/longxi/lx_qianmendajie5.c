// this room is created by buzzer.c
// driver is �������
// created date is Sat May  7 13:56:31 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"ǰ�Ŵ��"+"%^RESET%^");
set_long("");
set_exits( ([
"west":"/a/longxi/lx_dianjiangtai.c",

"south":"/a/longxi/lx_jiaolichang.c",

"east":"/a/longxi/lx_qiandajie4.c",
 ]));
}
