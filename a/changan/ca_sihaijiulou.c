// this room is created by buzzer.c
// driver is �������
// created date is Tue May  3 21:31:57 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
inherit STORE;

void setup() {
set_area("changan");
set_light(50);
set_brief("%^YELLOW%^"+"�ĺ���¥"+"%^RESET%^");
set_long("
    �����ǳ������ľ�¥-�ĺ���¥��һ���ߴ�Ľ��������
�Ž��ֵ����ƣ��ſڻ��������������¥����������ƣ�����
�ü��ˡ���Ҳ������������һЩ�Եġ�list�г������ʳ�
buyָ���\n\n");
set_exits( ([
"west":"/a/changan/ca_nandajie.c",
 ]));
add_object("/sgdomain/obj/foodanddrink/mantou.c");
add_object("/sgdomain/obj/foodanddrink/ypjd.c");

set_objects( (["/sgdomain/obj/other/well.c" : 1]) );

}
