// this room is created by buzzer.c
// driver is �������
// created date is Thu May 26 21:57:30 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"����"+"%^RESET%^");
set_long("
    �����ǽ������,ר�����˵ĵط�,����վ������
�����ۡ�\n\n");
set_exits( ([
"east":"/a/jiangling/jl_jianyu.c",

"north":"/a/jiangling/jl_yamen.c",
 ]));
}
