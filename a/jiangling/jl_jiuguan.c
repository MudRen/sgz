// this room is created by buzzer.c
// driver is �������
// created date is Mon May  9 11:04:26 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
inherit STORE;

void setup() {
set_area("jiangling");
set_light(50);
set_brief("%^YELLOW%^"+"�ƹ�"+"%^RESET%^");
set_long("
    �����ǽ���ƹ�,�ſ�д��һ�����ơ�̫��¥��,���ܵ�װ��
��ڻԻͣ������ۻ�����,���������������֡�\n\n");
set_exits( ([
"south":"/a/jiangling/jl_shibanlu.c",
 ]));
//set_objects((["/sgdomain/obj/other/board.c" : ({ 1,"����ľƹݣ��ſڹ���һ�ײ����ơ������ơ�list�г���Ʒ��buy����\n\n"}) ]) );

add_object("/sgdomain/obj/foodanddrink/mantou.c");
add_object("/sgdomain/obj/foodanddrink/ypjd.c");

set_objects( (["/sgdomain/obj/other/well.c" : 1]) );

}
