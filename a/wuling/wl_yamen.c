// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sat May 28 19:25:26 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"����"+"%^RESET%^");
set_long("
    ��������������,���ұ߷���һ�����,���������ԩ���ʱ��
���Ի�����ԩ��\n\n");
set_exits( ([
"north":"/a/wuling/wl_laoyu.c",

"south":"/a/wuling/wl_dadao1.c",
 ]));
}
