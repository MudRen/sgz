// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Thu Jun  2 21:03:34 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
inherit STORE;
void setup() {
set_area("poyang");
set_light(50);
set_brief("%^YELLOW%^"+"�ƹ�"+"%^RESET%^");
set_long("
    ������۶���ƹ�,�ſ�д��һ�����ơ�̫��¥��,���ܵ�װ��
��ڻԻͣ������ۻ�����,���������������֡�\n\n");
set_exits( ([
"west":"/a/poyang/py_lianbingchang.c",
 ]));
add_object("/sgdomain/obj/foodanddrink/mantou.c");
add_object("/sgdomain/obj/foodanddrink/ypjd.c");

set_objects( (["/sgdomain/obj/other/well.c" : 1]) );
}
