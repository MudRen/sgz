// this room is created by buzzer.c
// driver is �������
// created date is Mon May  9 09:25:40 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"��լ"+"%^RESET%^");
set_long("
    �����ǽ���Ĺ�լ,æµ��һ��Ĺ�Ա���ڼ�����Ϣ��\n\n");
set_exits( ([
"east":"/a/jiangling/jl_ruipinglu.c",
 ]));
}
