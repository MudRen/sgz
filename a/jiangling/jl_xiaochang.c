// this room is created by buzzer.c
// driver is �������
// created date is Mon May  9 09:19:20 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"У��"+"%^RESET%^");
set_long("
    �����ǽ���У��,�ڴ�����Կ���һ�Ӷӹٱ����ڲ�����
�����Ǵ�ʤ�̵ĸ�����ֻҪ���б�������Ϳ��Ե��������
������ɱ�С�\n\n");
set_exits( ([
"west":"/a/jiangling/jl_ruipinglu2.c",
 ]));
}
