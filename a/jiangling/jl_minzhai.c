// this room is created by buzzer.c
// driver is �������
// created date is Mon May  9 09:38:34 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"��լ"+"%^RESET%^");
set_long("
    ��������լ,�����������һ��,����˵�����Ļ���
��������ƽ·���������ˣ���֪������ʲô������\n\n");
set_exits( ([
"west":"/a/jiangling/jl_ruipinglu5.c",
 ]));
}
