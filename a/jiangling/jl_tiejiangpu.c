// this room is created by buzzer.c
// driver is �������
// created date is Mon May  9 09:23:54 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
inherit STORE;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("
    �������ڿ�������һ���պ��˵ĸֽ��������һ�����ŷ��䣬
�ұߵ�ǽ�Ϲ��Ÿ�ʽ�����ĵ��������в��������ϳ˵Ļ�Ʒ����list
ָ������ļ۸�buyָ���\n\n");
set_exits( ([
"west":"/a/jiangling/jl_ruipinglu1.c",
 ]));
}
