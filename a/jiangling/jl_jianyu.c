// this room is created by buzzer.c
// driver is �������
// created date is Thu May 26 21:57:52 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"����"+"%^RESET%^");
set_long("
    �����Ǽ���,��������������������ڵ�����,
�Ա�һ��ľͰ�������˵��׷���\n\n");
set_exits( ([
"west":"/a/jiangling/jl_datang.c",
 ]));
}
