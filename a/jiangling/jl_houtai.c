// this room is created by buzzer.c
// driver is �������
// created date is Mon May  9 10:08:12 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"��̨"+"%^RESET%^");
set_long("
    ������Ϸ��ĺ�̨,�м���Ϸ�����ڻ�װ,׼����̨�ݳ�,
ǽ�Ϲ�����ָ�����Ϸ�����ӱ��߿�����̨��\n\n");
set_exits( ([
"north":"/a/jiangling/jl_xipeng.c",
 ]));
}
