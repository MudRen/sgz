// this room is created by buzzer.c
// driver is �������
// created date is Thu Apr 28 23:30:08 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
inherit STORE;
void setup() {
set_area("huayin");
set_light(50);
set_brief("%^YELLOW%^"+"С��"+"%^RESET%^");
set_long("
    ���߽�����Ψһ��һ��С�꣬��Ϊ�������٣����������Ҳ��̫
�á���С���������������һ�Դ��˯����listָ����Կ������е�
��Ʒ��buyָ���\n\n");
set_exits( ([
"north":"/a/huayin/xiaolu.c",
 ]));
add_object("/sgdomain/obj/foodanddrink/mantou.c");
add_object("/sgdomain/obj/foodanddrink/ypjd.c");
set_objects( (["/sgdomain/obj/other/well.c" : 1]) );
}
