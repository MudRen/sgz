// this room is created by buzzer.c
// driver is �������
// created date is Mon May  9 09:29:42 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"��ջ"+"%^RESET%^");
set_long("
    �����ǽ������Ŀ�ջ,��������ս��,������䵭��\n\n");
set_exits( ([
"south":"/a/jiangling/jl_xiaoxiang.c",
 ]));
set_objects( (["/sgdomain/obj/other/bed.c" : 1]) );

}
