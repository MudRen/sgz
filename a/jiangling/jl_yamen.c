// this room is created by buzzer.c
// driver is �������
// created date is Thu May 26 21:57:10 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"����"+"%^RESET%^");
set_long("
    �����ǽ�������,һЩ��������ſ�,���Ŵ����������ӡ�\n\n");
set_exits( ([
"south":"/a/jiangling/jl_datang.c",

"north":"/a/jiangling/jl_xiaolu.c",
 ]));
}
