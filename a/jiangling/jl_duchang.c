// this room is created by buzzer.c
// driver is �������
// created date is Mon May  9 09:40:36 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"�ĳ�"+"%^RESET%^");
set_long("
    �����Ƕĳ�,һ����Χ�������ڶ��ƾ�,�����뺷��
����������Ѳ�ӡ�\n\n");
set_exits( ([
"west":"/a/jiangling/jl_ruipinglu3.c",
 ]));
}
