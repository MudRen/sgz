// this room is created by buzzer.c
// driver is �������
// created date is Sun May  8 21:43:31 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
inherit STORE;
void setup() {
set_area("tianshui");
set_light(50);
set_brief("%^YELLOW%^"+"�����"+"%^RESET%^");
set_long("
    ������������ζ�Ļ�������͹ݣ��ſ�վ��һλ����ӵ�
�ϰ壬��������ɫ�����棬���⡣��С����������к��㣬��
λ�͹٣�Ҫ��ʲô��list�����г���Ʒ�۸�buy����\n\n");
set_exits( ([
"east":"/a/tianshui/ts_nandajie1.c",
 ]));
add_object("/sgdomain/obj/foodanddrink/mantou.c");
add_object("/sgdomain/obj/foodanddrink/ypjd.c");

set_objects( (["/sgdomain/obj/other/well.c" : 1]) );

}
