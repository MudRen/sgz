// this room is created by buzzer.c
// driver is �������
// created date is Sat May  7 14:44:59 2011
#include <mudlib.h>
#include <ansi.h>
inherit INDOOR_ROOM;
inherit STORE;

void setup() {
set_area("longxi");
set_light(50);
set_brief("%^YELLOW%^"+"��������"+"%^RESET%^");
set_long("
    ���������ڿ�������һ���պ��˵Ľ��أ������һ�����ŷ��䣬
�ұߵ�ǽ�Ϲ��Ÿ�ʽ�����ĵ��������в��������ϳ˵Ļ�Ʒ����list
ָ������ļ۸�buyָ���\n\n");
set_exits( ([
"south":"/a/longxi/lx_xiaoxiang1.c",
 ]));
add_object("/sgdomain/obj/weapon/blade/dandao.c");
add_object("/sgdomain/obj/weapon/blade/gangdao.c");
add_object("/sgdomain/obj/weapon/ji/changji.c");
add_object("/sgdomain/obj/weapon/sword/changjian.c");
add_object("/sgdomain/obj/weapon/sword/gangjian.c");
}
