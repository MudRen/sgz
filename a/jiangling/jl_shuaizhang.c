// this room is created by buzzer.c
// driver is �������
// created date is Mon May  9 09:21:42 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"˧��"+"%^RESET%^");
set_long("
    �����ǽ���˧��,���ڷǳ���,������һ�Ŵ���
����ľ��,���԰������ž��µĵ��ӣ������ǽ�Ϲ��ż�
��������������ǽ���̫��ƽʱ���������;���ĵط���\n\n");
set_exits( ([
"east":"/a/jiangling/jl_bingying.c",
 ]));
}
