// this room is created by buzzer.c
// driver is �������
// created date is Mon May  9 10:03:32 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"Ϸ��"+"%^RESET%^");
set_long("
    �����ǽ����Ϸ��,̨�������š������𼧡����ܶ����
��̨�½к��Ȳ�,�����ζ�Ŀ���Ϸ��һ��С���ڶ���С��,
һ��С����ͷ���ԵĶ��ſ��˵�Ǯ���������Ǻ�̨��\n\n");
set_exits( ([
"south":"/a/jiangling/jl_houtai.c",

"north":"/a/jiangling/jl_yaopu.c",

"east":"/a/jiangling/jl_dongchengmen.c",
 ]));
}
