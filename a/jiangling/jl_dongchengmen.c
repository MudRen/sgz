// this room is created by buzzer.c
// driver is �������
// created date is Mon May  9 10:08:48 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit OUTDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"������"+"%^RESET%^");
set_long("
    �����ǽ���Ķ�����,�ߴ�ĳ�ǽ��д��
ŵ��������֡�"+"%^MAGENTA%^"+"����"+"%^RESET%^"+"����\n\n");
set_exits( ([
"west":"/a/jiangling/jl_xipeng.c",
 ]));
}
