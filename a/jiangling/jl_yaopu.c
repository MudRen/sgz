// this room is created by buzzer.c
// driver is �������
// created date is Mon May  9 10:00:22 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"ҩ��"+"%^RESET%^");
set_long("
    �����ǽ���Ψһ��ҩ�̣��ſ�д��һ�����ơ�һƷ�á���\n\n");
set_exits( ([
"south":"/a/jiangling/jl_xipeng.c",

"north":"/a/jiangling/jl_shibanlu.c",
 ]));
}
