// this room is created by buzzer.c
// driver is ��ɽҹ��
// created date is Sat May 28 19:31:14 2011
//#include <mudlib.h>
//#include <ansi.h>
inherit INDOOR_ROOM;
inherit STORE;
void setup() {
set_area("wuling");
set_light(50);
set_brief("%^YELLOW%^"+"�ƹ�"+"%^RESET%^");
set_long("
    ��¥�����νྻ�����п������κ��ݣ�ʮ֮�˾��Ǹ��̴�
�֡�����ش���ͨҪ�أ�����Է����˻��治�١�list�г���
Ʒ��buy����\n\n");
set_exits( ([
"west":"/a/wuling/wl_xiaoxiang.c",
 ]));
add_object("/sgdomain/obj/foodanddrink/mantou.c");
add_object("/sgdomain/obj/foodanddrink/ypjd.c");

set_objects( (["/sgdomain/obj/other/well.c" : 1]) );
}
